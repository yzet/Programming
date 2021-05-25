//
// Created by zet on 11.05.2021.
//

#ifndef MARRIAGE_AGENCY_H
#define MARRIAGE_AGENCY_H

#include "agency.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

enum class MarriageAgencyService {
    organizationOfCorrespondence,
    organizationOfMeetings
};

enum class MarriageAgencyCountry {
    Ukraine = 1,
    Poland = 2,
    Romania = 4
};

class MarriageAgency : public Agency {
private:
    MarriageAgencyService marriageAgencyService;
    int32_t countries;
public:
    MarriageAgency()
            : Agency(), marriageAgencyService(MarriageAgencyService::organizationOfCorrespondence),
              countries((int) MarriageAgencyCountry::Ukraine) {};

    MarriageAgency(bool isWeekendsValue, std::string nameValue, int yearsOnMarketValue, person_t directorValue,
                   Cities cityValue, MarriageAgencyService marriageAgencyServiceValue, int32_t countriesValue) :
            Agency(isWeekendsValue, nameValue, yearsOnMarketValue, directorValue,
                   cityValue), marriageAgencyService(marriageAgencyServiceValue), countries(countriesValue) {};

    ~MarriageAgency() = default;

    MarriageAgencyService GetMarriageAgencyService() const;

    void SetMarriageAgencyService(MarriageAgencyService marriageAgencyServiceValue);

    int32_t GetCountries() const;

    void SetCountries(int32_t countriesValue);

    static string ServiceToString(const MarriageAgencyService &marriageAgencyService);

    static string CountriesToString(int32_t countries);

    string toString() const;

    static MarriageAgency fromString(string agency_string);

    static void ValueToAgencyByIndex(MarriageAgency &agency, int32_t index, const string &value);

    MarriageAgencyService ServiceFromString(string serviceString) const;

    static int CountriesFromString(const string &countriesString);

    bool operator==(const MarriageAgency &agency) const;

    friend std::ostream &operator<<(std::ostream &output, const MarriageAgency &marriageAgency);

    friend std::istream &operator>>(std::istream &input, MarriageAgency &agency);
};
#endif //MARRIAGE_AGENCY_H
