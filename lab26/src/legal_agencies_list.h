//
// Created by zet on 25.05.2021.
//

#ifndef LEGAL_AGENCIES_LIST_H
#define LEGAL_AGENCIES_LIST_H

//#include "agency.h"
//#include "stdlib.h"
#include "memory.h"
//#include <time.h>
#include "string"
#include "fstream"
#include "legal_agency.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;

class LegalAgenciesListElement
{
private:
    LegalAgenciesListElement * next;
    LegalAgenciesListElement * prev;
    LegalAgency data;

public:

    explicit LegalAgenciesListElement(const LegalAgency &data_value);

    LegalAgenciesListElement * GetNext() const;
    void SetNext(LegalAgenciesListElement * next_value);

    LegalAgenciesListElement * GetPrev() const;
    void SetPrev(LegalAgenciesListElement * prev_value);

    LegalAgency GetData() const;
    void SetData(const LegalAgency &data_value);
};

class LegalAgenciesList
{
private:
    LegalAgenciesListElement * head;
    LegalAgenciesListElement * tail;
    size_t length = 0;

    void SwapListElements(LegalAgenciesListElement * left, LegalAgenciesListElement * right);
    void StringOfAgenciesToList(const string &agencies_string);
public:
    LegalAgenciesList();

    LegalAgenciesList(LegalAgenciesList &copy);

    ~LegalAgenciesList();

    LegalAgenciesListElement * GetHead();
    LegalAgenciesListElement * GetTail();

    void AddElementByIndex(const LegalAgency &element_data, size_t index);
    void AddElementBack(const LegalAgency &element_data);
    size_t GetLength() const;

    void DeleteElementByIndex(size_t index);
    LegalAgenciesListElement& GetElementByIndex(size_t index) const;

    void SortByComparator(int(*comparator)(const LegalAgency &left, const LegalAgency &right));
    LegalAgenciesList GetElementsBy(bool(*check_function)(LegalAgency agency)) const;

    void ShowAll() const;
    void ReadFromFile(const string &file_name);
    void WriteToFile(const string &file_name) const;

    void Clear();

    LegalAgenciesListElement& operator[](int index) const;

    bool operator==(const LegalAgenciesList &agenciesList) const;

    friend ostream& operator<<(ostream& output, const LegalAgenciesList& agencies_list);
    friend istream& operator>>(istream& input, LegalAgenciesList& agencies_list);

    friend ofstream& operator<<(ofstream& output, const LegalAgenciesList& agencies_list);
    friend ifstream& operator>>(ifstream& input, LegalAgenciesList& agencies_list);
};

#endif //LEGAL_AGENCIES_LIST_H
