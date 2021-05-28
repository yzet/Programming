//
// Created by zet on 25.05.2021.
//

#ifndef VIRTUAL_AGENCIES_LIST_H
#define VIRTUAL_AGENCIES_LIST_H

//
// Created by zet on 07.05.2021.
//

#ifndef AGENCIES_LIST_H
#define AGENCIES_LIST_H

#include "agency.h"
//#include "stdlib.h"
#include "memory.h"
//#include <time.h>
#include <vector>
#include "string"
#include "fstream"
#include "legal_agency.h"
#include "marriage_agency.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::vector;

class AgenciesListElement
{
private:
    AgenciesListElement * next{};
    AgenciesListElement * prev{};
    Agency * data;

public:

    explicit AgenciesListElement(const Agency &data_value);

    AgenciesListElement * GetNext() const;
    void SetNext(AgenciesListElement * next_value);

    AgenciesListElement * GetPrev() const;
    void SetPrev(AgenciesListElement * prev_value);

    Agency * GetData() const;
    void SetData(const Agency &data_value);
};

class AgenciesList
{
private:
    AgenciesListElement * head;
    AgenciesListElement * tail;
    size_t length = 0;

    void SwapListElements(AgenciesListElement * left, AgenciesListElement * right);
//    void StringOfAgenciesToList(const string &agencies_string);
public:
    AgenciesList();

    AgenciesList(AgenciesList &copy);

    ~AgenciesList() = default;

    AgenciesListElement * GetHead();
    AgenciesListElement * GetTail();

    void AddElementByIndex(const Agency &element_data, size_t index);
    void AddElementBack(const Agency &element_data);
    size_t GetLength() const;

    void DeleteElementByIndex(size_t index);
//    AgenciesListElement& GetElementByIndex(size_t index) const;
    Agency * GetElementByIndex(size_t index) const;

//    void SortByComparator(int(*comparator)(const Agency &left, const Agency &right));
//    AgenciesList GetElementsBy(bool(*check_function)(Agency agency)) const;

    void SortByComparator(int(*comparator)(const Agency &left, const Agency &right));


    void ShowAll() const;
//    void ReadFromFile(const string &file_name);
//    void WriteToFile(const string &file_name) const;

    void Clear();

//    AgenciesListElement& operator[](int index) const;
    Agency * operator[](int index) const;

    bool operator==(const AgenciesList &agenciesList) const;

    friend ostream& operator<<(ostream& output, const AgenciesList& agencies_list);
//    friend istream& operator>>(istream& input, AgenciesList& agencies_list);
//
//    friend ofstream& operator<<(ofstream& output, const AgenciesList& agencies_list);
//    friend ifstream& operator>>(ifstream& input, AgenciesList& agencies_list);
    AgenciesListElement *GetAgenciesListElementWithIndex(size_t index);

    AgenciesList GetElementsBy(bool (*check_function)(Agency *)) const;
};



#endif //AGENCIES_LIST_H


#endif //VIRTUAL_AGENCIES_LIST_H
