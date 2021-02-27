#include "lib.h"

int main()
{
    // char *agencies_info_text = (char *)calloc(STRING_SIZE, sizeof(char));

    // read_agencies_text_file(agencies_info_text, STRING_SIZE - 1);

    // char **agencies_info = (char **)calloc(0, sizeof(char *));
    // // for free agencies
    // size_t count_of_agencies = split(&agencies_info, agencies_info_text, "\n");

    // struct LegalAgency *legal_agencies = (struct LegalAgency *)calloc(0, sizeof(struct LegalAgency));
    // struct MarriageAgency *marriage_agencies = (struct MarriageAgency *)calloc(0, sizeof(struct MarriageAgency));

    // size_t *legal_and_marriage_number = (size_t *)calloc(2, sizeof(size_t));
    // set_agencies(&legal_agencies, &marriage_agencies, agencies_info, count_of_agencies, legal_and_marriage_number);

    // for (size_t i = 0; i < *legal_and_marriage_number; i++)
    // {
    //     print_legal_agency(legal_agencies + i, stdout);
    // }

    // for (size_t i = 0; i < *(legal_and_marriage_number + 1); i++)
    // {
    //     print_marriage_agency(marriage_agencies + i, stdout);
    // }

    // fputs("-----------------------\n", stdout);

    // struct LegalAgency *legal_agencies_in_city = (struct LegalAgency *)calloc(0, sizeof(struct LegalAgency));
    // size_t number_of_legal_agencies_in_city = 0;
    // filter_legal_agencies_by_city(legal_agencies, *(legal_and_marriage_number), &legal_agencies_in_city, Kyiv, &number_of_legal_agencies_in_city);

    // for (size_t i = 0; i < number_of_legal_agencies_in_city; i++)
    // {
    //     print_legal_agency(legal_agencies_in_city + i, stdout);
    // }

    // struct MarriageAgency *marriage_agencies_in_city = (struct MarriageAgency *)calloc(0, sizeof(struct MarriageAgency));
    // size_t number_of_marriage_agencies_in_city = 0;
    // filter_marriage_agencies_by_city(marriage_agencies, *(legal_and_marriage_number + 1), &marriage_agencies_in_city, London, &number_of_marriage_agencies_in_city);

    // for (size_t i = 0; i < number_of_marriage_agencies_in_city; i++)
    // {
    //     print_marriage_agency(marriage_agencies_in_city + i, stdout);
    // }

    generate_agency_info_text(0);

    char * agencies_info_text = (char *)calloc(STRING_SIZE, sizeof(char));
    read_agencies_text_file(agencies_info_text, STRING_SIZE - 1);

    char ** agencies_info = (char **)calloc(0, sizeof(char *));
    size_t count_of_agencies = split(&agencies_info, agencies_info_text, "\n");

    struct LegalAgency * legal_agencies = (struct LegalAgency *)calloc(0, sizeof(struct LegalAgency));
    struct MarriageAgency * marriage_agencies = (struct MarriageAgency *)calloc(0, sizeof(struct MarriageAgency));

    size_t * legal_marriage_count = (size_t *)malloc(2 * sizeof(size_t));
    set_agencies(&legal_agencies, &marriage_agencies, agencies_info, count_of_agencies, legal_marriage_count);

    print_marriage_agency(marriage_agencies, stdout);



    free(agencies_info_text);
    // free all agencies info?

    // free(legal_agencies_in_city);
    // free(marriage_agencies_in_city);

    for (size_t i = 0; i < count_of_agencies; i++)
    {
        free(*(agencies_info + i));
    }
    free(agencies_info);

    free(legal_marriage_count);

    // free(legal_and_marriage_number);
    free(legal_agencies);
    free(marriage_agencies);

    return 0;
}