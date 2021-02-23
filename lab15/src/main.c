#include "lib.h"

int main()
{
    char *agencies_info_text = (char *)calloc(STRING_SIZE, sizeof(char));

    read_agencies_text_file(agencies_info_text, STRING_SIZE - 1);

    char **agencies_info = (char **)calloc(0, sizeof(char *));
    // for free agencies
    size_t count_of_agencies = split(&agencies_info, agencies_info_text, "\n");

    struct LegalAgency **legal_agencies = (struct LegalAgency **)calloc(0, sizeof(struct LegalAgency *));
    struct MarriageAgency **marriage_agencies = (struct MarriageAgency **)calloc(0, sizeof(struct MarriageAgency *));

    set_agencies(&legal_agencies, &marriage_agencies, agencies_info, count_of_agencies);

    free(agencies_info_text);
    // free all agencies info?

    for (size_t i = 0; i < count_of_agencies; i++)
    {
        free(*(agencies_info + i));
    }
    free(agencies_info);

    free(legal_agencies);
    free(marriage_agencies);

    return 0;
}