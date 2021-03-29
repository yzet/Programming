#include "lib.h"

int main()
{

    // read data from text file

    printf("%s\n", "Read data from text file");
    char * agencies_info_text = (char *)calloc(STRING_SIZE, sizeof(char));
    read_agencies_text_file(agencies_info_text, STRING_SIZE - 1);

    char ** agencies_info = (char **)calloc(0, sizeof(char *));
    size_t count_of_agencies = split(&agencies_info, agencies_info_text, "\n");

    // struct LegalAgency * legal_agencies = (struct LegalAgency *)calloc(0, sizeof(struct LegalAgency));
    // struct MarriageAgency * marriage_agencies = (struct MarriageAgency *)calloc(0, sizeof(struct MarriageAgency));
    struct Agency * agencies = (struct Agency *)calloc(0, sizeof(struct Agency));

    // size_t * legal_marriage_count = (size_t *)malloc(2 * sizeof(size_t));
    // set_agencies(&legal_agencies, &marriage_agencies, agencies_info, count_of_agencies, legal_marriage_count);
    set_agencies(&agencies, agencies_info, count_of_agencies);

    printf("%s\n", "Read data from text file complete");

    // end read data from text file

    // print agencies array on screen

    printf("%s\n", "Print agencies from text file");
    for (size_t i = 0; i < count_of_agencies; i++)
    {
        print_agency(agencies + i, stdout);
    }
    printf("%s\n", "Print agencies from text file complete");

    // end print agencies array on screen

    // write marriage agencies array to file

    printf("%s\n", "Write agencies to text file");
    char * path_to_agencies_file = (char *)calloc(STRING_SIZE, sizeof(char));
    get_info_from_console(path_to_agencies_file, STRING_SIZE - 1, "Enter path to file for agencies:");
    FILE * agencies_file = fopen(path_to_agencies_file, "w");
    for (size_t i = 0; i < count_of_agencies; i++)
    {
        print_agency((agencies + i), agencies_file);
    }
    free(path_to_agencies_file);
    fclose(agencies_file);
    printf("%s\n", "Write agencies to text file complete");

    // end write marriage agencies array to file

    // start sorting by charackteristic
    sort_agencies_by_options(&agencies, count_of_agencies, CityOption);
    for (size_t i = 0; i < count_of_agencies; i++)
    {
        print_agency(agencies + i, stdout);
    }
    // end sorting by charackteristic

    // start get agencies in kharkov with 3+ years
    struct Agency * geting_agencies = (struct Agency *)calloc(0, sizeof(struct Agency));
    size_t count_of_geting = get_agencies_from_kharkiv_with_3_or_more_years_on_market(agencies, &geting_agencies, count_of_agencies);;
    for (size_t i = 0; i < count_of_geting; i++)
    {
        print_agency(geting_agencies + i, stdout);
    }

    // end get agencies in kharkov with 3+ years

    // generate agencies

    printf("%s\n", "Generate agencies");
    char * path_to_generate_agencies_file = "generated_agencies.txt"; 
    for (size_t i = 0; i < N; i++)
    {
        generate_agency_info_text(i, path_to_generate_agencies_file);
        if (i < N - 1)
        {
            FILE * generate_agencies_file = fopen(path_to_generate_agencies_file, "a");
            fputs("\n", generate_agencies_file);
            fclose(generate_agencies_file);
        }
    }
    printf("%s\n", "Generate agencies complete");

    // end generate agencies

    // start write agencies binary

    printf("%s\n", "Write agencies binary");
    char * path_to_bin_file = "agencies_output.bin";
    FILE * bin_file = fopen(path_to_bin_file, "wb");
    for (size_t i = 0; i < count_of_agencies; i++)
    {
        write_agency_binary((agencies + i), bin_file);
    }
    fclose(bin_file);
    printf("%s\n", "Write agencies binary complete");
    // end write agencies binary

    // read legal agencies from binary file and read by index

    printf("%s\n", "Read agencies binary");
    bin_file = fopen(path_to_bin_file, "rb");
    struct Agency * agencies_from_binary = (struct Agency *)calloc(count_of_agencies, sizeof(struct Agency));
    for (size_t i = 0; i < count_of_agencies; i++)
    {
        load_agency_binary_by_index((agencies_from_binary + i), bin_file, i);
    }
    fclose(bin_file);
    printf("%s\n", "Read agencies binary complete");

    // end read legal agencies from binary file and read by index

    free(agencies_info_text);

    for (size_t i = 0; i < count_of_agencies; i++)
    {
        free(*(agencies_info + i));
    }
    free(agencies_info);

    // free(legal_marriage_count);
    // free(legal_agencies);
    // free(marriage_agencies);
    // free(legal_agencies_from_binary);
    free(agencies);
    free(agencies_from_binary);
    free(geting_agencies);
    return 0;
}