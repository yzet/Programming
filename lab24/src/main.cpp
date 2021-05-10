//#include "agencies_dynamic_array.h"
#include "agencies_list.h"
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

    AgenciesList agencies_list;

    Agency agency(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    agencies_list.AddElementBack(agency);

    agency.SetName("SName");
    agency.SetCity(Kharkiv);
    agencies_list.AddElementBack(agency);

    agency.SetName("TName");
    agency.SetCity(London);
    agencies_list.AddElementBack(agency);

    agencies_list.WriteToFile("../data/output.txt");
//    agencies_list.ReadFromFile("../data/output.txt");
    AgenciesList read_data_a_l;
    read_data_a_l.ReadFromFile("../data/output.txt");
    read_data_a_l.ShowAll();

    return 0;
}