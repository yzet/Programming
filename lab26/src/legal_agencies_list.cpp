//
// Created by zet on 25.05.2021.
//

#include "legal_agencies_list.h"

LegalAgenciesListElement *LegalAgenciesListElement::GetNext() const {
    return next;
}

LegalAgenciesListElement::LegalAgenciesListElement(const LegalAgency &data_value) {
    next = nullptr;
    prev = nullptr;
    data = data_value;
}

void LegalAgenciesListElement::SetNext(LegalAgenciesListElement *next_value) {
    next = next_value;
}

LegalAgenciesListElement *LegalAgenciesListElement::GetPrev() const {
    return prev;
}

void LegalAgenciesListElement::SetPrev(LegalAgenciesListElement *prev_value) {
    prev = prev_value;
}

LegalAgency LegalAgenciesListElement::GetData() const {
    return data;
}

void LegalAgenciesListElement::SetData(const LegalAgency &data_value) {
    data = data_value;
}

void LegalAgenciesList::SwapListElements(LegalAgenciesListElement *left, LegalAgenciesListElement *right) {
    LegalAgenciesListElement *left_prev = left->GetPrev();
    if (left_prev != nullptr) {
        left_prev->SetNext(right);
    }

    LegalAgenciesListElement *right_next = right->GetNext();
    if (right_next != nullptr) {
        right_next->SetPrev(left);
    }

    right->SetPrev(left_prev);
    left->SetNext(right_next);

    right->SetNext(left);
    left->SetPrev(right);

    if (left->GetNext() == nullptr) tail = left;
}

void LegalAgenciesList::StringOfAgenciesToList(const string &agencies_string) {
    string key = "Agency";
    auto key_index = (int32_t) agencies_string.find(key);
    int32_t last_agency_description_symbol = 0;

    while (key_index != -1) {
        last_agency_description_symbol = (int32_t) agencies_string.find('}', (size_t) last_agency_description_symbol);
        last_agency_description_symbol = (int32_t) agencies_string.find('}',
                                                                        (size_t) last_agency_description_symbol + 1);

        AddElementBack(LegalAgency::fromString(
                agencies_string.substr((size_t) key_index, (size_t) last_agency_description_symbol)));

        key_index = (int32_t) agencies_string.find(key, key_index + key.length());
    }
}

void LegalAgenciesList::AddElementBack(const LegalAgency &element_data) {
    auto new_element = new LegalAgenciesListElement(element_data);

    if (tail != nullptr) {
        new_element->SetPrev(tail);
        tail->SetNext(new_element);
    } else {
        head = new_element;
    }

    tail = new_element;

    length++;
}

LegalAgenciesList::LegalAgenciesList() {
    head = nullptr;
    tail = nullptr;
}

LegalAgenciesList::LegalAgenciesList(LegalAgenciesList &copy) {
    LegalAgenciesListElement *copy_current = copy.head;
    while (copy_current != nullptr) {
        this->AddElementBack(copy_current->GetData());
        copy_current = copy_current->GetNext();
    }
}

LegalAgenciesList::~LegalAgenciesList() {
    Clear();
}

LegalAgenciesListElement *LegalAgenciesList::GetTail() {
    return tail;
}

LegalAgenciesListElement *LegalAgenciesList::GetHead() {
    return head;
}

void LegalAgenciesList::AddElementByIndex(const LegalAgency &element_data, size_t index) {
    auto new_element = new LegalAgenciesListElement(element_data);

    LegalAgenciesListElement *prev_for_inserted = head;

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

size_t LegalAgenciesList::GetLength() const {
    return length;
}

void LegalAgenciesList::DeleteElementByIndex(size_t index) {
    LegalAgenciesListElement *deleted = head;

    if (head != nullptr && index < length) {

        for (size_t i = 0; i < index; i++) {
            deleted = deleted->GetNext();
        }

        LegalAgenciesListElement *prev = deleted->GetPrev();
        LegalAgenciesListElement *next = deleted->GetNext();

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

LegalAgenciesListElement &LegalAgenciesList::GetElementByIndex(size_t index) const {
    LegalAgenciesListElement *current;
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

void LegalAgenciesList::WriteToFile(const string &file_name) const {
    ofstream output_file(file_name);

    if (!output_file) {
        cerr << "File " << file_name << " could not be opened for reading!";
    } else {
        for (size_t i = 0; i < length; i++) {
            output_file << GetElementByIndex(i).GetData().toString() << endl;
        }
    }
}

void LegalAgenciesList::Clear() {
    while (length != 0) DeleteElementByIndex(0);
}

void LegalAgenciesList::ReadFromFile(const string &file_name) {
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

void LegalAgenciesList::ShowAll() const {
    LegalAgenciesListElement *current = head;
    while (current != nullptr) {
        cout << current->GetData().toString() << endl;
        current = current->GetNext();
    }
}

LegalAgenciesListElement &LegalAgenciesList::operator[](int index) const {
    return GetElementByIndex((size_t) index);
}

bool LegalAgenciesList::operator==(const LegalAgenciesList &agenciesList) const {
    bool result = true;
    if (length != agenciesList.length) result = false;
    else {
        for (size_t i = 0; i < length; i++) {
            if (!(GetElementByIndex(i).GetData() == agenciesList[(int32_t)i].GetData())) {
                result = false;
                break;
            }
        }
    }
    return result;
}

ostream &operator<<(ostream &output, const LegalAgenciesList &agencies_list) {
    for (size_t i = 0; i < agencies_list.length; i++) {
        output << agencies_list[(int) i].GetData();
    }

    return output;
}

istream &operator>>(istream &input, LegalAgenciesList &agencies_list) {
    size_t count_of_agencies;
    cout << "Enter count of agencies: ";
    input >> count_of_agencies;
    LegalAgency agency_buff;
    for (size_t i = 0; i < count_of_agencies; i++) {
        input >> agency_buff;
        agencies_list.AddElementBack(agency_buff);
    }

    return input;
}

ofstream &operator<<(ofstream &output, const LegalAgenciesList &agencies_list) {
    for (size_t i = 0; i < agencies_list.length; i++) {
        output << agencies_list[(int) i].GetData();
    }
    return output;
}

ifstream &operator>>(ifstream &input, LegalAgenciesList &agencies_list) {
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
