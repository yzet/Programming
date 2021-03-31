#include "../src/lib.h"

void test_insert_string();
void test_reduce_string();
void test_insert_agencies();
void test_reduce_agencies();

bool assert_dynamic_array_chars(struct DynamicArray *expected, struct DynamicArray *actual, const char function_name[33]);
bool asserts_agencies(struct Agency *expected, struct Agency *actual, const char function_name[33]);

#define NUMBER_OF_AGENCIES_INSERT 3
#define NUMBER_OF_AGENCIES_REDUCE 2

int main()
{
    test_insert_string();
    test_reduce_string();
    test_insert_agencies();
    test_reduce_agencies();

    return 0;
}

void test_insert_string()
{
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;

    struct DynamicArray actual;
    init_dynamic_array(&actual, sizeof(char));
    void *inserted_data = (void *)"hello";
    insert(&actual, inserted_data, strlen((char *)inserted_data), 0);
    void *inserted_data1 = (void *)"hel";
    insert(&actual, inserted_data, strlen((char *)inserted_data1), 3);

    struct DynamicArray expected;
    expected.length = 8;
    expected.size_of_elements = 1;
    expected.array = (void *)"helhello";

    result = assert_dynamic_array_chars(&expected, &actual, __FUNCTION__);

    if (result)
        printf("%s\n", "OK");

    free_dynamic_array(&actual);
}

void test_reduce_string()
{
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;

    struct DynamicArray actual;
    init_dynamic_array(&actual, sizeof(char));
    insert(&actual, (void *)"hello", 5, 0);
    reduce(&actual, 1, 3);

    struct DynamicArray expected;
    expected.length = 2;
    expected.size_of_elements = 1;
    expected.array = (void *)"ho";

    result = assert_dynamic_array_chars(&expected, &actual, __FUNCTION__);
    if (result)
        printf("%s\n", "OK");

    free_dynamic_array(&actual);
}

bool assert_dynamic_array_chars(struct DynamicArray *expected, struct DynamicArray *actual, const char function_name[33])
{
    bool result = true;

    if (expected->length != actual->length)
    {
        result = false;
    }
    else if (expected->size_of_elements != actual->size_of_elements)
    {
        result = false;
    }
    else
    {
        for (size_t i = 0; i < expected->length; i++)
        {
            if (*(char *)(expected->array + i) != *(char *)(actual->array + i))
            {
                result = false;
            }
        }
    }
    if (!result)
    {
        printf("Function: %s failed:\nActual data:\n", function_name);
        print_dynamic_char_array(actual, stdout);
        putc('\n', stdout);
        printf("Expected data:\n");
        print_dynamic_char_array(expected, stdout);
        putc('\n', stdout);
    }
    return result;
}

void test_insert_agencies()
{
    bool result = true;

    printf("Function: %s\n", __FUNCTION__);

    struct DynamicArray actual;
    init_dynamic_array(&actual, sizeof(struct Agency));

    void *new_agency = (void *)malloc(sizeof(struct Agency) * 1);
    struct Person director;
    set_person(&director, "Surname1", "Name1", "Email1@gmail.com");
    set_agency((struct Agency *)new_agency, true, "AGENCY NAME1", 3, director, Kharkiv);

    insert(&actual, new_agency, 1, 0);

    set_person(&director, "Surname2", "Name2", "Email2@gmail.com");
    set_agency((struct Agency *)new_agency, false, "AGENCY NAME2", 4, director, London);

    insert(&actual, new_agency, 1, 1);

    set_person(&director, "Surname3", "Name3", "Email3@gmail.com");
    set_agency((struct Agency *)new_agency, true, "AGENCY NAME3", 2, director, Kyiv);
    insert(&actual, new_agency, 1, 1);

    struct Agency expected[NUMBER_OF_AGENCIES_INSERT] =
        {
            {true, "AGENCY NAME1", 3, {"Surname1", "Name1", "Email1@gmail.com"}, Kharkiv},
            {true, "AGENCY NAME3", 2, {"Surname3", "Name3", "Email3@gmail.com"}, Kyiv},
            {false, "AGENCY NAME2", 4, {"Surname2", "Name2", "Email2@gmail.com"}, London}};

    for (size_t i = 0; i < NUMBER_OF_AGENCIES_INSERT; i++)
    {
        result &= asserts_agencies(&expected[i], (struct Agency *)actual.array + i, __FUNCTION__);
    }
    if (result)
        printf("%s\n", "OK");

    free_dynamic_array(&actual);
    free(new_agency);
}

void test_reduce_agencies()
{
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;

    struct DynamicArray actual;
    init_dynamic_array(&actual, sizeof(struct Agency));

    void *new_agency = (void *)malloc(sizeof(struct Agency) * 1);
    struct Person director;
    set_person(&director, "Surname1", "Name1", "Email1@gmail.com");
    set_agency((struct Agency *)new_agency, true, "AGENCY NAME1", 3, director, Kharkiv);

    insert(&actual, new_agency, 1, 0);

    set_person(&director, "Surname2", "Name2", "Email2@gmail.com");
    set_agency((struct Agency *)new_agency, false, "AGENCY NAME2", 4, director, London);

    insert(&actual, new_agency, 1, 1);

    set_person(&director, "Surname3", "Name3", "Email3@gmail.com");
    set_agency((struct Agency *)new_agency, true, "AGENCY NAME3", 2, director, Kyiv);
    insert(&actual, new_agency, 1, 1);

    reduce(&actual, 1, 1);

    struct Agency expected[NUMBER_OF_AGENCIES_INSERT] =
        {
            {true, "AGENCY NAME1", 3, {"Surname1", "Name1", "Email1@gmail.com"}, Kharkiv},
            {false, "AGENCY NAME2", 4, {"Surname2", "Name2", "Email2@gmail.com"}, London}};
    
    for (size_t i = 0; i < NUMBER_OF_AGENCIES_REDUCE; i++)
    {
        result &= asserts_agencies(&expected[i], (struct Agency *)actual.array + i, __FUNCTION__);
    }
    if (result)
        printf("%s\n", "OK");

    free_dynamic_array(&actual);
    free(new_agency);
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