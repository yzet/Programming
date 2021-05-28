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
              countries(1) {
        TYPE = 'M';
    };

    MarriageAgency(bool isWeekendsValue, std::string nameValue, int yearsOnMarketValue, person_t directorValue,
                   Cities cityValue, MarriageAgencyService marriageAgencyServiceValue, int32_t countriesValue) :
            Agency(isWeekendsValue, nameValue, yearsOnMarketValue, directorValue,
                   cityValue), marriageAgencyService(marriageAgencyServiceValue), countries(countriesValue) {
        TYPE = 'M';
    };

    ~MarriageAgency() override = default;

    MarriageAgencyService GetMarriageAgencyService() const;
    void SetMarriageAgencyService(MarriageAgencyService marriageAgencyServiceValue);

    int32_t GetCountries() const;
    void SetCountries(int32_t countriesValue);

    static string MarriageServiceToString(const MarriageAgencyService &marriageAgencyService);
    static string CountriesToString(int32_t countries);

    std::string ServiceToString() const override;

    bool GetIsWeekends() const override;

    void SetIsWeekends(bool value) override;

    string GetName() const override;

    void SetName(const string &value) override;

    int GetYearsOnMarket() const override;

    void SetYearsOnMarket(int value) override;

    person_t GetDirector() const override;

    void SetDirector(const person_t &value) override;

    Cities GetCity() const override;

    char GetType() const override;
    void SetType(char type) override;

    Cities StringToCity(const string &city_string) const override;

    string CityToString(Cities city_value) const override;

    string CityToString() const override;

    void PrintDirector() const override;

    void PrintAgency() const override;

    void SetCity(Cities value) override;

    bool operator==(const Agency &agency) const override;

    string toString() const override;

    Agency * Clone() const override{
        return (Agency *)new MarriageAgency(*this);
    }

    int CountriesFromString(const string &countriesString);

    MarriageAgencyService ServiceFromString(string serviceString) const;

    void getAgencyFromConsole(std::istream &input, Agency &agency) const override;
};

#endif //MARRIAGE_AGENCY_H
