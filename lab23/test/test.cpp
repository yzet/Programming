#include "../src/agencies_dynamic_array.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void TestAddAgency();

void TestRemoveAgency();

bool AssertAgencies(const Agency &expected, const Agency &actual, const string &function_name);

bool AssertAgenciesDynamicArray(const AgenciesDynamicArray &expected, const AgenciesDynamicArray &actual,
                                const string &function_name);

int main() {

    TestAddAgency();
    TestRemoveAgency();
    return 0;
}

void TestAddAgency() {
    cout << "Function: " << __FUNCTION__ << endl;
    bool result = true;

    AgenciesDynamicArray actual;

    Agency agency1(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    actual.AddAgency(agency1);
    Agency agency2(agency1);
    agency2.SetName("SName");
    actual.AddAgency(agency2);
    Agency agency3(agency2);
    agency3.SetName("TName");
    actual.AddAgency(agency3);

    size_t expected_length = 3;
    auto *expected_array = new Agency[expected_length];
    expected_array[0] = agency1;
    expected_array[1] = agency2;
    expected_array[2] = agency3;

    AgenciesDynamicArray expected(expected_array, expected_length);

    result &= AssertAgenciesDynamicArray(expected, actual, __FUNCTION__);

    delete[] expected_array;
    if (result)
        cout << "OK" << endl;
}

void TestRemoveAgency() {
    cout << "Function: " << __FUNCTION__ << endl;
    bool result = true;

    AgenciesDynamicArray actual;
    AgenciesDynamicArray expected;

    Agency agency1(false, "FName", 1, {"FNa", "FSur", "Femail"}, Kiyv);
    actual.AddAgency(agency1);
    expected.AddAgency(agency1);

    Agency agency2(agency1);
    agency2.SetName("SName");
    actual.AddAgency(agency2);

    Agency agency3(agency2);
    agency3.SetName("TName");
    actual.AddAgency(agency3);
    expected.AddAgency(agency3);

    actual.RemoveAgency(1);

    result &= AssertAgenciesDynamicArray(expected, actual, __FUNCTION__);

    if (result)
        cout << "OK" << endl;
}

bool AssertAgenciesDynamicArray(const AgenciesDynamicArray &expected, const AgenciesDynamicArray &actual,
                                const string &function_name) {
    bool result = true;

    if (expected.GetLength() != actual.GetLength()) result = false;

    for (size_t i = 0; i < expected.GetLength(); i++) {
        result &= AssertAgencies(expected.GetAgency((int32_t) i), actual.GetAgency((int32_t) i), function_name);
    }

    if (!result) {
        cout << "Function: " << function_name << "failed:\nActual data:\n";
        actual.ShowAll();
        cout << endl;
        cout << "Expected data" << endl;
        expected.ShowAll();
    }

    return result;
}

bool AssertAgencies(const Agency &expected, const Agency &actual, const string &function_name) {
    bool result = true;

    result = ((expected.GetName().compare(actual.GetName()) == 0) ? true : false);
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
        actual.PrintAgency();
        cout << endl;
        cout << "Expected data" << endl;
        expected.PrintAgency();
    }

    return result;
}