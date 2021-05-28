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
