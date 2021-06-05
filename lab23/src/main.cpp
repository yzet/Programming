/**
 * @mainpage
 * # Загальне завдання
 * 1. **Розробити** клас, що відображає сутність "базового класу"
 * 2. **Розробити** клас, що має у собі жинамічний масив об'єктів базового класу
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи роботи розроблених функцій
 *
 * @author Zhuravlev Y.
 * @date 28-may-2021
 * @version 1.0
 */


#include "agencies_dynamic_array.h"
#include "agency.h"

/**
 * Функція перевірки міста
 *
 * Функція первіряє чи знаходиться агенство у місті Харків
 * @param agency агенство для перевірки
 * @return функція повертає true або false
 */
bool CheckOnKharkiv(Agency &agency)
{
    bool result;
    if (agency.GetCity() == Kharkiv && agency.GetYearsOnMarket() >= 3)
        result = true;
    else
        result = false;
    return result;
}

int main() {

    AgenciesDynamicArray dynamic_array;

    Agency agency(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    dynamic_array.AddAgency(agency);
    agency.SetName("SName");
    agency.SetYearsOnMarket(3);
    agency.SetCity(Kharkiv);
    dynamic_array.AddAgency(agency);
    agency.SetName("TName");
    agency.SetYearsOnMarket(3);
    agency.SetCity(Kharkiv);
    dynamic_array.AddAgency(agency);
//    dynamic_array.ShowAll();
    std::cout << std::endl;
//    dynamic_array.RemoveAgency(0);
//    dynamic_array.ShowAll();
    dynamic_array.GetAgenciesBy(CheckOnKharkiv).ShowAll();

    return 0;
}