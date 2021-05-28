//
// Created by zet on 28.05.2021.
//

#ifndef AGENCIES_VECTOR_H
#define AGENCIES_VECTOR_H

#include "agency.h"
#include "legal_agency.h"
#include "marriage_agency.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::cout;

class AgenciesVector {
private:
    vector<Agency *> data;
//    size_t length = 0;

//    void SwapListElements(AgenciesListElement * left, AgenciesListElement * right);
//    void StringOfAgenciesToList(const string &agencies_string);
public:
    AgenciesVector();

    AgenciesVector(AgenciesVector &copy);

    ~AgenciesVector();

//    AgenciesListElement * GetHead();
//    AgenciesListElement * GetTail();

    void AddElementByIndex(const Agency &element_data, size_t index);

    void AddElementBack(const Agency &element_data);

    size_t GetLength() const;

    void DeleteElementByIndex(size_t index);

    Agency *GetElementByIndex(size_t index) const;

//    void SortByComparator(int(*comparator)(const Agency &left, const Agency &right));
//    AgenciesList GetElementsBy(bool(*check_function)(Agency agency)) const;

    void SortByComparator(bool (*comparator)(const Agency *left, const Agency *right));

    void ShowAll() const;
//    void ReadFromFile(const string &file_name);
//    void WriteToFile(const string &file_name) const;

    void Clear();

//    AgenciesListElement& operator[](int index) const;
    Agency *operator[](int index) const;

    bool operator==(const AgenciesVector &agenciesList) const;

    //TODO input/output
//    friend ostream& operator<<(ostream& output, const AgenciesList& agencies_list);
//    friend istream& operator>>(istream& input, AgenciesList& agencies_list);
//
//    friend ofstream& operator<<(ofstream& output, const AgenciesList& agencies_list);
//    friend ifstream& operator>>(ifstream& input, AgenciesList& agencies_list);
//    AgenciesListElement *GetAgenciesListElementWithIndex(size_t index);

    AgenciesVector  *GetElementsBy(bool (*check_function)(const Agency *)) const;
};


#endif //AGENCIES_VECTOR_H
