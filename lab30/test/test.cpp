#include "../src/agencies_vector.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <math.h>

using std::cout;
using std::endl;
using std::string;

bool comparator_by_years_on_market(const Agency *left, const Agency *right) {

    if (left->GetYearsOnMarket() > right->GetYearsOnMarket()) {
        return false;
    }
    return true;
}

bool checkOnKharkiv(const Agency *agency) {
    if (agency->GetCity() == Kharkiv)
        return true;
    return false;
}

bool AgenciesThatWorkInKharkivAndHaveThreeOrMoreYearsOnMarket(const Agency *agency) {
    if (agency->GetCity() == Kharkiv && agency->GetYearsOnMarket() >= 3) {
        return true;
    }
    return false;
}

TEST(AgenciesTests, AgenciesVectorSorting) {

    AgenciesVector actual;

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

    AgenciesVector expected;
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

TEST(AgenciesTests, AgenciesVectorSelecting) {
    AgenciesVector data;

    Agency * agency1 = new LegalAgency();
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(2);
    agency1->SetCity(Kiyv);
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(6);
    agency1->SetCity(London);
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(7);
    agency1->SetCity(Kharkiv);
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(12);
    data.AddElementBack(*agency1);

    AgenciesVector expected;
    agency1->SetYearsOnMarket(0);
    expected.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(7);
    expected.AddElementBack(*agency1);
    agency1->SetYearsOnMarket(12);
    expected.AddElementBack(*agency1);

//    cout << expected;
    AgenciesVector * actual = data.GetElementsBy(checkOnKharkiv);

    ASSERT_EQ(*actual, expected);

    delete actual;
    expected.Clear();
    delete agency1;
}

TEST(AgenciesTests, AgenciesVectorKharkivAndThreeOrMoreYears) {
    AgenciesVector data;

    Agency * agency1 = new LegalAgency();
    Agency * agency2 = new MarriageAgency();
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(4);
    agency1->SetCity(Kiyv);
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(6);
    agency1->SetCity(London);
    data.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(7);
    agency1->SetCity(Kharkiv);
    data.AddElementBack(*agency1);

    agency2->SetYearsOnMarket(4);
    agency2->SetCity(Kharkiv);
    data.AddElementBack(*agency2);

    agency2->SetYearsOnMarket(2);
    agency2->SetCity(Kharkiv);
    data.AddElementBack(*agency2);

    agency2->SetYearsOnMarket(7);
    agency2->SetCity(Kharkiv);
    data.AddElementBack(*agency2);

    AgenciesVector expected;
    agency1->SetCity(Kharkiv);
    agency2->SetCity(Kharkiv);
    agency1->SetYearsOnMarket(7);
    expected.AddElementBack(*agency1);
    agency2->SetYearsOnMarket(4);
    expected.AddElementBack(*agency2);
    agency2->SetYearsOnMarket(7);
    expected.AddElementBack(*agency2);

//    cout << expected;
    AgenciesVector * actual = data.GetElementsBy(AgenciesThatWorkInKharkivAndHaveThreeOrMoreYearsOnMarket);

    ASSERT_EQ(*actual, expected);

    delete actual;
    expected.Clear();
    delete agency1;
    delete agency2;

}

TEST(AgenciesTests, AgenciesVectorIfstremTest) {
    AgenciesVector expected;

    Agency * agency1 = new LegalAgency();
    Agency * agency2 = new MarriageAgency();

    expected.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(4);
    agency1->SetCity(Kiyv);
    expected.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(6);
    agency1->SetCity(London);
    expected.AddElementBack(*agency1);

    agency1->SetYearsOnMarket(7);
    agency1->SetCity(Kharkiv);
    expected.AddElementBack(*agency1);

    agency2->SetYearsOnMarket(4);
    agency2->SetCity(Kharkiv);
    expected.AddElementBack(*agency2);

    agency2->SetYearsOnMarket(2);
    agency2->SetCity(Kharkiv);
    expected.AddElementBack(*agency2);

    agency2->SetYearsOnMarket(7);
    agency2->SetCity(Kharkiv);
    expected.AddElementBack(*agency2);

    AgenciesVector actual;

    ifstream agenciesInputFile("../data/output.txt");
    agenciesInputFile >> actual;

    ASSERT_EQ(actual, expected);

    delete agency1;
    delete agency2;
}

//int main(int argc, char **argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}