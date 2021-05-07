#ifndef __AGENCIES_DYNAMIC_ARRAY__
#define __AGENCIES_DYNAMIC_ARRAY__

#include "agency.h"
//#include "memory.h"
#include <cstring>
#include <iostream>

class AgenciesDynamicArray {
private:
    Agency *array = nullptr;
    size_t length;
public:
    AgenciesDynamicArray(/* args */);

    AgenciesDynamicArray(AgenciesDynamicArray &copy);

    AgenciesDynamicArray(const Agency *array_value, size_t array_length);

    size_t GetLength() const;

    void AddAgency(const Agency &agency);

    void RemoveAgency(int32_t index);

    Agency &GetAgency(int32_t index) const;

    void ShowAll() const;

    AgenciesDynamicArray GetAgenciesBy(bool (*check_function)(Agency &agency)) const;

    ~AgenciesDynamicArray();
};


#endif