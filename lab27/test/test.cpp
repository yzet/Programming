#include "../src/virtual_agencies_list.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <math.h>

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

    Agency * agency1 = new LegalAgency();
    actual.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(12);
    actual.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(6);
    actual.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(7);
    actual.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(2);
    actual.AddElementBack(*agency1);
//    cout << actual;

    AgenciesList expected;
    agency1->SetYearsOnMarket(0);
    expected.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(2);
    expected.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(6);
    expected.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(7);
    expected.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(12);
    expected.AddElementBack(*agency1);
//    cout << expected;
    actual.SortByComparator(comparator_by_years_on_market);

    ASSERT_EQ(actual, expected);

    delete agency1;
    actual.Clear();
    expected.Clear();
}

//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}