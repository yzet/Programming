//
// Created by zet on 28.05.2021.
//

#include "agencies_vector.h"

AgenciesVector::AgenciesVector() {
    data = vector<Agency *>();
}

AgenciesVector::AgenciesVector(AgenciesVector &copy) {
    for (size_t i = 0; i < data.size(); i++) {
        Agency *agencyCopy = copy[(int)i]->Clone();
        data.push_back(agencyCopy);
    }
}

AgenciesVector::~AgenciesVector() {
    for (Agency *agency: data) {
        delete agency;
    }
}

void AgenciesVector::AddElementByIndex(const Agency &element_data, size_t index) {
    Agency *agencyCopy = element_data.Clone();
    data.insert(data.begin() + (int)index, agencyCopy);
}

void AgenciesVector::AddElementBack(const Agency &element_data) {
    Agency *agencyCopy = element_data.Clone();
    data.push_back(agencyCopy);
}

size_t AgenciesVector::GetLength() const {
    return data.size();
}

void AgenciesVector::DeleteElementByIndex(size_t index) {
    delete data[index];
    data.erase(data.begin() + (int)index);
}

Agency *AgenciesVector::GetElementByIndex(size_t index) const {
    return data[index];
}

void AgenciesVector::SortByComparator(bool (*comparator)(const Agency *, const Agency *)) {
    sort(data.begin(), data.end(), comparator);
}

void AgenciesVector::ShowAll() const {
    for (auto agency : data) {
        cout << *agency;
    }
}

void AgenciesVector::Clear() {
    while (!data.empty()) DeleteElementByIndex(0);
}

Agency *AgenciesVector::operator[](int index) const {
    return data[(size_t)index];
}

bool AgenciesVector::operator==(const AgenciesVector &agenciesList) const {
    bool result = true;
    if (data.size() == agenciesList.GetLength()) {
        for (size_t i = 0; i < data.size(); i++) {
            if (!(*(data[i]) == *(agenciesList.GetElementByIndex(i)))) {
                result = false;
                break;
            }
        }
    } else {
        result = false;
    }
    return result;
}

AgenciesVector  *AgenciesVector::GetElementsBy(bool (*check_function)(const Agency *)) const {
    // TODO: can return no new variable ITS NOT WORK
    auto selected = new AgenciesVector();

    for (auto agency : data) {
        if (check_function(agency)) {
            selected->AddElementBack(*agency);
        }
    }

    return selected;
}

ostream &operator<<(ostream &output, const AgenciesVector &agencies_list) {
    for (size_t i = 0; i < agencies_list.GetLength(); i++) {
        output << *(agencies_list[(int) i]);
    }
    return output;
}

ofstream &operator<<(ofstream &output, const AgenciesVector &agencies_list) {
    if (!output) {
        cerr << "File could not be opened for reading!";
    } else {
        for (size_t i = 0; i < agencies_list.GetLength(); i++) {
            output << *(agencies_list[(int) i]);
        }
    }
    return output;
}

istream &operator>>(istream &input, AgenciesVector &agencies_list) {
    size_t count_of_agencies;
    cout << "Enter count of agencies: ";
    input >> count_of_agencies;
    for (size_t i = 0; i < count_of_agencies; i++) {
        Agency * agency_buff;
        cout << "Enter agency type(L/M):" << endl;
        char agency_type;
        input >> agency_type;
        if (agency_type == 'L') {
            agency_buff = new LegalAgency();
        } else {
            agency_buff = new MarriageAgency();
        }
        input >> *agency_buff;
        agencies_list.AddElementBack(*agency_buff);
        delete agency_buff;
    }

    return input;
}

ifstream &operator>>(ifstream &input, AgenciesVector &agencies_list) {
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

void AgenciesVector::StringOfAgenciesToList(const string &agencies_string) {
    string key = "Agency";
    auto key_index = (int32_t) agencies_string.find(key);
    int32_t last_agency_description_symbol = 0;

    while (key_index != -1) {
        last_agency_description_symbol = (int32_t) agencies_string.find('}', (size_t) last_agency_description_symbol + 1);
        last_agency_description_symbol = (int32_t) agencies_string.find('}',
                                                                        (size_t) last_agency_description_symbol + 1);

        Agency * agencyBuff = AgencyCreator::FromString(
                agencies_string.substr((size_t) key_index, (size_t) last_agency_description_symbol)); //TODO: twice read one agency
        AddElementBack(*agencyBuff);
        delete agencyBuff;

        key_index = (int32_t) agencies_string.find(key, (uint)last_agency_description_symbol - 1);
    }
}
