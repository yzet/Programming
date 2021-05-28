//#include "agencies_dynamic_array.h"
#include "agency.h"
#include <iostream>
#include "legal_agency.h"
#include "marriage_agency.h"
#include "virtual_agencies_list.h"
#include "agency_creator.h"

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;


int main() {

    Agency * marriageAgency1 = new MarriageAgency();
    cin >> *marriageAgency1;
    cout << *marriageAgency1;
//    Agency * marriageAgency = new MarriageAgency();
//
//    legalAgency->SetYearsOnMarket(10);
//    ((MarriageAgency *)(marriageAgency))->SetCountries(((int)MarriageAgencyCountry::Romania|(int)MarriageAgencyCountry::Poland));
//
//    string legalAgencyString = legalAgency->toString();
//    cout << *legalAgency << endl << endl;
//
//    Agency * testCreator = nullptr;
//    testCreator = AgencyCreator::FromString(legalAgencyString);
//    testCreator->SetYearsOnMarket(10);
//    cout << *testCreator;
//    cout << *legalAgency;
//    cout << *marriageAgency;

//    Agency *agency1 = new LegalAgency();
//    agency1->SetName("FName");
//
//    Agency *agency2 = new LegalAgency();
//    agency2 = agency1;
//    agency2->SetCity(London);
//
//    cout << (*agency2 == *agency1) << endl;
//    cout << agency2 << endl;
//
//    cin >> agency1;
//    cout << agency1;
//
    AgenciesList agencies_list;
    Agency *data = new LegalAgency(true, "Name Name", 3, person_t{"DirName", "DirSurname", "DirEmail"}, (Cities) 1,
                                   LegalAgencyService::defenseInCourt, 3);
//    cin >> data;
    agencies_list.AddElementBack(*data);
    data->SetCity(London);
    agencies_list.AddElementBack(*data);
    Agency *marriageAgency = new MarriageAgency();
    agencies_list.AddElementBack(*marriageAgency);

    cout << (*agencies_list[0] == *agencies_list[1]) << endl;

//    ifstream file("../data/output.txt");
//    cout << agencies_list;

//    file >> agencies_list;

    agencies_list.ShowAll();
    agencies_list.Clear();
    delete marriageAgency;
    delete data;
    return 0;
}