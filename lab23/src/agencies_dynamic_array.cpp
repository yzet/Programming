#include "agencies_dynamic_array.hpp"

AgenciesDynamicArray::AgenciesDynamicArray(/* args */) {
    array = nullptr;
    length = 0;
}

AgenciesDynamicArray::AgenciesDynamicArray(AgenciesDynamicArray &copy) {
    this->length = copy.length;
    this->array = new Agency[this->length];
//    for (size_t i = 0; i < this->length; i++) {
//        *(array + i) = *(copy.array + i);
//    }
    std::copy(copy.array, copy.array + copy.length, this->array);
}

AgenciesDynamicArray::~AgenciesDynamicArray() {
    delete [] array;
}

void AgenciesDynamicArray::AddAgency(const Agency &agency) // TODO: test
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

Agency &AgenciesDynamicArray::GetAgency(int32_t index) {
    return array[index]; // TODO: error if array == nullptr
}

void AgenciesDynamicArray::ShowAll() {
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