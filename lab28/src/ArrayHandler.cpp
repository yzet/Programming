//
// Created by zyzy9 on 15.06.2021.
//

#include "ArrayHandler.h"

ArrayHandler::ArrayHandler() : countOfArrays(0), arrays(nullptr), resultIndices(nullptr) {}

void ArrayHandler::Run() {
    while (true) {
        try {
            string filename = GetFileName("input");
            if (filename == "\\exit") {
                break;
            }
            ReadInputFromFile(filename);
            filename = GetFileName("output");
            if (filename == "\\exit") {
                break;
            }
            GetMaxElementIndices();
            WriteResultInFile(filename);
            Clear();
        } catch (out_of_range &e) {
            Clear();
            cout << e.what();
        } catch (ios_base::failure &e) {
            Clear();
            cout << e.what();
        } catch (invalid_argument &e) {
            Clear();
            cout << e.what();
        }
        cout << endl;
    }
}

string ArrayHandler::GetFileName(string fileType) { // input or output
    cout << "Enter path to " << fileType << " file: ";
    string filename;
    cin >> filename;
    return filename;
}

void ArrayHandler::ReadInputFromFile(const string &filename) {
    ifstream inputFile(filename);
    inputFile >> countOfArrays;
    if (countOfArrays < 0) {
        string message = "In file " + filename + " invalid argument\n";
        throw invalid_argument(message);
    }
    arrays = new Array[countOfArrays];
    for (size_t i = 0; i < (size_t)countOfArrays; i++) {
        int arraySize;
        inputFile >> arraySize;
        if (arraySize < 0) {
            string message = "In file " + filename + " invalid argument\n";
            throw invalid_argument(message);
        }
        int array[arraySize];
        for (int j = 0; j < arraySize; j++) {
            inputFile >> array[j];
        }
        arrays[i].SetData(array, arraySize);
    }
}

void ArrayHandler::WriteResultInFile(string filename) {
    ofstream outputFile(filename);
    for (int i = 0; i < countOfArrays; i++) {
        outputFile << "array " << i << " max value in index: " << resultIndices[i] << endl;
    }
    outputFile.close();
}

void ArrayHandler::GetMaxElementIndices() {
    resultIndices = new int[countOfArrays];
    for (int i = 0; i < countOfArrays; i++) {
        int maxValue, index = 0;
        maxValue = arrays[i].GetElementByIndex(0);
        for (int j = 1; j < arrays[i].GetSize(); j++) {
            if (arrays[i].GetElementByIndex(j) > maxValue) {
                index = j;
                maxValue = arrays[i].GetElementByIndex(j);
            }
        }
        resultIndices[i] = index;
    }
}

void ArrayHandler::Clear() {
    for (int i = 0; i < countOfArrays; i++) {
        arrays[i].Clear();
    }
    delete resultIndices;
    delete arrays;
}

Array::Array(int sizeValue, int *dataValue) : size(sizeValue) {
    this->data = new int[sizeValue];
    for (int i = 0; i < size; i++) {
        this->data[i] = dataValue[i];
    }
}

int Array::GetElementByIndex(size_t index) const{
    if (index > (size_t)size) {
        throw out_of_range("Out of range in array");
    } else {
        return data[index];
    }
}

Array::Array(const Array &copy) {
    size = copy.size;
    for (size_t i = 0; i < (size_t)size; i++) {
        data[i] = copy.GetElementByIndex(i);
    }
}

Array& Array::operator=(const Array array1) {
    size = array1.size;
    if (data != nullptr)
        delete data;
    data = new int[size];
    for (int i = 0; i < size; i++){
        data[i] = array1.data[i];
    }
    return *this;
}

Array::Array(): size(0), data(nullptr) {}

void Array::SetSize(int sizeValue) {
    this->size = sizeValue;
    delete data;
    data = new int[size];
}

void Array::SetData(int *dataValue, int sizeValue) {
    this->size = sizeValue;
    delete this->data;
    this->data = new int[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = dataValue[i];
    }
}

int Array::GetSize() {
    return size;
}

void Array::Clear() {
    delete data;
}

