#include "../src/lib.h"

bool test_set_agencies_from_text_file();
bool asserts_legal_agencies(struct LegalAgency * expected, struct LegalAgency * actual, const char function_name[33]);
bool asserts_marriage_agencies(struct MarriageAgency * expected, struct MarriageAgency * actual, const char function_name[33]);

bool test_set_agencies_from_text_file()
{
    printf("Function: %s ", __FUNCTION__);

    struct LegalAgency expected_legal_agencies[2] = {
        {{true, "AGENCY_NAME1", 2, {"Surname0", "Name0", "Email0.gmail"}, Kyiv}, DefenseInCourt, 3},
        {{true, "AGENCY_NAME2", 3, {"Surname1", "Name1", "Email1.gmail"}, London}, DefenseInCourt, 4}
    };

    struct MarriageAgency expected_marriage_agencies[2] = {
        {{true, "AGENCY_NAME3", 3, {"Surname2", "Name2", "Email2.gmail"}, London}, MailingOrganization, 3},
        {{false, "AGENCY_NAME4", 1, {"Surname3", "Name3", "Email3.gmail"}, London}, MailingOrganization, 2}
    };

    struct LegalAgency * actual_legal_agencies = (struct LegalAgency *)calloc(0, sizeof(struct LegalAgency));
    struct MarriageAgency * actual_marriage_agencies = (struct MarriageAgency *)calloc(0, sizeof(struct MarriageAgency));

    bool result = true;

    set_agencies_from_text_file_full(&actual_legal_agencies, &actual_marriage_agencies);

    for (size_t i = 0; i < 2; i++)
    {
        result &= asserts_legal_agencies(&(expected_legal_agencies[i]), (actual_legal_agencies + i), __FUNCTION__);
    }

    for (size_t i = 0; i < 2; i++)
    {
        result &= asserts_marriage_agencies(&expected_marriage_agencies[i], (actual_marriage_agencies+i), __FUNCTION__);
    }

    if (result) printf("%s", "Ok\n");

    free(actual_legal_agencies);
    free(actual_marriage_agencies);
    return result;
}

bool asserts_legal_agencies(struct LegalAgency * expected, struct LegalAgency * actual, const char function_name[33])
{
    bool result = true;
    if ( strcmp(expected->main_info.director.surname, actual->main_info.director.surname) != 0 ) result = false;
    if ( strcmp(expected->main_info.director.name, actual->main_info.director.name) != 0 ) result = false;
    if ( strcmp(expected->main_info.director.email, actual->main_info.director.email) != 0 ) result = false;
    if ( expected->main_info.is_weekends != actual->main_info.is_weekends ) result = false;
    if ( strcmp( expected->main_info.name, actual->main_info.name ) != 0) result = false;
    if ( expected->main_info.years_on_market != actual->main_info.years_on_market ) result = false;
    if ( expected->main_info.city != actual->main_info.city ) result = false;
    if ( expected->number_of_success_fees != actual->number_of_success_fees ) result = false;
    if ( expected->service_type != actual->service_type) result = false;

    if (!result)
    {
        printf("Function: %s failed:\nActual data:\n", function_name);
        print_legal_agency(actual, stdout);
        printf("Expected data:\n");
        print_legal_agency(expected, stdout);
    }

    return result;
}

bool asserts_marriage_agencies(struct MarriageAgency * expected, struct MarriageAgency * actual, const char function_name[33])
{
    bool result = true;

    if ( strcmp(expected->main_info.director.surname, actual->main_info.director.surname) != 0 ) result = false;
    if ( strcmp(expected->main_info.director.name, actual->main_info.director.name) != 0 ) result = false;
    if ( strcmp(expected->main_info.director.email, actual->main_info.director.email) != 0 ) result = false;
    if ( expected->main_info.is_weekends != actual->main_info.is_weekends ) result = false;
    if ( strcmp( expected->main_info.name, actual->main_info.name ) != 0) result = false;
    if ( expected->main_info.years_on_market != actual->main_info.years_on_market ) result = false;
    if ( expected->main_info.city != actual->main_info.city ) result = false;
    if ( expected->service_type != actual->service_type ) result = false;
    if ( expected->countries != actual->countries ) result = false;

    if (!result)
    {
        printf("Function: %s failed:\nActual data:\n", function_name);
        print_marriage_agency(actual, stdout);
        printf("Expected data:\n");
        print_marriage_agency(expected, stdout);
    }

    return result;
}

int main()
{
    test_set_agencies_from_text_file();
    return 0;
}
