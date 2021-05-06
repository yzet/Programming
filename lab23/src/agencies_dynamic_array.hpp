#ifndef __AGENCIES_DYNAMIC_ARRAY__
#define __AGENCIES_DYNAMIC_ARRAY__

#include "agency.hpp"
//#include "memory.h"
#include <cstring>
#include <iostream>

class AgenciesDynamicArray
{
private:
    Agency * array = nullptr;
    size_t length;
public:
    AgenciesDynamicArray(/* args */);
    AgenciesDynamicArray(AgenciesDynamicArray &copy); // TODO: check this

    void AddAgency(const Agency &agency);
    void RemoveAgency(int32_t index);
    Agency& GetAgency(int32_t index);
    void ShowAll();

    AgenciesDynamicArray GetAgenciesBy(bool (*check_function)(Agency &agency)) const;

    ~AgenciesDynamicArray();
};


#endif