#include "agencies_dynamic_array.h"
#include "agency.h"

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
    dynamic_array.AddAgency(agency);
    agency.SetName("TName");
    agency.SetYearsOnMarket(3);
    dynamic_array.AddAgency(agency);
//    dynamic_array.ShowAll();
    std::cout << std::endl;
//    dynamic_array.RemoveAgency(0);
//    dynamic_array.ShowAll();
    dynamic_array.GetAgenciesBy(CheckOnKharkiv).ShowAll();

    return 0;
}