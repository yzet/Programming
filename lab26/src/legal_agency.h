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

public:
    LegalAgency() : Agency(), legalAgencyService(LegalAgencyService::divorceConsultation), numberOfCasesWon(0) {}

    LegalAgency(bool isWeekendsValue, std::string nameValue, int yearsOnMarketValue, person_t directorValue,
                Cities cityValue, LegalAgencyService legalAgencyServiceValue, int numberOfCasesWonValue) :
            Agency(
                    isWeekendsValue,
                    nameValue,
                    yearsOnMarketValue,
                    directorValue,
                    cityValue
            ),
            legalAgencyService(legalAgencyServiceValue), numberOfCasesWon(numberOfCasesWonValue){};

    ~LegalAgency() = default;

    LegalAgencyService GetLegalAgencyService() const;
    void SetLegalAgencyService(const LegalAgencyService &legalAgencyServiceValue);

    int GetNumberOfCasesWon() const;
    void SetNumberOfCasesWon(int numberOfCasesWon);

    static string LegalAgencyServiceToString(LegalAgencyService legalAgencyService);

    static LegalAgency fromString(string legalAgencyString);
    string toString() const;

    static void ValueToAgencyByIndex(LegalAgency &agency, int32_t index, const string &value);

    LegalAgencyService LegalAgencyServiceFromString(const string &serviceString);

    bool operator==(const LegalAgency &agency) const;

    friend std::ostream &operator<<(std::ostream &output, const LegalAgency &agency);

    friend std::istream &operator>>(std::istream &input, LegalAgency &agency);

};

#endif //LEGAL_AGENCY_H
