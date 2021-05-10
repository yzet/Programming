#include "../src/agencies_list.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//void TestAddAgency();
//
//void TestRemoveAgency();

void TestAddElementBack();

void TestAddElementByIndex();

void TestRemoveAgency();

bool AssertAgencies(const Agency &expected, const Agency &actual, const string &function_name);

bool AssertAgenciesLists(const AgenciesList &expected, const AgenciesList &actual,
                         const string &function_name);

int main() {

    TestAddElementBack();
    TestAddElementByIndex();
    TestRemoveAgency();
    return 0;
}

void TestAddElementBack() {
    cout << "Function: " << __FUNCTION__ << endl;
    bool result = true;

    AgenciesList actual;
    AgenciesList expected;

    Agency agency1(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    actual.AddElementBack(agency1);
    Agency agency2(agency1);
    agency2.SetName("SName");
    actual.AddElementBack(agency2);
    Agency agency3(agency2);
    agency3.SetName("TName");
    actual.AddElementBack(agency3);

    size_t expected_length = 3;
    auto *expected_array = new Agency[expected_length];
    expected_array[0] = agency1;
    expected_array[1] = agency2;
    expected_array[2] = agency3;

    result &= AssertAgencies(expected_array[0], actual.GetHead()->GetData(), __FUNCTION__);
    result &= AssertAgencies(expected_array[1], actual.GetHead()->GetNext()->GetData(), __FUNCTION__);
    result &= AssertAgencies(expected_array[2], actual.GetHead()->GetNext()->GetNext()->GetData(), __FUNCTION__);

    result &= AssertAgencies(expected_array[2], actual.GetTail()->GetData(), __FUNCTION__);
    result &= AssertAgencies(expected_array[1], actual.GetTail()->GetPrev()->GetData(), __FUNCTION__);
    result &= AssertAgencies(expected_array[0], actual.GetTail()->GetPrev()->GetPrev()->GetData(), __FUNCTION__);

    delete[] expected_array;
    if (result)
        cout << "OK" << endl;
}

void TestRemoveAgency() {
    cout << "Function: " << __FUNCTION__ << endl;
    bool result = true;

    AgenciesList actual;
    AgenciesList expected;

    Agency agency1(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    actual.AddElementBack(agency1);
    Agency agency2(agency1);
    agency2.SetName("SName");
    actual.AddElementBack(agency2);
    Agency agency3(agency2);
    agency3.SetName("TName");
    actual.AddElementBack(agency3);

    actual.DeleteElementByIndex(1);

    expected.AddElementBack(agency1);
    expected.AddElementBack(agency3);

    result &= AssertAgenciesLists(expected, actual, __FUNCTION__);

    if (result)
        cout << "OK" << endl;
}

void TestAddElementByIndex() {
    cout << "Function: " << __FUNCTION__ << endl;
    bool result = true;

    AgenciesList actual;
    AgenciesList expected;

    Agency agency1(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    actual.AddElementByIndex(agency1, 0);
    Agency agency2(agency1);
    agency2.SetName("SName");
    actual.AddElementByIndex(agency2, 1);
    Agency agency3(agency2);
    agency3.SetName("TName");
    actual.AddElementByIndex(agency3, 1);

    expected.AddElementBack(agency1);
    expected.AddElementBack(agency3);
    expected.AddElementBack(agency2);

    result &= AssertAgenciesLists(expected, actual, __FUNCTION__);

    if (result)
        cout << "OK" << endl;

}

bool AssertAgenciesLists(const AgenciesList &expected, const AgenciesList &actual,
                         const string &function_name) {
    bool result = true;

    if (expected.GetLength() != actual.GetLength()) result = false;


    for (size_t i = 0; i < expected.GetLength(); i++) {
        result &= AssertAgencies(expected.GetElementByIndex(i).GetData(), actual.GetElementByIndex(i).GetData(),
                                 function_name);
    }

    if (!result) {
        cout << "Function: " << function_name << " failed:\nActual data:\n";
        actual.ShowAll();
        cout << endl << endl;
        cout << "Expected data" << endl;
        expected.ShowAll();
        cout << endl << endl;
    }

    return result;
}

bool AssertAgencies(const Agency &expected, const Agency &actual, const string &function_name) {
    bool result = true;

    result = (expected.GetName().compare(actual.GetName()) == 0);
    result &= (expected.GetIsWeekends() == actual.GetIsWeekends());
    result &= (expected.GetYearsOnMarket() == actual.GetYearsOnMarket());

    if (expected.GetDirector().surname != actual.GetDirector().surname)
        result &= false;
    if (expected.GetDirector().name.compare(actual.GetDirector().name) != 0)
        result &= false;
    if (expected.GetDirector().email.compare(actual.GetDirector().email) != 0)
        result &= false;

    result &= (expected.GetCity() == actual.GetCity());

    if (!result) {
        cout << "Function: " << function_name << "failed:\nActual data:\n";
        cout << actual.toString() << endl << endl;
        cout << "Expected data" << endl;
        cout << expected.toString() << endl << endl;
    }

    return result;
}