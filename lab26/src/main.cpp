//#include "agencies_dynamic_array.h"
#include "agencies_list.h"
#include "agency.h"
#include <iostream>
#include "legal_agency.h"
#include "marriage_agency.h"

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

//bool CheckOnKharkiv(Agency &agency)
//{
//    bool result;
//    if (agency.GetCity() == Kharkiv && agency.GetYearsOnMarket() >= 3)
//        result = true;
//    else
//        result = false;
//    return result;
//}

int main() {

    LegalAgency legalAgency;
    cout << legalAgency;
    legalAgency.SetYearsOnMarket(10);
    string legalAgencyString = legalAgency.toString();
    LegalAgency secondAgency = legalAgency.fromString(legalAgencyString);
    cout << (legalAgency == secondAgency) << endl;
    cout << secondAgency;
//    cin >> legalAgency;
//    cout << legalAgency;

//    MarriageAgency marriageAgency;
//    cout << marriageAgency;
//    marriageAgency.SetYearsOnMarket(10);
//    string marriageAgencyString = marriageAgency.toString();
//    MarriageAgency secondAgency = marriageAgency.fromString(marriageAgencyString);
//    cout << secondAgency;
//    cin >> marriageAgency;
//    cout << marriageAgency;


    return 0;
}