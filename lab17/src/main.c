#include "lib.h"

int main()
{

    // read data from text file

    printf("%s\n", "Read data from text file");
    char * agencies_info_text = (char *)calloc(STRING_SIZE, sizeof(char));
    read_agencies_text_file(agencies_info_text, STRING_SIZE - 1);

    char ** agencies_info = (char **)calloc(0, sizeof(char *));
    size_t count_of_agencies = split(&agencies_info, agencies_info_text, "\n");

    struct LegalAgency * legal_agencies = (struct LegalAgency *)calloc(0, sizeof(struct LegalAgency));
    struct MarriageAgency * marriage_agencies = (struct MarriageAgency *)calloc(0, sizeof(struct MarriageAgency));

    size_t * legal_marriage_count = (size_t *)malloc(2 * sizeof(size_t));
    set_agencies(&legal_agencies, &marriage_agencies, agencies_info, count_of_agencies, legal_marriage_count);

    printf("%s\n", "Read data from text file complete");

    // end read data from text file

    // print legal agencies array on screen

    printf("%s\n", "Print legal agencies from text file");
    for (size_t i = 0; i < *legal_marriage_count; i++)
    {
        print_legal_agency(legal_agencies + i, stdout);
    }
    printf("%s\n", "Print legal agencies from text file complete");

    // end print legal agencies array on screen

    // write marriage agencies array to file

    printf("%s\n", "Write marriage agencies to text file");
    char * path_to_marriage_agencies_file = (char *)calloc(STRING_SIZE, sizeof(char));
    get_info_from_console(path_to_marriage_agencies_file, STRING_SIZE - 1, "Enter path to file for marriage agencies:");
    FILE * marriage_agencies_file = fopen(path_to_marriage_agencies_file, "w");
    for (size_t i = 0; i < *(legal_marriage_count + 1); i++)
    {
        print_marriage_agency((marriage_agencies + i), marriage_agencies_file);
    }
    free(path_to_marriage_agencies_file);
    fclose(marriage_agencies_file);
    printf("%s\n", "Write marriage agencies to text file complete");

    // end write marriage agencies array to file

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

    // write legal agencies binary

    printf("%s\n", "Write legal agencies binary");
    char * path_to_bin_file = "legal_agencies.bin";
    FILE * bin_file = fopen(path_to_bin_file, "wb");
    for (size_t i = 0; i < *legal_marriage_count; i++)
    {
        write_legal_agency_binary((legal_agencies + i), bin_file);
    }
    fclose(bin_file);
    printf("%s\n", "Write legal agencies binary complete");
    // end write legal agencies binary

    // read legal agencies from binary file and read by index

    printf("%s\n", "Read legal agencies binary");
    bin_file = fopen(path_to_bin_file, "rb");
    struct LegalAgency * legal_agencies_from_binary = (struct LegalAgency *)calloc(*legal_marriage_count, sizeof(struct LegalAgency));
    for (size_t i = 0; i < *legal_marriage_count; i++)
    {
        load_legal_agency_from_binary_by_index((legal_agencies_from_binary + i), bin_file, i);
    }
    fclose(bin_file);
    printf("%s\n", "Read legal agencies binary complete");

    // end read legal agencies from binary file and read by index

    free(agencies_info_text);

    for (size_t i = 0; i < count_of_agencies; i++)
    {
        free(*(agencies_info + i));
    }
    free(agencies_info);

    free(legal_marriage_count);
    free(legal_agencies);
    free(marriage_agencies);
    free(legal_agencies_from_binary);

    return 0;
}