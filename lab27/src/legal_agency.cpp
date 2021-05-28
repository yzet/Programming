//
// Created by zet on 11.05.2021.
//

#include "legal_agency.h"

LegalAgencyService LegalAgency::GetLegalAgencyService() const {
    return legalAgencyService;
}

void LegalAgency::SetLegalAgencyService(const LegalAgencyService &legalAgencyServiceValue) {
    legalAgencyService = legalAgencyServiceValue;
}

int LegalAgency::GetNumberOfCasesWon() const {
    return numberOfCasesWon;
}

void LegalAgency::SetNumberOfCasesWon(int numberOfCasesWonValue) {
    numberOfCasesWon = numberOfCasesWonValue;
}

string LegalAgency::LegalAgencyServiceToString(LegalAgencyService legalAgencyService) {
    string serviceString = "NULL";

    switch ((int32_t) legalAgencyService) {
        case (int32_t) LegalAgencyService::divorceConsultation:
            serviceString = "Divorce Consultation";
            break;
        case (int32_t) LegalAgencyService::defenseInCourt:
            serviceString = "Defense in court";
            break;
        default:
            break;
    }

    return serviceString;
}

std::string LegalAgency::ServiceToString() const {
    return LegalAgencyServiceToString(legalAgencyService);
}

bool LegalAgency::GetIsWeekends() const {
    return Agency::GetIsWeekends();
}

void LegalAgency::SetIsWeekends(bool value) {
    Agency::SetIsWeekends(value);
}

std::string LegalAgency::GetName() const {
    return Agency::GetName();
}

void LegalAgency::SetName(const string &value) {
    Agency::SetName(value);
}

int LegalAgency::GetYearsOnMarket() const {
    return Agency::GetYearsOnMarket();
}

void LegalAgency::SetYearsOnMarket(int value) {
    Agency::SetYearsOnMarket(value);
}

person_t LegalAgency::GetDirector() const {
    return Agency::GetDirector();
}

void LegalAgency::SetDirector(const person_t &value) {
    Agency::SetDirector(value);
}

Cities LegalAgency::GetCity() const {
    return Agency::GetCity();
}

void LegalAgency::SetCity(Cities value) {
    Agency::SetCity(value);
}

void LegalAgency::PrintAgency() const {
    std::cout << toString();
}

string LegalAgency::toString() const {
    string agencyString = Agency::toString();
    agencyString.erase(agencyString.length() - 3, 3);
    stringstream legalAgencySS;
    legalAgencySS << agencyString;
    legalAgencySS << "," << std::endl<<"-Service:" << LegalAgency::LegalAgencyServiceToString(legalAgencyService) << "," << std::endl <<
                  "-Number of cases won:" << GetNumberOfCasesWon() << std::endl << "}" << std::endl;

    return legalAgencySS.str();
}

void LegalAgency::PrintDirector() const {
    Agency::PrintDirector();
}

std::string LegalAgency::CityToString() const {
    return Agency::CityToString();
}

std::string LegalAgency::CityToString(Cities city_value) const {
    return Agency::CityToString(city_value);
}

Cities LegalAgency::StringToCity(const string &city_string) const {
    return Agency::StringToCity(city_string);
}

bool LegalAgency::operator==(const Agency &agency) const {
    if (agency.GetType() == this->TYPE) {

        return (name == agency.GetName() && is_weekends == agency.GetIsWeekends() &&
                years_on_market == agency.GetYearsOnMarket() &&
                city == agency.GetCity() && director.surname == agency.GetDirector().surname &&
                director.name == agency.GetDirector().name && director.email == agency.GetDirector().email &&
                legalAgencyService == ((LegalAgency *) (&agency))->GetLegalAgencyService() &&
                numberOfCasesWon == ((LegalAgency *) (&agency))->GetNumberOfCasesWon());
    } else
        return false;
}

char LegalAgency::GetType() const {
    return Agency::GetType();
}

void LegalAgency::SetType(char type) {
    Agency::SetType(type);
}

LegalAgencyService LegalAgency::LegalAgencyServiceFromString(const string &serviceString) {
    LegalAgencyService service = LegalAgencyService::defenseInCourt;
    if (serviceString == "Divorce Consultation") {
        service = LegalAgencyService::divorceConsultation;
    } else if (serviceString == "Defense on court") {
        service = LegalAgencyService::defenseInCourt;
    }

    return service;
}

void LegalAgency::getAgencyFromConsole(std::istream &input, Agency &agency) const {
    Agency::getAgencyFromConsole(input, agency);
    int service;
    int numberOfCasesWonValue;

    std::cout << "-Service:";
    input >> service;
//    std::cout << "," << std::endl;

    std::cout << "-Number of cases won:";
    input >> numberOfCasesWonValue;
    std::cout << "}" << std::endl;

    ((LegalAgency *)(&agency))->SetLegalAgencyService((LegalAgencyService)service);
    ((LegalAgency *)(&agency))->SetNumberOfCasesWon(numberOfCasesWonValue);

}
