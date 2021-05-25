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

        string MarriageAgency::ServiceToString(const MarriageAgencyService &marriageAgencyService) {
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

MarriageAgency MarriageAgency::fromString(string agency_string) {
    char desired_symbol = '-';
    auto pos_for_replace = (int32_t) agency_string.find(desired_symbol);

    while (pos_for_replace != -1) {
        agency_string.replace((unsigned long) pos_for_replace, 1, 0, desired_symbol);
        pos_for_replace = (int32_t) agency_string.find(desired_symbol);
        if (pos_for_replace == -1 && desired_symbol != '\n') {
            desired_symbol = '\n';
            pos_for_replace = (int32_t) agency_string.find(desired_symbol);
        }
    }

    MarriageAgency result_agency;
    std::string read_data;
    size_t key_index = 0;
    size_t next_delimiter_index = 0;

    std::string keys[] = {
            "Name",
            "Weekends",
            "Name",
            "Surname",
            "Email",
            "Years on market",
            "City",
            "Service",
            "Countries"
    };
    size_t keys_length = 9;

    for (size_t i = 0; i < keys_length; i++) {
        key_index = agency_string.find(keys[i], key_index);
        next_delimiter_index = std::min(agency_string.find(',', key_index),
                                        agency_string.find('}', key_index)); // TODO: can return -1?
        size_t first_value_index = key_index + keys[i].length() + 1;
        read_data = agency_string.substr(first_value_index, next_delimiter_index - first_value_index);
        MarriageAgency::ValueToAgencyByIndex(result_agency, (int) i, read_data);
    }

    return result_agency;
}

void MarriageAgency::ValueToAgencyByIndex(MarriageAgency &agency, int32_t index,
                                       const std::string &value) { // TODO: why is not static
    switch (index) {
        case 0:
            agency.SetName(value);
            break;
        case 1:
            agency.SetIsWeekends(value == "Yes");
            break;
        case 2:
            agency.director.name = value;
            break;
        case 3:
            agency.director.surname = value;
            break;
        case 4:
            agency.director.email = value;
            break;
        case 5: {
            std::stringstream ss;
            ss << value;
            int yearsOnMarket = 0;
            ss >> yearsOnMarket;
            agency.SetYearsOnMarket(yearsOnMarket);
        }
            break;
        case 6:
            agency.SetCity(agency.StringToCity(value));
            break;
        case 7:
            agency.SetMarriageAgencyService(agency.ServiceFromString(value));
            break;
        case 8: {
//            std::stringstream ss;
//            ss << value;
//            int numberOfCasesWon = 0;
//            ss >> numberOfCasesWon;
            agency.SetCountries(CountriesFromString(value));
        }
        default:
            break;
    }
}

string MarriageAgency::toString() const {
    string agencyString = Agency::toString();
    agencyString.erase(agencyString.length() - 3, 3);
    stringstream legalAgencySS;
    legalAgencySS << agencyString;
    legalAgencySS << "," << std::endl<<"-Service:" << MarriageAgency::ServiceToString(marriageAgencyService) << "," << std::endl <<
                  "-Countries:" << MarriageAgency::CountriesToString(countries) << std::endl << "}" << std::endl;

    return legalAgencySS.str();
}

bool MarriageAgency::operator==(const MarriageAgency &agency) const {
    return (name == agency.name && is_weekends == agency.is_weekends && years_on_market == agency.years_on_market &&
            city == agency.city && director.surname == agency.director.surname &&
            director.name == agency.director.name && director.email == agency.director.email &&
            marriageAgencyService == agency.marriageAgencyService && countries == agency.countries);
}

std::ostream &operator<<(std::ostream &output, const MarriageAgency &agency) {
    output << agency.toString();
    return output;
}

std::istream &operator>>(std::istream &input, MarriageAgency &agency) {
    std::string agency_name;
    bool agency_is_weekends;
    person_t agency_director;
    int agency_years_on_market;
    int agency_city;
    int service;
    int countries;

    std::cout << "Enter in this order: " << std::endl
              << "1)Name\n2)Weekends\n3)DirectorSurname\n4)DirectorName\n5)DirectorEmail\n6)YearsOnMarket\n7)City\n8)Service\n9)Countries"
              << std::endl;

    std::getline(input, agency_name, '\n');
    // regex
    input >> agency_is_weekends;
    std::cin.ignore(1, '\n');
    std::getline(input, agency_director.surname, '\n');
    std::getline(input, agency_director.name, '\n');
    std::getline(input, agency_director.email, '\n');
    input >> agency_years_on_market;
    input >> agency_city;
    input >> service;
    input >> countries;

    agency.name = agency_name;
    agency.is_weekends = agency_is_weekends;
    agency.years_on_market = agency_years_on_market;
    agency.city = (Cities) agency_city;
    agency.director = agency_director;
    agency.marriageAgencyService = (MarriageAgencyService)service;
    agency.countries = countries;

    return input;
}
