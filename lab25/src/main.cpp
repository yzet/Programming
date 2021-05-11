//#include "agencies_dynamic_array.h"
#include "agencies_list.h"
#include "agency.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

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

//    Agency agency1;
//    agency1.SetName("FName");
//
//    Agency agency2;
//    agency2 = agency1;
//    agency2.SetCity(London);

//    cout << (agency2 == agency1) << endl;
//    cout << agency2 << endl;

//    cin >> agency1;
//    cout << agency1;

    AgenciesList agencies_list;
    Agency data(true, "Name Name", 3, person_t{"DirName", "DirSurname", "DirEmail"}, (Cities)1);
//    cin >> data;
    agencies_list.AddElementBack(data);
    data.SetCity(London);
    agencies_list.AddElementBack(data);

    ifstream file("../data/output.txt");
//    cout << agencies_list;

    file >> agencies_list;

    agencies_list.ShowAll();
    return 0;
}