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

LegalAgencyService LegalAgency::LegalAgencyServiceFromString(const string &serviceString) {
    LegalAgencyService service = LegalAgencyService::defenseInCourt;
    if (serviceString == "Divorce Consultation") {
        service = LegalAgencyService::divorceConsultation;
    } else if (serviceString == "Defense on court") {
        service = LegalAgencyService::defenseInCourt;
    }

    return service;
}

LegalAgency LegalAgency::fromString(string agency_string) {
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

    LegalAgency result_agency;
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
            "Number of cases won"
    };
    size_t keys_length = 9;

    for (size_t i = 0; i < keys_length; i++) {
        key_index = agency_string.find(keys[i], key_index);
        next_delimiter_index = std::min(agency_string.find(',', key_index),
                                        agency_string.find('}', key_index)); // TODO: can return -1?
        size_t first_value_index = key_index + keys[i].length() + 1;
        read_data = agency_string.substr(first_value_index, next_delimiter_index - first_value_index);
        LegalAgency::ValueToAgencyByIndex(result_agency, (int) i, read_data);
    }

    return result_agency;
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

void LegalAgency::ValueToAgencyByIndex(LegalAgency &agency, int32_t index,
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
            int years_on_market = 0;
            ss >> years_on_market;
            agency.SetYearsOnMarket(years_on_market);
        }
            break;
        case 6:
            agency.SetCity(agency.StringToCity(value));
            break;
        case 7:
            agency.SetLegalAgencyService(agency.LegalAgencyServiceFromString(value));
            break;
        case 8: {
            std::stringstream ss;
            ss << value;
            int numberOfCasesWon = 0;
            ss >> numberOfCasesWon;
            agency.SetNumberOfCasesWon(numberOfCasesWon);
        }
        default:
            break;
    }
}

bool LegalAgency::operator==(const LegalAgency &agency) const {
    return (name == agency.name && is_weekends == agency.is_weekends && years_on_market == agency.years_on_market &&
            city == agency.city && director.surname == agency.director.surname &&
            director.name == agency.director.name && director.email == agency.director.email &&
            legalAgencyService == agency.legalAgencyService && numberOfCasesWon == agency.numberOfCasesWon);
}

std::ostream &operator<<(std::ostream &output, const LegalAgency &agency) {
    output << agency.toString();
    return output;
}

std::istream &operator>>(std::istream &input, LegalAgency &agency) {
    std::string agency_name;
    bool agency_is_weekends;
    person_t agency_director;
    int agency_years_on_market;
    int agency_city;
    int service;
    int numberOfCasesWon;

    std::cout << "Enter in this order: " << std::endl
              << "1)Name\n2)Weekends\n3)DirectorSurname\n4)DirectorName\n5)DirectorEmail\n6)YearsOnMarket\n7)City\n8)Service\n9)NumberOfCasesWon"
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
    input >> numberOfCasesWon;

    agency.name = agency_name;
    agency.is_weekends = agency_is_weekends;
    agency.years_on_market = agency_years_on_market;
    agency.city = (Cities) agency_city;
    agency.director = agency_director;
    agency.legalAgencyService = (LegalAgencyService)service;
    agency.numberOfCasesWon = numberOfCasesWon;

    return input;
}