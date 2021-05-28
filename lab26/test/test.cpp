#include "../src/agencies_list.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <math.h>
#include "../src/legal_agency.h"
#include "../src/legal_agencies_list.h"
#include "../src/marriage_agency.h"
#include "../src/marriage_agencies_list.h"

using std::cout;
using std::endl;
using std::string;

int comparator_by_years_on_market(const Agency &left, const Agency &right) {
    int result = 1;
    if (left.GetYearsOnMarket() < right.GetYearsOnMarket()) {
        result = -1;
    } else if (left.GetYearsOnMarket() == right.GetYearsOnMarket()) {
        result = 0;
    }

    return result;
}

TEST(AgenciesTests, AgenciesListSorting) {

    AgenciesList actual;

    Agency agency1;
    actual.AddElementBack(agency1);
    agency1.SetYearsOnMarket(12);
    actual.AddElementBack(agency1);
    agency1.SetYearsOnMarket(6);
    actual.AddElementBack(agency1);
    agency1.SetYearsOnMarket(7);
    actual.AddElementBack(agency1);
    agency1.SetYearsOnMarket(2);
    actual.AddElementBack(agency1);
//    cout << actual;

    AgenciesList expected;
    agency1.SetYearsOnMarket(0);
    expected.AddElementBack(agency1);
    agency1.SetYearsOnMarket(2);
    expected.AddElementBack(agency1);
    agency1.SetYearsOnMarket(6);
    expected.AddElementBack(agency1);
    agency1.SetYearsOnMarket(7);
    expected.AddElementBack(agency1);
    agency1.SetYearsOnMarket(12);
    expected.AddElementBack(agency1);
//    cout << expected;
    actual.SortByComparator(comparator_by_years_on_market);

    ASSERT_EQ(actual, expected);
}

//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

TEST(LegalAgenciesTests, PositiveComparison) {
    LegalAgency agency1;
    LegalAgency agency2 = agency1;

    ASSERT_EQ(false, agency1 == agency2);

    LegalAgency agency3(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2, LegalAgencyService::defenseInCourt, 4);

    LegalAgency agency4(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2, LegalAgencyService::defenseInCourt, 4);
    ASSERT_EQ(true, agency3 == agency4);
}

TEST(LegalAgenciesTests, NegativeComparison) {
    LegalAgency agency1;
    LegalAgency agency2 = agency1;
    agency2.SetCity(London);
    ASSERT_EQ(false, agency1 == agency2);

    LegalAgency agency3(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2, LegalAgencyService::defenseInCourt, 4);

    LegalAgency agency4(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2, LegalAgencyService::defenseInCourt, 4);
    agency4.SetName("Name");
    ASSERT_EQ(false, agency3 == agency4);
}

TEST(LegalAgenciesTests, AssignmentTest) {
    LegalAgency agency1;
    LegalAgency agency2;
    agency2 = agency1;

    ASSERT_EQ(agency1, agency2);

    LegalAgency agency3(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2, LegalAgencyService::defenseInCourt, 4);

    LegalAgency agency4(true, "Agency Name", 3,
                   person_t{"Surname", "Name",
                            "Email"}, (Cities)2, LegalAgencyService::defenseInCourt, 4);
    agency4 = agency3;
    ASSERT_EQ(agency3, agency4);
}

TEST(LegalAgenciesTests, IndexingOperator) {
    LegalAgency agency1;
    LegalAgency agency2;
    agency2 = LegalAgency(true, "Agency Name", 3, person_t{"DirectorSurname", "DirectorName", "DirectorEmail"}, (Cities)1, LegalAgencyService::defenseInCourt, 4);

    LegalAgenciesList agencies_list;

    agencies_list.AddElementBack(agency1);
    agencies_list.AddElementBack(agency2);
    agencies_list.AddElementBack(agency1);

    size_t number_of_elements = 3;

    LegalAgency actual[] = {
            agencies_list[0].GetData(),
            agencies_list[1].GetData(),
            agencies_list[2].GetData()
    };

    LegalAgency expected[] = {
            agency1,
            agency2,
            agency1
    };

    for (size_t i = 0; i < number_of_elements; i++) {
        ASSERT_EQ(actual[i], expected[i]);
    }

}

TEST(MarriageAgenciesTests, PositiveComparison) {
    MarriageAgency agency1;
    MarriageAgency agency2 = agency1;

    ASSERT_EQ(true, agency1 == agency2);

    MarriageAgency agency3(true, "Agency Name", 3,
                        person_t{"DirectorSurname", "DirectorName",
                                 "DirectorEmail"}, (Cities)2, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);

    MarriageAgency agency4(true, "Agency Name", 3,
                        person_t{"DirectorSurname", "DirectorName",
                                 "DirectorEmail"}, (Cities)2, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);
    ASSERT_EQ(true, agency3 == agency4);
}

TEST(MarriageAgenciesTests, NegativeComparison) {
    MarriageAgency agency1;
    MarriageAgency agency2 = agency1;
    agency2.SetCity(London);
    ASSERT_EQ(false, agency1 == agency2);

    MarriageAgency agency3(true, "Agency Name", 3,
                        person_t{"DirectorSurname", "DirectorName",
                                 "DirectorEmail"}, (Cities)2, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);

    MarriageAgency agency4(true, "Agency Name", 3,
                        person_t{"DirectorSurname", "DirectorName",
                                 "DirectorEmail"}, (Cities)2, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);
    agency4.SetName("Name");
    ASSERT_EQ(false, agency3 == agency4);
}

TEST(MarriageAgenciesTests, AssignmentTest) {
    MarriageAgency agency1;
    MarriageAgency agency2;
    agency2 = agency1;

    ASSERT_EQ(agency1, agency2);

    MarriageAgency agency3(true, "Agency Name", 3,
                        person_t{"DirectorSurname", "DirectorName",
                                 "DirectorEmail"}, (Cities)2, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);

    MarriageAgency agency4(true, "Agency Name", 3,
                        person_t{"Surname", "Name",
                                 "Email"}, (Cities)2, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);
    agency4 = agency3;
    ASSERT_EQ(agency3, agency4);
}

TEST(MarriageAgenciesTests, IndexingOperator) {
    MarriageAgency agency1;
    MarriageAgency agency2;
    agency2 = MarriageAgency(true, "Agency Name", 3, person_t{"DirectorSurname", "DirectorName", "DirectorEmail"}, (Cities)1, MarriageAgencyService::organizationOfMeetings, (int32_t)MarriageAgencyCountry::Romania);

    MarriageAgenciesList agencies_list;

    agencies_list.AddElementBack(agency1);
    agencies_list.AddElementBack(agency2);
    agencies_list.AddElementBack(agency1);

    size_t number_of_elements = 3;

    MarriageAgency actual[] = {
            agencies_list[0].GetData(),
            agencies_list[1].GetData(),
            agencies_list[2].GetData()
    };

    MarriageAgency expected[] = {
            agency1,
            agency2,
            agency1
    };

    for (size_t i = 0; i < number_of_elements; i++) {
        ASSERT_EQ(actual[i], expected[i]);
    }

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}