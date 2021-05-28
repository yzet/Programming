//
// Created by zet on 27.05.2021.
//

#ifndef AGENCY_CREATOR_H
#define AGENCY_CREATOR_H

#include "agency.h"
#include "legal_agency.h"
#include "marriage_agency.h"

class AgencyCreator {
public:
    static Agency *FromString(std::string agency_string);

    static void ValueToAgencyByIndex(Agency **agency, int32_t index, const std::string &value); // TODO: not work

    static Agency *GenerateAgencyFromType(std::string agencyString);
};

#endif //AGENCY_CREATOR_H
