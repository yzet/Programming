//
// Created by zet on 27.05.2021.
//

#include "agency_creator.h"

Agency *AgencyCreator::GenerateAgencyFromType(std::string agencyString) {
    std::string keyString = "Type";
    size_t keyIndex = agencyString.find(keyString);
    size_t firstValueIndex = keyIndex + keyString.length() + 1;
    size_t nextDelimiterIndex = std::min(agencyString.find(',', keyIndex),
                                    agencyString.find('}', keyIndex));
    std::string value = agencyString.substr(firstValueIndex, nextDelimiterIndex - firstValueIndex);

    if(value[0] == 'L') {
        return new LegalAgency();
    } else if (value[0] == 'M') {
        return new MarriageAgency();
    }

    return nullptr;
}

Agency *AgencyCreator::FromString(std::string agency_string) {
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

    Agency * result_agency = nullptr;

    std::string read_data;
    size_t key_index = 0;
    size_t next_delimiter_index = 0;

//    std::string keys[10] = {
//            "Type",
//            "Name",
//            "Weekends",
//            "Name",
//            "Surname",
//            "Email",
//            "Years on market",
//            "City",
//            "Service",
//            "0"
//    };

    std::vector<string> keys(10);
    keys[0] = "Type";
    keys[1] = "Name";
    keys[2] = "Weekends";
    keys[3] = "Name";
    keys[4] = "Surname";
    keys[5] = "Email";
    keys[6] = "Years on market";
    keys[7] = "City";
    keys[8] = "Service";

    size_t keys_length = 10;

    result_agency = GenerateAgencyFromType(agency_string);
    if (result_agency->GetType() == 'L') {
        keys[9] = "Number of cases won";
    } else {
        keys[9] = "Countries";
    }
    for (size_t i = 1; i < keys_length; i++) {
        key_index = agency_string.find(keys[i], key_index);
        next_delimiter_index = std::min(agency_string.find(',', key_index),
                                        agency_string.find('}', key_index)); // TODO: can return -1?
        size_t first_value_index = key_index + keys[i].length() + 1;
        read_data = agency_string.substr(first_value_index, next_delimiter_index - first_value_index);

        AgencyCreator::ValueToAgencyByIndex(&result_agency, (int) i, read_data);
    }
    return result_agency;
}

void AgencyCreator::ValueToAgencyByIndex(Agency **agency, int32_t index, const std::string &value) { // TODO: not work
    switch (index) {
        case 0:
            (*agency)->SetType(value[0]);
            break;
        case 1:
            (*agency)->SetName(value);
            break;
        case 2:
            (*agency)->SetIsWeekends(value == "Yes");
            break;
        case 3: {
            (*agency)->SetDirector({value, (*agency)->GetDirector().surname, (*agency)->GetDirector().email});
            break;
        }
        case 4:
            (*agency)->SetDirector({(*agency)->GetDirector().name, value, (*agency)->GetDirector().email});
            break;
        case 5:
            (*agency)->SetDirector({(*agency)->GetDirector().name, (*agency)->GetDirector().surname, value});
            break;
        case 6: {
            std::stringstream ss;
            ss << value;
            int years_on_market = 0;
            ss >> years_on_market;
            (*agency)->SetYearsOnMarket(years_on_market);
        }
            break;
        case 7:
            (*agency)->SetCity((*agency)->StringToCity(value));
            break;
        case 8: {
            if ((*agency)->GetType() == 'L') {
                ((LegalAgency *) agency)->SetLegalAgencyService(
                        ((LegalAgency *) agency)->LegalAgencyServiceFromString(value));
            } else if ((*agency)->GetType() == 'M') {
                ((MarriageAgency *) agency)->SetMarriageAgencyService(
                        ((MarriageAgency *) agency)->ServiceFromString(value));
            }
        }
            break;
        case 9: {
            if ((*agency)->GetType() == 'L') {
                std::stringstream ss;
                ss << value;
                int numberOfCasesWon;
                ss >> numberOfCasesWon;
                ((LegalAgency *) *agency)->SetNumberOfCasesWon(numberOfCasesWon); // TODO: if delete * from *agency we have not error?
            } else if ((*agency)->GetType() == 'M') {
                ((MarriageAgency *) agency)->SetCountries(((MarriageAgency *) agency)->CountriesFromString(value));
            }
        }
        default:
            break;
    }
}
