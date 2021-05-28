//
// Created by zet on 11.05.2021.
//

#include "marriage_agency.h"

MarriageAgencyService MarriageAgency::GetMarriageAgencyService() const {
    return marriageAgencyService;
}

void MarriageAgency::SetMarriageAgencyService(MarriageAgencyService marriageAgencyServiceValue) {
    marriageAgencyService = marriageAgencyServiceValue;
}

int32_t MarriageAgency::GetCountries() const {
    return countries;
}

void MarriageAgency::SetCountries(int32_t countriesValue) {
    countries = countriesValue;
}

string MarriageAgency::CountriesToString(int32_t countries) {
    stringstream countries_ss;
    // is empty?
    if ((countries & (int32_t) MarriageAgencyCountry::Ukraine) != 0) countries_ss << "Ukraine";
    if ((countries & (int32_t) MarriageAgencyCountry::Poland) != 0) {
        if (countries_ss.str().length() != 0) countries_ss << ' ';
        countries_ss << "Poland";
    }
    if ((countries & (int32_t) MarriageAgencyCountry::Romania) != 0) {
        if (countries_ss.str().length() != 0) countries_ss << ' ';
        countries_ss << "Romania";
    }
    return countries_ss.str();
}

string MarriageAgency::MarriageServiceToString(const MarriageAgencyService &marriageAgencyService) {
    string result = "NULL";
    switch ((int32_t)marriageAgencyService) {
        case (int32_t)MarriageAgencyService::organizationOfCorrespondence:
            result = "Organization of correspondence";
            break;
        case (int32_t)MarriageAgencyService::organizationOfMeetings:
            result = "Organization of meetings";
            break;
        default:
            break;
    }

    return result;
}

std::string MarriageAgency::ServiceToString() const {
    return MarriageAgency::MarriageServiceToString(marriageAgencyService);
}

bool MarriageAgency::GetIsWeekends() const {
    return Agency::GetIsWeekends();
}

void MarriageAgency::SetIsWeekends(bool value) {
    Agency::SetIsWeekends(value);
}

std::string MarriageAgency::GetName() const {
    return Agency::GetName();
}

void MarriageAgency::SetName(const string &value) {
    Agency::SetName(value);
}

int MarriageAgency::GetYearsOnMarket() const {
    return Agency::GetYearsOnMarket();
}

void MarriageAgency::SetYearsOnMarket(int value) {
    Agency::SetYearsOnMarket(value);
}

person_t MarriageAgency::GetDirector() const {
    return Agency::GetDirector();
}

void MarriageAgency::SetDirector(const person_t &value) {
    Agency::SetDirector(value);
}

Cities MarriageAgency::GetCity() const {
    return Agency::GetCity();
}

void MarriageAgency::SetCity(Cities value) {
    Agency::SetCity(value);
}

void MarriageAgency::PrintAgency() const {
    std::cout << toString();
}

void MarriageAgency::PrintDirector() const {
    Agency::PrintDirector();
}

std::string MarriageAgency::CityToString() const {
    return Agency::CityToString();
}

std::string MarriageAgency::CityToString(Cities city_value) const {
    return Agency::CityToString(city_value);
}

Cities MarriageAgency::StringToCity(const string &city_string) const {
    return Agency::StringToCity(city_string);
}

bool MarriageAgency::operator==(const Agency &agency) const {
    if (agency.GetType() == this->TYPE) {

        return (name == agency.GetName() && is_weekends == agency.GetIsWeekends() &&
                years_on_market == agency.GetYearsOnMarket() &&
                city == agency.GetCity() && director.surname == agency.GetDirector().surname &&
                director.name == agency.GetDirector().name && director.email == agency.GetDirector().email &&
                marriageAgencyService == ((MarriageAgency *) (&agency))->GetMarriageAgencyService() &&
                countries == ((MarriageAgency *) (&agency))->GetCountries());
    } else
        return false;
}

char MarriageAgency::GetType() const {
    return Agency::GetType();
}

string MarriageAgency::toString() const {
    string agencyString = Agency::toString();
    agencyString.erase(agencyString.length() - 3, 3);
    stringstream marriageAgencySS;
    marriageAgencySS << agencyString;
    marriageAgencySS << "," << std::endl<<"-Service:" << MarriageAgency::MarriageServiceToString(marriageAgencyService) << "," << std::endl <<
                  "-Countries:" << MarriageAgency::CountriesToString(countries) << std::endl << "}" << std::endl;

    return marriageAgencySS.str();
}

void MarriageAgency::SetType(char type) {
    Agency::SetType(type);
}

int MarriageAgency::CountriesFromString(const string &countriesString){
    int result = 0;

    if (countriesString.find("Ukraine") != string::npos) {
        result += (int)MarriageAgencyCountry::Ukraine;
    }
    if (countriesString.find("Poland") != string::npos) {
        result += (int)MarriageAgencyCountry::Poland;
    }
    if (countriesString.find("Romania") != string::npos) {
        result += (int)MarriageAgencyCountry::Romania;
    }

    return result;
}

MarriageAgencyService MarriageAgency::ServiceFromString(string serviceString) const{
    MarriageAgencyService result;
    if (serviceString == "Organization of correspondence") {
        result = MarriageAgencyService::organizationOfCorrespondence;
    } else if (serviceString == "Organization if meetings") {
        result = MarriageAgencyService::organizationOfMeetings;
    } else {
        std::cerr << "ServiceFromString Error";
    }
    return result;
}

void MarriageAgency::getAgencyFromConsole(std::istream &input, Agency &agency) const {
    Agency::getAgencyFromConsole(input, agency);
    int service;
    int countriesValue;

    std::cout << "-Service:";
    input >> service;
//    std::cout << "," << std::endl;

    std::cout << "-Countries:";
    input >> countriesValue;
    std::cout << "}" << std::endl;

    ((MarriageAgency *)(&agency))->SetMarriageAgencyService((MarriageAgencyService)service);
    ((MarriageAgency *)(&agency))->SetCountries(countriesValue);

}

