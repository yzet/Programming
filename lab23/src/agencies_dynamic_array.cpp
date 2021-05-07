#include "agencies_dynamic_array.h"

AgenciesDynamicArray::AgenciesDynamicArray() {
    array = nullptr;
    length = 0;
#ifdef DEBUG
    std::cout << "Default constructor called for AgenciesDynamicArray" << std::endl;
#endif
}

AgenciesDynamicArray::AgenciesDynamicArray(AgenciesDynamicArray &copy) {
    this->length = copy.length;
    this->array = new Agency[this->length];

    std::copy(copy.array, copy.array + copy.length, this->array);
#ifdef DEBUG
    std::cout << "Copy constructor called for AgenciesDynamicArray" << std::endl;
#endif
}

AgenciesDynamicArray::AgenciesDynamicArray(const Agency * array_value, size_t array_length)
{
    array = new Agency[array_length];
    std::copy(array_value, array_value + array_length, array);
    length = array_length;
#ifdef DEBUG
    std::cout << "Constructor with parameters called for AgenciesDynamicArray" << std::endl;
#endif
}


AgenciesDynamicArray::~AgenciesDynamicArray() {
    delete [] array;
#ifdef DEBUG
    std::cout << "Destructor called for AgenciesDynamicArray" << std::endl;
#endif
}

size_t AgenciesDynamicArray::GetLength() const{
    return length;
}

void AgenciesDynamicArray::AddAgency(const Agency &agency)
{
    auto *new_array = new Agency[length + 1];

    std::copy(array, array + length, new_array);
    new_array[length] = agency;

    delete [] array;
    array = new_array;
    length++;
}

void AgenciesDynamicArray::RemoveAgency(int32_t index) {
    auto *new_array = new Agency[length - 1];
    if (index != 0) {
        std::copy(array, (array + index), new_array);
    }

    if (index < (int32_t) length - 1) {
        std::copy((array + index + 1), (array + length), new_array + index);
    }

    delete [] array;
    array = new_array;
    length--;
}

Agency &AgenciesDynamicArray::GetAgency(int32_t index) const{
    return array[index]; // TODO: error if array == nullptr
}

void AgenciesDynamicArray::ShowAll() const{
    for (size_t i = 0; i < length; i++) {
        GetAgency((int32_t) i).PrintAgency();
        std::cout << std::endl;
    }
}

AgenciesDynamicArray AgenciesDynamicArray::GetAgenciesBy(bool (*check_function)(Agency &agency)) const {
    AgenciesDynamicArray selected_agencies;
    for (size_t i = 0; i < length; i++) {
        if (check_function(array[i])) {
            selected_agencies.AddAgency(array[i]);
        }
    }
    return selected_agencies;
}