//
// Created by zet on 07.05.2021.
//
#include "agencies_list.h"

AgenciesListElement::AgenciesListElement(const Agency &data_value) {
    next = nullptr;
    prev = nullptr;
    this->data = data_value;
}

void AgenciesListElement::SetData(const Agency &data_value) {
    data = data_value;
}

Agency AgenciesListElement::GetData() const {
    return data;
}

void AgenciesListElement::SetNext(AgenciesListElement *next_value) {
    next = next_value;
}

AgenciesListElement *AgenciesListElement::GetNext() const {
    return next;
}


void AgenciesListElement::SetPrev(AgenciesListElement *prev_value) {
    prev = prev_value;
}

AgenciesListElement *AgenciesListElement::GetPrev() const {
    return prev;
}



AgenciesList::AgenciesList() {
    head = nullptr;
    tail = nullptr;
}

AgenciesList::AgenciesList(AgenciesList &copy) {
    AgenciesListElement *copy_current = copy.head;
    while (copy_current != nullptr) {
        this->AddElementBack(copy_current->GetData());
        copy_current = copy_current->GetNext();
    }
}

AgenciesList::~AgenciesList() {
    Clear();
}

AgenciesListElement * AgenciesList::GetHead() {
    return head;
}
AgenciesListElement * AgenciesList::GetTail() {
    return tail;
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

            if (new_element->GetNext() != nullptr){
                new_element->GetNext()->SetPrev(new_element);
            }

            if (prev_for_inserted == tail)
                tail = new_element;
        }
    }

    length++;
}

void AgenciesList::AddElementBack(const Agency &element_data) {
//    AddElementByIndex(element_data, length - 1);
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

size_t AgenciesList::GetLength() const {
    return length;
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

        delete deleted;

        length--;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
    } else {
        cout << "No such element" << endl;
    }

}

AgenciesListElement& AgenciesList::GetElementByIndex(size_t index) const {

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

        return *current;
    } else {
        cout << "Index is not available" << endl;
    }
    exit(1);
}

//void AgenciesList::SortByComparator(int(*comparator)(Agency left, Agency right)) {
//    for (size_t i = 0; i < length; i++) {
//        for (size_t j = 0; j < length - 1; j++) {
//            if (comparator(GetElementByIndex(j).GetData(), GetElementByIndex(j + 1).GetData()) > 0) {
//                SwapListElements(GetElementByIndex(j).GetPrev()->GetNext(),
//                                 GetElementByIndex(j + 1).GetNext()->GetPrev());
//            }
//        }
//    }
//}
//
//void AgenciesList::SwapListElements(AgenciesListElement *left, AgenciesListElement *right) {
//    AgenciesListElement *left_prev = left->GetPrev();
//    if (left_prev != nullptr) {
//        left_prev->SetNext(right);
//    }
//
//    AgenciesListElement *right_next = right->GetNext();
//    if (right_next != nullptr) {
//        right_next->SetPrev(left);
//    }
//
//    right->SetPrev(left_prev);
//    left->SetNext(right_next);
//
//    right->SetNext(left);
//    left->SetPrev(right);
//}
//
//AgenciesList AgenciesList::GetElementsBy(bool(*check_function)(Agency agency)) const {
//
//    AgenciesList selected_agencies;
//    for (size_t i = 0; i < length; i++) {
//        Agency verifiable_agency = GetElementByIndex(i).GetData();
//        if (check_function(verifiable_agency)) {
//            selected_agencies.AddElementBack(verifiable_agency);
//        }
//    }
//    return selected_agencies;
//}

void AgenciesList::Clear() {
    while (length != 0) DeleteElementByIndex(0);
}

void AgenciesList::ShowAll() const {
    AgenciesListElement *current = head;
    while (current != nullptr) {
        cout << current->GetData().toString() << endl;
        current = current->GetNext();
    }
}

void AgenciesList::ReadFromFile(const string &file_name) {
    ifstream input_file(file_name);
    string file_data;


    if (!input_file) {
        cerr << "File " << file_name << " could not be opened for reading!";
    } else {
        this->Clear();
        while (input_file) {
            string buffer;
            getline(input_file, buffer, '\n');
            file_data.append(buffer);
        }
    }

    StringOfAgenciesToList(file_data);
}

void AgenciesList::StringOfAgenciesToList(const string &agencies_string) {
    string key = "Agency";
    auto key_index = (int32_t) agencies_string.find(key);
    int32_t last_agency_description_symbol = 0;

    while (key_index != -1) {
        last_agency_description_symbol = (int32_t) agencies_string.find('}', (size_t) last_agency_description_symbol);
        last_agency_description_symbol = (int32_t) agencies_string.find('}', (size_t) last_agency_description_symbol + 1);

        AddElementBack(Agency::FromString(
                agencies_string.substr((size_t) key_index, (size_t) last_agency_description_symbol)));

        key_index = (int32_t) agencies_string.find(key, key_index + key.length());
    }
}

void AgenciesList::WriteToFile(const string &file_name) const {
    ofstream output_file(file_name);

    if (!output_file) {
        cerr << "File " << file_name << " could not be opened for reading!";
    } else {
        for (size_t i = 0; i < length; i++) {
            output_file << GetElementByIndex(i).GetData().toString() << endl;
        }
    }
}
