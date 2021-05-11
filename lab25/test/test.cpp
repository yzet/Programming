#include "../src/agencies_list.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <math.h>

using std::cout;
using std::endl;
using std::string;

bool AssertAgencies(const Agency &expected, const Agency &actual, const string &function_name);

bool AssertAgenciesLists(const AgenciesList &expected, const AgenciesList &actual,
                         const string &function_name);



TEST(AgenciesTests, PositiveComparison) {
    Agency agency1;
    Agency agency2 = agency1;

    ASSERT_EQ(true, agency1 == agency2);

    Agency agency3(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2);

    Agency agency4(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2);
    ASSERT_EQ(true, agency3 == agency4);
}

TEST(AgenciesTests, NegativeComparison) {
    Agency agency1;
    Agency agency2 = agency1;
    agency2.SetCity(London);
    ASSERT_EQ(false, agency1 == agency2);

    Agency agency3(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2);

    Agency agency4(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2);
    agency4.SetName("Name");
    ASSERT_EQ(false, agency3 == agency4);
}

TEST(AgenciesTests, AssignmentTest) {
    Agency agency1;
    Agency agency2;
    agency2 = agency1;

    ASSERT_EQ(agency1, agency2);

    Agency agency3(true, "Agency Name", 3,
                   person_t{"DirectorSurname", "DirectorName",
                            "DirectorEmail"}, (Cities)2);

    Agency agency4(true, "Agency Name", 3,
                   person_t{"Surname", "Name",
                            "Email"}, (Cities)2);
    agency4 = agency3;
    ASSERT_EQ(agency3, agency4);
}

TEST(AgenciesTests, IndexingOperator) {
    Agency agency1;
    Agency agency2;
    agency2 = Agency(true, "Agency Name", 3, person_t{"DirectorSurname", "DirectorName", "DirectorEmail"}, (Cities)1);

    AgenciesList agencies_list;

    agencies_list.AddElementBack(agency1);
    agencies_list.AddElementBack(agency2);
    agencies_list.AddElementBack(agency1);

    size_t number_of_elements = 3;

    Agency actual[] = {
            agencies_list[0].GetData(),
            agencies_list[1].GetData(),
            agencies_list[2].GetData()
    };

    Agency expected[] = {
            agency1,
            agency2,
            agency1
    };

    for (size_t i = 0; i < number_of_elements; i++) {
        ASSERT_EQ(actual[i], expected[i]);
    }

}

//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}