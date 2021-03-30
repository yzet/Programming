#include "../src/lib.h"

bool asserts_agencies(struct Agency *expected, struct Agency *actual, const char function_name[33]);
void test_sort_agencies_by_options();
void test_get_agencies_from_kharkiv_with_3_or_more_years_on_market();

int main()
{
    test_sort_agencies_by_options();
    test_get_agencies_from_kharkiv_with_3_or_more_years_on_market();
    return 0;
}

#define NUMBER_OF_AGENCIES 4
void test_sort_agencies_by_options()
{
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;
    // struct Agency actual[NUMBER_OF_AGENCIES] =
    //     {
    //         {true, "AGENCY NAME1", 2, {"Surname0", "Name0", "Email0.gmail"}, Kharkiv},
    //         {true, "AGENCY NAME2", 4, {"Surname1", "Name1", "Email1.gmail"}, London},
    //         {true, "AGENCY NAME3", 3, {"Surname2", "Name2", "Email2.gmail"}, Kyiv},
    //         {false, "AGENCY NAME4", 2, {"Surname3", "Name3", "Email3.gmail"}, London}};

    struct Agency *actual = (struct Agency *)calloc(NUMBER_OF_AGENCIES, sizeof(struct Agency));

    struct Agency buff0 = {true, "AGENCY NAME1", 2, {"Surname0", "Name0", "Email0.gmail"}, Kharkiv};
    memcpy((actual + 0), &buff0, sizeof(buff0));
    struct Agency buff1 = {true, "AGENCY NAME2", 4, {"Surname1", "Name1", "Email1.gmail"}, London};
    memcpy((actual + 1), &buff1, sizeof(buff1));
    struct Agency buff2 = {true, "AGENCY NAME3", 3, {"Surname2", "Name2", "Email2.gmail"}, Kyiv};
    memcpy((actual + 2), &buff2, sizeof(buff2));
    struct Agency buff3 = {false, "AGENCY NAME4", 2, {"Surname3", "Name3", "Email3.gmail"}, London};
    memcpy((actual + 3), &buff3, sizeof(buff3));

    struct Agency expected[NUMBER_OF_AGENCIES] =
        {
            {true, "AGENCY NAME1", 2, {"Surname0", "Name0", "Email0.gmail"}, Kharkiv},
            {false, "AGENCY NAME4", 2, {"Surname3", "Name3", "Email3.gmail"}, London},
            {true, "AGENCY NAME3", 3, {"Surname2", "Name2", "Email2.gmail"}, Kyiv},
            {true, "AGENCY NAME2", 4, {"Surname1", "Name1", "Email1.gmail"}, London}};

    sort_agencies_by_options(&actual, NUMBER_OF_AGENCIES, YearsOnMarketOption);

    for (size_t i = 0; i < NUMBER_OF_AGENCIES; i++)
    {
        result &= asserts_agencies(&expected[i], (actual + i), __FUNCTION__);
    }

    if (result)
        printf("%s\n", "OK");

    free(actual);
}

#define NUMBER_OF_GETING_AGENCIES 2
void test_get_agencies_from_kharkiv_with_3_or_more_years_on_market()
{
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;
    struct Agency *data = (struct Agency *)calloc(NUMBER_OF_AGENCIES, sizeof(struct Agency));

    struct Agency buff0 = {true, "AGENCY NAME1", 2, {"Surname0", "Name0", "Email0.gmail"}, Kharkiv};
    memcpy((data + 0), &buff0, sizeof(buff0));
    struct Agency buff1 = {true, "AGENCY NAME2", 4, {"Surname1", "Name1", "Email1.gmail"}, Kharkiv};
    memcpy((data + 1), &buff1, sizeof(buff1));
    struct Agency buff2 = {true, "AGENCY NAME3", 3, {"Surname2", "Name2", "Email2.gmail"}, Kharkiv};
    memcpy((data + 2), &buff2, sizeof(buff2));
    struct Agency buff3 = {false, "AGENCY NAME4", 2, {"Surname3", "Name3", "Email3.gmail"}, London};
    memcpy((data + 3), &buff3, sizeof(buff3));

    struct Agency *actual = (struct Agency *)calloc(0, sizeof(struct Agency));

    get_agencies_from_kharkiv_with_3_or_more_years_on_market(data, &actual, NUMBER_OF_AGENCIES);

    struct Agency expected[NUMBER_OF_GETING_AGENCIES] =
        {
            {true, "AGENCY NAME2", 4, {"Surname1", "Name1", "Email1.gmail"}, Kharkiv},
            {true, "AGENCY NAME3", 3, {"Surname2", "Name2", "Email2.gmail"}, Kharkiv}};
    for (size_t i = 0; i < NUMBER_OF_GETING_AGENCIES; i++)
    {
        result &= asserts_agencies(&expected[i], (actual + i), __FUNCTION__);
    }
    if (result)
        printf("%s\n", "OK");

    free(actual);
    free(data);
}

bool asserts_agencies(struct Agency *expected, struct Agency *actual, const char function_name[33])
{
    bool result = true;
    if (strcmp(expected->director.surname, actual->director.surname) != 0)
        result = false;
    if (strcmp(expected->director.name, actual->director.name) != 0)
        result = false;
    if (strcmp(expected->director.email, actual->director.email) != 0)
        result = false;
    if (expected->is_weekends != actual->is_weekends)
        result = false;
    if (strcmp(expected->name, actual->name) != 0)
        result = false;
    if (expected->years_on_market != actual->years_on_market)
        result = false;
    if (expected->city != actual->city)
        result = false;
    if (!result)
    {
        printf("Function: %s failed:\nActual data:\n", function_name);
        print_agency(actual, stdout);
        printf("Expected data:\n");
        print_agency(expected, stdout);
    }

    return result;
}
