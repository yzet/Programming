#include "../src/data.h"
#include "../src/list.h"
#include "../src/time_calculate.h"

void test_add_element_to_list_by_index();

void test_add_element_to_list_end();

void test_delete_element_from_list_by_index();

void test_sort_agencies_list_by_years_on_market();

void test_get_element_with_city_from_index();

bool asserts_agencies(struct Agency *expected, struct Agency *actual, const char function_name[33]);

bool assert_two_bidirectional_list_of_agencies(struct AgenciesList *expected, struct AgenciesList *actual,
                                               const char function_name[33]);


int main() {
    setbuf(stdout, 0);
#ifdef DEBUG
    printf("%s\n", "Test started.\n");
    time_t begin = clock();
#endif
    test_add_element_to_list_by_index();
    test_add_element_to_list_end();
    test_delete_element_from_list_by_index();
    test_sort_agencies_list_by_years_on_market();
    test_get_element_with_city_from_index();

#ifdef DEBUG
    printf("Time for all tests: ");
    print_time_delta(begin, clock());
#endif
    return 0;
}

void test_add_element_to_list_by_index() {

    printf("Function: %s\n", __FUNCTION__);
#ifdef DEBUG
    time_t begin = clock();
#endif
    bool result = true;

    struct AgenciesList actual;

    init_agencies_list(&actual);

    struct Agency new_agency = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};
    add_element_to_list_by_index(&actual, &new_agency, 0);
    new_agency.name = "Agency Name 2";
    new_agency.director.surname = "Surname2";
    add_element_to_list_by_index(&actual, &new_agency, 0);
    new_agency.name = "Agency Name 3";
    add_element_to_list_by_index(&actual, &new_agency, 1);

    struct AgenciesList expected;
    struct AgenciesListElement first_element;
    struct AgenciesListElement second_element;
    struct AgenciesListElement third_element;

    first_element.next = &second_element;
    second_element.prev = &first_element;
    second_element.next = &third_element;
    third_element.prev = &second_element;
    third_element.next = NULL;
    expected.head = &first_element;

    struct Agency new_agency_expected = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};
    memcpy(&third_element.data, &new_agency_expected, sizeof(struct Agency));
    new_agency_expected.name = "Agency Name 2";
    new_agency_expected.director.surname = "Surname2";
    memcpy(&first_element.data, &new_agency_expected, sizeof(struct Agency));
    new_agency_expected.name = "Agency Name 3";
    memcpy(&second_element.data, &new_agency_expected, sizeof(struct Agency));

    result &= assert_two_bidirectional_list_of_agencies(&expected, &actual, __FUNCTION__);

    free_agencies_list(&actual);
    if (result)
        printf("%s\n", "OK");
#ifdef DEBUG
    printf("Time: ");
    print_time_delta(begin, clock());
#endif
}

void test_add_element_to_list_end() {
    printf("Function: %s\n", __FUNCTION__);
#ifdef DEBUG
    time_t begin = clock();
#endif
    bool result = true;

    struct AgenciesList actual;

    init_agencies_list(&actual);

    struct Agency new_agency = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};

    add_element_to_list_end(&actual, &new_agency);

    new_agency.name = "Agency Name 2";
    new_agency.director.surname = "Surname2";

    add_element_to_list_end(&actual, &new_agency);

    struct AgenciesList expected;
    init_agencies_list(&expected);

    struct Agency new_agency_expected = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};
    add_element_to_list_by_index(&expected, &new_agency_expected, 0);

    new_agency_expected.name = "Agency Name 2";
    new_agency_expected.director.surname = "Surname2";

    add_element_to_list_by_index(&expected, &new_agency_expected, 1);

    result &= assert_two_bidirectional_list_of_agencies(&expected, &actual, __FUNCTION__);

    if (result)
        printf("%s\n", "OK");

    free_agencies_list(&actual);
    free_agencies_list(&expected);
#ifdef DEBUG
    printf("Time: ");
    print_time_delta(begin, clock());
#endif
}

void test_delete_element_from_list_by_index() {
#ifdef DEBUG
    time_t begin = clock();
#endif
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;

    struct AgenciesList actual;

    init_agencies_list(&actual);

    struct Agency new_agency = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};

    add_element_to_list_end(&actual, &new_agency);

    new_agency.name = "Agency Name 2";
    new_agency.director.surname = "Surname2";

    add_element_to_list_end(&actual, &new_agency);

    new_agency.name = "Agency Name 3";
    add_element_to_list_end(&actual, &new_agency);

    delete_element_from_list_by_index(&actual, 1);

    struct AgenciesList expected;
    init_agencies_list(&expected);

    struct Agency new_agency_expected = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};

    add_element_to_list_end(&expected, &new_agency_expected);

    new_agency_expected.name = "Agency Name 2";
    new_agency_expected.director.surname = "Surname2";

    add_element_to_list_end(&expected, &new_agency_expected);

    new_agency_expected.name = "Agency Name 3";
    add_element_to_list_end(&expected, &new_agency_expected);

    struct AgenciesListElement *deleted_element = expected.head->next;
    expected.head->next = expected.head->next->next;
    expected.head->next->prev = expected.head;
    free(deleted_element->data.name);
    free(deleted_element->data.director.name);
    free(deleted_element->data.director.surname);
    free(deleted_element->data.director.email);
    free(deleted_element);

    result &= assert_two_bidirectional_list_of_agencies(&expected, &actual, __FUNCTION__);
    if (result)
        printf("%s\n", "OK");

    free_agencies_list(&actual);
    free_agencies_list(&expected);
#ifdef DEBUG
    printf("Time: ");
    print_time_delta(begin, clock());
#endif
}

void test_sort_agencies_list_by_years_on_market() {
#ifdef DEBUG
    time_t begin = clock();
#endif
    printf("Function: %s\n", __FUNCTION__);
    bool result = true;

    struct AgenciesList actual;

    init_agencies_list(&actual);

    struct Agency new_agency = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};

    add_element_to_list_end(&actual, &new_agency);

    new_agency.name = "Agency Name 2";
    new_agency.director.surname = "Surname2";
    new_agency.years_on_market = 1;

    add_element_to_list_end(&actual, &new_agency);

    new_agency.name = "Agency Name 3";
    new_agency.years_on_market = 2;
    add_element_to_list_end(&actual, &new_agency);

    sort_agencies_list_by_years_on_market(&actual);

    struct AgenciesList expected;
    init_agencies_list(&expected);

    struct Agency new_agency_expected = {true, "Agency Name 2", 1, {"Surname2", "Name1", "Email@mail.com"}, Kharkiv};

    add_element_to_list_end(&expected, &new_agency_expected);

    new_agency_expected.name = "Agency Name 3";
    new_agency_expected.years_on_market = 2;

    add_element_to_list_end(&expected, &new_agency_expected);

    new_agency_expected.name = "Agency Name 1";
    new_agency_expected.director.surname = "Surname1";
    new_agency_expected.years_on_market = 3;

    add_element_to_list_end(&expected, &new_agency_expected);

    result &= assert_two_bidirectional_list_of_agencies(&expected, &actual, __FUNCTION__);
    if (result)
        printf("%s\n", "OK");

    free_agencies_list(&actual);
    free_agencies_list(&expected);
#ifdef DEBUG
    printf("Time: ");
    print_time_delta(begin, clock());
#endif
}

void test_get_element_with_city_from_index() {
    printf("Function: %s\n", __FUNCTION__);
#ifdef DEBUG
    time_t begin = clock();
#endif
    bool result = true;

    struct AgenciesList data;

    init_agencies_list(&data);

    struct Agency new_agency = {true, "Agency Name 1", 3, {"Surname1", "Name1", "Email@mail.com"}, Kharkiv};

    add_element_to_list_end(&data, &new_agency);

    new_agency.name = "Agency Name 2";
    new_agency.director.surname = "Surname2";
    new_agency.years_on_market = 1;
    new_agency.city = Kyiv;

    add_element_to_list_end(&data, &new_agency);

    new_agency.city = Kyiv;
    new_agency.name = "Agency Name 3";
    new_agency.years_on_market = 2;
    add_element_to_list_end(&data, &new_agency);

    struct AgenciesListElement *actual = NULL;

    get_element_with_city_from_index(&data, 1, Kyiv, &actual);

    struct Agency expected = {true, "Agency Name 2", 1, {"Surname2", "Name1", "Email@mail.com"}, Kyiv};

    result &= asserts_agencies(&expected, &actual->data, __FUNCTION__);

    if (result)
        printf("%s\n", "OK");

    free_agencies_list(&data);
#ifdef DEBUG
    printf("Time: ");
    print_time_delta(begin, clock());
#endif
}

bool assert_two_bidirectional_list_of_agencies(struct AgenciesList *expected, struct AgenciesList *actual,
                                               const char function_name[33]) {
    bool result = true;

    struct AgenciesListElement *expected_current = expected->head;
    struct AgenciesListElement *actual_current = actual->head;

    while (expected_current != NULL && actual_current != NULL) {
        result &= asserts_agencies(&expected_current->data, &actual_current->data, function_name);
        expected_current = expected_current->next;
        actual_current = actual_current->next;
    }

    if (expected_current != NULL || actual_current != NULL) {
        result = false;
    }

    if (!result) {
        printf("Function: %s failed:\nActual data:\n", function_name);
        print_agencies_list_on_screen(actual);
        putc('\n', stdout);
        printf("Expected data:\n");
        print_agencies_list_on_screen(expected);
        putc('\n', stdout);
    }

    return result;
}


bool asserts_agencies(struct Agency *expected, struct Agency *actual, const char function_name[33]) {
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
    if (!result) {
        printf("Function: %s failed:\nActual data:\n", function_name);
        print_agency(actual, stdout);
        printf("Expected data:\n");
        print_agency(expected, stdout);
    }

    return result;
}