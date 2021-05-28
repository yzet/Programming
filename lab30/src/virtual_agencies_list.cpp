//
// Created by zet on 25.05.2021.
//

#include "virtual_agencies_list.h"

AgenciesList::AgenciesList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}


AgenciesListElement::AgenciesListElement(const Agency &data_value) {
    next = nullptr;
    prev = nullptr;
    Agency * dataValue = nullptr;
    if (data_value.GetType() == 'L') {
        dataValue = new LegalAgency( *((LegalAgency *)&data_value));
    } else if (data_value.GetType() == 'M') {
        dataValue = new MarriageAgency( *((MarriageAgency *)&data_value));
    }
    data = dataValue;
}

AgenciesListElement *AgenciesListElement::GetNext() const {
    return next;
}

void AgenciesListElement::SetNext(AgenciesListElement *next_value) {
    next = next_value;
}

AgenciesListElement *AgenciesListElement::GetPrev() const {
    return prev;
}

void AgenciesListElement::SetPrev(AgenciesListElement *prev_value) {
    prev = prev_value;
}

Agency *AgenciesListElement::GetData() const {
    return data;
}

void AgenciesListElement::SetData(const Agency &data_value) {
    Agency * dataValue = nullptr;
    if (data_value.GetType() == 'L') {
        dataValue = new LegalAgency( *((LegalAgency *)&data_value));
    } else if (data_value.GetType() == 'M') {
        dataValue = new MarriageAgency( *((MarriageAgency *)&data_value));
    }
    data = dataValue;
}

AgenciesList::AgenciesList(AgenciesList &copy) {
    head = nullptr;
    tail = nullptr;
    AgenciesListElement *copy_current = copy.head;
    while (copy_current != nullptr) {
        this->AddElementBack(*copy_current->GetData());
        copy_current = copy_current->GetNext();
    }
}

size_t AgenciesList::GetLength() const {
    return length;
}

void AgenciesList::AddElementBack(const Agency &element_data) {

    auto new_element = new AgenciesListElement(element_data);

    if (tail != nullptr) {
        new_element->SetPrev(tail);
        tail->SetNext(new_element);
    } else {
        head = new_element;
    }

    tail = new_element;

    length++;
}

void AgenciesList::AddElementByIndex(const Agency &element_data, size_t index) {
    auto new_element = new AgenciesListElement(element_data);

    AgenciesListElement *prev_for_inserted = head;

    if (prev_for_inserted == nullptr) {
        head = new_element;
        tail = new_element;
    } else {
        for (size_t i = 1; i < index && prev_for_inserted != tail; i++) {
            prev_for_inserted = prev_for_inserted->GetNext();
        }

        if (index == 0) {
            new_element->SetNext(head);
            head = new_element;
        } else {
            new_element->SetNext(prev_for_inserted->GetNext());
            new_element->SetPrev(prev_for_inserted);

            prev_for_inserted->SetNext(new_element);

            if (new_element->GetNext() != nullptr) {
                new_element->GetNext()->SetPrev(new_element);
            }

            if (prev_for_inserted == tail)
                tail = new_element;
        }
    }

    length++;
}

void AgenciesList::ShowAll() const {
    AgenciesListElement *current = head;
    while (current != nullptr) {
        cout << *(current->GetData()) << endl << endl;
//        cout << current->GetData().toString() << endl;
        current = current->GetNext();
    }
}

void AgenciesList::DeleteElementByIndex(size_t index) {
    AgenciesListElement *deleted = head;

    if (head != nullptr && index < length) {

        for (size_t i = 0; i < index; i++) {
            deleted = deleted->GetNext();
        }

        AgenciesListElement *prev = deleted->GetPrev();
        AgenciesListElement *next = deleted->GetNext();

        if (prev) {
            prev->SetNext(next);
        }

        if (next) {
            next->SetPrev(prev);
        }

        if (index == 0) head = next;
        if (index == length - 1) tail = prev;

        delete deleted->GetData();
        delete deleted; // TODO: error in sorting when free memory

        length--;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
    } else {
        cout << "No such element" << endl;
    }
}

Agency *AgenciesList::GetElementByIndex(size_t index) const {
    AgenciesListElement *current;
    int step = 0;
    size_t i = 0;
    if (index <= length / 2) {
        current = head;
        step = 1;
    } else {
        current = tail;
        step = -1;
        i = length - 1;
    }

    if (head != nullptr && index < length) {
        for (; i != index; i += step) {
            if (step < 0) current = current->GetPrev();
            else current = current->GetNext();
        }

        return current->GetData();
    } else {
        cout << "Index is not available" << endl;
    }
    exit(1);
}

AgenciesListElement *AgenciesList::GetHead() {
    return head;
}

AgenciesListElement *AgenciesList::GetTail() {
    return tail;
}

void AgenciesList::Clear() {
    while (length != 0) DeleteElementByIndex(0);
}

Agency *AgenciesList::operator[](int index) const {
    return GetElementByIndex((size_t) index);
}

bool AgenciesList::operator==(const AgenciesList &agenciesList) const {
    bool result = true;
    if (length != agenciesList.length) result = false;
    else {
        for (size_t i = 0; i < length; i++) {
            if (!(*(GetElementByIndex(i))==*(agenciesList.GetElementByIndex(i)))) {
                result = false;
                break;
            }
        }
    }
    return result;
}

ostream &operator<<(ostream &output, const AgenciesList &agencies_list) {
    for (size_t i = 0; i < agencies_list.length; i++) {
        output << *(agencies_list[(int) i]);
    }

    return output;
}

void AgenciesList::SortByComparator(int (*comparator)(const Agency &, const Agency &)) {
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length - 1; j++) {
            if (comparator(*GetElementByIndex(j), *GetElementByIndex(j + 1)) > 0) {

                SwapListElements(GetAgenciesListElementWithIndex(j),
                                 GetAgenciesListElementWithIndex(j + 1));
            }
        }
    }
}

AgenciesListElement * AgenciesList::GetAgenciesListElementWithIndex(size_t index) {
    AgenciesListElement *current;
    int step = 0;
    size_t i = 0;
    if (index <= length / 2) {
        current = head;
        step = 1;
    } else {
        current = tail;
        step = -1;
        i = length - 1;
    }

    if (head != nullptr && index < length) {
        for (; i != index; i += step) {
            if (step < 0) current = current->GetPrev();
            else current = current->GetNext();
        }

        return current;
    } else {
        cout << "Index is not available" << endl;
    }
    exit(1);
}

void AgenciesList::SwapListElements(AgenciesListElement *left, AgenciesListElement *right) {
    AgenciesListElement *left_prev = left->GetPrev();
    if (left_prev != nullptr) {
        left_prev->SetNext(right);
    }

    AgenciesListElement *right_next = right->GetNext();
    if (right_next != nullptr) {
        right_next->SetPrev(left);
    }

    right->SetPrev(left_prev);
    left->SetNext(right_next);

    right->SetNext(left);
    left->SetPrev(right);

    if (left->GetNext() == nullptr) tail = left;
}

AgenciesList AgenciesList::GetElementsBy(bool(*check_function)(Agency * agency)) const {

    AgenciesList selected_agencies;
    for (size_t i = 0; i < length; i++) {
        Agency * verifiable_agency = GetElementByIndex(i);
        if (check_function(verifiable_agency)) {
            selected_agencies.AddElementBack(*verifiable_agency);
        }
    }
    return selected_agencies;
}



