//
// Created by zyzy9 on 15.06.2021.
//

#ifndef ARRAYHANDLER_H
#define ARRAYHANDLER_H

#include <iostream>
#include <fstream>

using std::string;

using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

using std::out_of_range;
using std::ios_base;
using std::invalid_argument;

class Array {
private:
    int size;
    int * data;
public:
    Array();
    Array(int sizeValue, int * dataValue);
    Array(const Array &copy);

    int GetElementByIndex(size_t index) const;
    int GetSize();

    Array& operator=(Array array1);

    void SetSize(int sizeValue);
    void SetData(int * dataValue, int sizeValue);

    void Clear();
};

class ArrayHandler {
private:
    int countOfArrays;
    Array * arrays;
    int * resultIndices{};

    void Clear();
public:
    ArrayHandler();

    void Run();
    string GetFileName(string fileType);
    void ReadInputFromFile(const string &filename);

    void GetMaxElementIndices();
    void WriteResultInFile(string filename);
};

#endif //ARRAYHANDLER_H
