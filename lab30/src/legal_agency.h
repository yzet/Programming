//
// Created by zet on 11.05.2021.
//

#ifndef LEGAL_AGENCY_H
#define LEGAL_AGENCY_H

#include "agency.h"
#include <string>

using std::string;
using std::stringstream;

enum class LegalAgencyService {
    divorceConsultation,
    defenseInCourt
};

class LegalAgency : public Agency {
private:
    LegalAgencyService legalAgencyService;
    int numberOfCasesWon;

protected:
    void PrintDirector() const override;

    std::string CityToString() const override;

    std::string CityToString(Cities city_value) const override;

    Cities StringToCity(const std::string &city_string) const override;

public:

    LegalAgency() : Agency(), legalAgencyService(LegalAgencyService::divorceConsultation), numberOfCasesWon(0) {
        TYPE = 'L';
    }

    LegalAgency(bool isWeekendsValue, std::string nameValue, int yearsOnMarketValue, person_t directorValue,
                Cities cityValue, LegalAgencyService legalAgencyServiceValue, int numberOfCasesWonValue) :
            Agency(
                    isWeekendsValue,
                    nameValue,
                    yearsOnMarketValue,
                    directorValue,
                    cityValue
            ),
            legalAgencyService(legalAgencyServiceValue), numberOfCasesWon(numberOfCasesWonValue) {
        TYPE = 'L';
    };

    ~LegalAgency() override = default;

    LegalAgencyService GetLegalAgencyService() const;

    void SetLegalAgencyService(const LegalAgencyService &legalAgencyServiceValue);

    int GetNumberOfCasesWon() const;

    void SetNumberOfCasesWon(int numberOfCasesWon);

    static string LegalAgencyServiceToString(LegalAgencyService legalAgencyService);

    std::string ServiceToString() const override;

    string toString() const override;
    void getAgencyFromConsole(std::istream &input,  Agency &agency) const;


    bool GetIsWeekends() const override;

    void SetIsWeekends(bool value) override;

    std::string GetName() const override;

    void SetName(const std::string &value) override;

    int GetYearsOnMarket() const override;

    void SetYearsOnMarket(int value) override;

    person_t GetDirector() const override;

    void SetDirector(const person_t &value) override;

    Cities GetCity() const override;

    void SetCity(Cities value) override;

    void PrintAgency() const override;

//    static Agency * FromString(std::string agency_string); // TODO: edit to *

//    Agency &operator=(const Agency &agency);

    bool operator==(const Agency &agency) const override;

    char GetType() const override;
    void SetType(char type) override;

    Agency * Clone() const override{
        return (Agency *)new LegalAgency(*this);
    }

    LegalAgencyService LegalAgencyServiceFromString(const string &serviceString);
};

#endif //LEGAL_AGENCY_H
