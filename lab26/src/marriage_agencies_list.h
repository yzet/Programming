
#ifndef MARRIAGE_AGENCIES_LIST_H
#define MARRIAGE_AGENCIES_LIST_H

//#include "agency.h"
//#include "stdlib.h"
#include "memory.h"
//#include <time.h>
#include "string"
#include "fstream"
#include "marriage_agency.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;

class MarriageAgenciesListElement
{
private:
    MarriageAgenciesListElement * next;
    MarriageAgenciesListElement * prev;
    MarriageAgency data;

public:

    explicit MarriageAgenciesListElement(const MarriageAgency &data_value);

    MarriageAgenciesListElement * GetNext() const;
    void SetNext(MarriageAgenciesListElement * next_value);

    MarriageAgenciesListElement * GetPrev() const;
    void SetPrev(MarriageAgenciesListElement * prev_value);

    MarriageAgency GetData() const;
    void SetData(const MarriageAgency &data_value);
};

class MarriageAgenciesList {
private:
    MarriageAgenciesListElement * head;
    MarriageAgenciesListElement * tail;
    size_t length = 0;

    void SwapListElements(MarriageAgenciesListElement * left, MarriageAgenciesListElement * right);
    void StringOfAgenciesToList(const string &agencies_string);
public:
    MarriageAgenciesList();

    MarriageAgenciesList(MarriageAgenciesList &copy);

    ~MarriageAgenciesList();

    MarriageAgenciesListElement * GetHead();
    MarriageAgenciesListElement * GetTail();

    void AddElementByIndex(const MarriageAgency &element_data, size_t index);
    void AddElementBack(const MarriageAgency &element_data);
    size_t GetLength() const;

    void DeleteElementByIndex(size_t index);
    MarriageAgenciesListElement& GetElementByIndex(size_t index) const;

    void SortByComparator(int(*comparator)(const MarriageAgency &left, const MarriageAgency &right));
    MarriageAgenciesList GetElementsBy(bool(*check_function)(MarriageAgency agency)) const;

    void ShowAll() const;
    void ReadFromFile(const string &file_name);
    void WriteToFile(const string &file_name) const;

    void Clear();

    MarriageAgenciesListElement& operator[](int index) const;

    bool operator==(const MarriageAgenciesList &agenciesList) const;

    friend ostream& operator<<(ostream& output, const MarriageAgenciesList& agencies_list);
    friend istream& operator>>(istream& input, MarriageAgenciesList& agencies_list);

    friend ofstream& operator<<(ofstream& output, const MarriageAgenciesList& agencies_list);
    friend ifstream& operator>>(ifstream& input, MarriageAgenciesList& agencies_list);
};


#endif //MARRIAGE_AGENCIES_LIST_H
