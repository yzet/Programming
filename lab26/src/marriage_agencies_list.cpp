//
// Created by zet on 25.05.2021.
//

#include "marriage_agencies_list.h"

//
// Created by zet on 25.05.2021.
//

MarriageAgenciesListElement *MarriageAgenciesListElement::GetNext() const {
    return next;
}

MarriageAgenciesListElement::MarriageAgenciesListElement(const MarriageAgency &data_value) {
    next = nullptr;
    prev = nullptr;
    data = data_value;
}

void MarriageAgenciesListElement::SetNext(MarriageAgenciesListElement *next_value) {
    next = next_value;
}

MarriageAgenciesListElement *MarriageAgenciesListElement::GetPrev() const {
    return prev;
}

void MarriageAgenciesListElement::SetPrev(MarriageAgenciesListElement *prev_value) {
    prev = prev_value;
}

MarriageAgency MarriageAgenciesListElement::GetData() const {
    return data;
}

void MarriageAgenciesListElement::SetData(const MarriageAgency &data_value) {
    data = data_value;
}

void MarriageAgenciesList::SwapListElements(MarriageAgenciesListElement *left, MarriageAgenciesListElement *right) {
    MarriageAgenciesListElement *left_prev = left->GetPrev();
    if (left_prev != nullptr) {
        left_prev->SetNext(right);
    }

    MarriageAgenciesListElement *right_next = right->GetNext();
    if (right_next != nullptr) {
        right_next->SetPrev(left);
    }

    right->SetPrev(left_prev);
    left->SetNext(right_next);

    right->SetNext(left);
    left->SetPrev(right);

    if (left->GetNext() == nullptr) tail = left;
}

void MarriageAgenciesList::StringOfAgenciesToList(const string &agencies_string) {
    string key = "Agency";
    auto key_index = (int32_t) agencies_string.find(key);
    int32_t last_agency_description_symbol = 0;

    while (key_index != -1) {
        last_agency_description_symbol = (int32_t) agencies_string.find('}', (size_t) last_agency_description_symbol);
        last_agency_description_symbol = (int32_t) agencies_string.find('}',
                                                                        (size_t) last_agency_description_symbol + 1);

        AddElementBack(MarriageAgency::fromString(
                agencies_string.substr((size_t) key_index, (size_t) last_agency_description_symbol)));

        key_index = (int32_t) agencies_string.find(key, key_index + key.length());
    }
}

void MarriageAgenciesList::AddElementBack(const MarriageAgency &element_data) {
    auto new_element = new MarriageAgenciesListElement(element_data);

    if (tail != nullptr) {
        new_element->SetPrev(tail);
        tail->SetNext(new_element);
    } else {
        head = new_element;
    }

    tail = new_element;

    length++;
}

MarriageAgenciesList::MarriageAgenciesList() {
    head = nullptr;
    tail = nullptr;
}

MarriageAgenciesList::MarriageAgenciesList(MarriageAgenciesList &copy) {
    MarriageAgenciesListElement *copy_current = copy.head;
    while (copy_current != nullptr) {
        this->AddElementBack(copy_current->GetData());
        copy_current = copy_current->GetNext();
    }
}

MarriageAgenciesList::~MarriageAgenciesList() {
    Clear();
}

MarriageAgenciesListElement *MarriageAgenciesList::GetTail() {
    return tail;
}

MarriageAgenciesListElement *MarriageAgenciesList::GetHead() {
    return head;
}

void MarriageAgenciesList::AddElementByIndex(const MarriageAgency &element_data, size_t index) {
    auto new_element = new MarriageAgenciesListElement(element_data);

    MarriageAgenciesListElement *prev_for_inserted = head;

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

size_t MarriageAgenciesList::GetLength() const {
    return length;
}

void MarriageAgenciesList::DeleteElementByIndex(size_t index) {

    MarriageAgenciesListElement *deleted = head;
    if (head != nullptr && index < length) {

        for (size_t i = 0; i < index; i++) {
            deleted = deleted->GetNext();
        }

        MarriageAgenciesListElement *prev = deleted->GetPrev();
        MarriageAgenciesListElement *next = deleted->GetNext();

        if (prev) {
            prev->SetNext(next);
        }

        if (next) {
            next->SetPrev(prev);
        }

        if (index == 0) head = next;
        if (index == length - 1) tail = prev;

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

MarriageAgenciesListElement &MarriageAgenciesList::GetElementByIndex(size_t index) const {
    MarriageAgenciesListElement *current;
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

void MarriageAgenciesList::WriteToFile(const string &file_name) const {
    ofstream output_file(file_name);

    if (!output_file) {
        cerr << "File " << file_name << " could not be opened for reading!";
    } else {
        for (size_t i = 0; i < length; i++) {
            output_file << GetElementByIndex(i).GetData().toString() << endl;
        }
    }
}

void MarriageAgenciesList::Clear() {
    while (length != 0) DeleteElementByIndex(0);
}

void MarriageAgenciesList::ReadFromFile(const string &file_name) {
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

void MarriageAgenciesList::ShowAll() const {
    MarriageAgenciesListElement *current = head;
    while (current != nullptr) {
        cout << current->GetData().toString() << endl;
        current = current->GetNext();
    }
}

MarriageAgenciesListElement &MarriageAgenciesList::operator[](int index) const {
    return GetElementByIndex((size_t) index);
}

bool MarriageAgenciesList::operator==(const MarriageAgenciesList &agenciesList) const {
    bool result = true;
    if (length != agenciesList.length) result = false;
    else {
        for (size_t i = 0; i < length; i++) {
            if (!(GetElementByIndex(i).GetData() == agenciesList[(int32_t) i].GetData())) {
                result = false;
                break;
            }
        }
    }
    return result;
}

ostream &operator<<(ostream &output, const MarriageAgenciesList &agencies_list) {
    for (size_t i = 0; i < agencies_list.length; i++) {
        output << agencies_list[(int) i].GetData();
    }

    return output;
}

istream &operator>>(istream &input, MarriageAgenciesList &agencies_list) {
    size_t count_of_agencies;
    cout << "Enter count of agencies: ";
    input >> count_of_agencies;
    MarriageAgency agency_buff;
    for (size_t i = 0; i < count_of_agencies; i++) {
        input >> agency_buff;
        agencies_list.AddElementBack(agency_buff);
    }

    return input;
}

ofstream &operator<<(ofstream &output, const MarriageAgenciesList &agencies_list) {
    for (size_t i = 0; i < agencies_list.length; i++) {
        output << agencies_list[(int) i].GetData();
    }
    return output;
}

ifstream &operator>>(ifstream &input, MarriageAgenciesList &agencies_list) {
    string file_data;
    if (!input) {
        cerr << "File could not be opened for reading!";
    } else {
        agencies_list.Clear();
        while (input) {
            string buffer;
            getline(input, buffer, '\n');
            file_data.append(buffer);
        }
    }

    agencies_list.StringOfAgenciesToList(file_data);

    return input;
}
