#include "lib.h"

void set_person(struct Person *person, char *surname, char *name, char *email)
{
    person->surname = surname;
    person->name = name;
    person->email = email;
}

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city)
{
    agency->is_weekends = is_weakends;
    agency->name = agency_name;
    agency->years_on_market = years_on_market;
    agency->director = agency_director;
    agency->city = city;
}

void set_legal_agency(struct LegalAgency *legal_agency, struct Agency main_info, enum LegalAgencyServicesTypes service_type, size_t number_of_succes_fees)
{
    legal_agency->main_info = main_info;
    legal_agency->service_type = service_type;
    legal_agency->number_of_success_fees = number_of_succes_fees;
}

void set_marriage_agency(struct MarriageAgency *marriage_agency, struct Agency main_info, enum MarriageAgencyServicesTypes service_type, enum MarriageAgencyCountryies *countries, size_t count_of_countries)
{
    marriage_agency->main_info = main_info;
    marriage_agency->service_type = service_type;
    marriage_agency->service_type = 0;
    for (size_t i = 0; i < count_of_countries; i++)
        marriage_agency->service_type += *(countries + i);
}

void get_info_from_console(char *to, size_t max_to_length, char *message)
{
    puts(message);
    fgets(to, (int)max_to_length, stdin);
    to = strtok(to, "\n");
}

void read_agencies_text_file(char *to, size_t max_to_length)
{
    char *path_to_file = (char *)calloc(STRING_SIZE, sizeof(char));

    //get_info_from_console(path_to_file, STRING_SIZE - 1, "Enter path to agencies text file");
    strcpy(path_to_file, "agencies.txt");

    FILE *agencies_text_file = fopen(path_to_file, "r");
    if (agencies_text_file == NULL)
    {
        puts("Unable file");
        exit(1);
    }

    char *buff = (char *)calloc(STRING_SIZE, sizeof(char));

    while (fgets(buff, STRING_SIZE - 1, agencies_text_file) != NULL)
    {
        max_to_length -= strlen(buff);
        if (max_to_length < 0)
        {
            puts("File text did not fit(read_agencies_text_file)");
            break;
        }
        else
        {
            strcat(to, buff);
        }
    }

    free(path_to_file);
    free(buff);
}

size_t split(char ***lexemes, char *string, char *delim)
{
    char *string_copy = (char *)calloc(strlen(string) + 1, sizeof(char));
    strcpy(string_copy, string);

    size_t count_of_lexemes = 1;
    for (size_t symbol_index = 0; symbol_index < strlen(string); symbol_index++)
    {
        char buff[2];
        buff[0] = string[symbol_index];
        buff[1] = '\0';
        if (strcmp(buff, delim) == 0)
            count_of_lexemes++;
    }

    free(*lexemes);
    *lexemes = (char **)calloc(count_of_lexemes, sizeof(char *));

    char *lexem = strtok(string_copy, delim);

    size_t lexem_index = 0;

    while (lexem != NULL)
    {
        *(*(lexemes) + lexem_index) = (char *)calloc(strlen(lexem) + 1, sizeof(char));
        strcpy(*(*(lexemes) + lexem_index), lexem);
        lexem_index++;
        lexem = strtok(NULL, delim);
    }

    free(string_copy);

    return count_of_lexemes;
}

void set_agencies(struct LegalAgency ***legal_agencies, struct MarriageAgency ***marriage_agencies, char **agensies_info, size_t count_of_agencies)
{
    size_t legal_agencies_number = get_number_of_agencies_by_type(Legal, agensies_info, count_of_agencies);
    size_t marriage_agencies_number = get_number_of_agencies_by_type(Marriage, agensies_info, count_of_agencies);

    free(*legal_agencies);
    free(*marriage_agencies);

    *legal_agencies = (struct LegalAgency **)calloc(legal_agencies_number, sizeof(struct LegalAgency *));
    *marriage_agencies = (struct MarriageAgency **)calloc(marriage_agencies_number, sizeof(struct MarriageAgency *));

    size_t * legal_agency_indices = (size_t *)malloc(legal_agencies_number);
    size_t * marriage_agency_indices = (size_t *)malloc(marriage_agencies_number);

    set_indices_of_agency_from_agensies_info_by_type(Legal, legal_agency_indices, agensies_info, count_of_agencies);
    set_indices_of_agency_from_agensies_info_by_type(Marriage, marriage_agency_indices, agensies_info, count_of_agencies);

    
    
}

size_t get_number_of_agencies_by_type(enum AgencyTypes agency_type, char **agenсies_info, size_t count_of_agencies)
{
    //char ** agency_info = (char **)calloc(0, sizeof(char *));
    const size_t agency_type_index = 7;
    size_t number_of_agencies_by_type = 0;

    for (size_t agency_index = 0; agency_index < count_of_agencies; agency_index++)
    {
        char ** agency_info = (char **)calloc(0, sizeof(char *));
        size_t count_of_fields = split(&agency_info, *(agenсies_info + agency_index), " ");
        if (strtol( *(agency_info + agency_type_index), NULL, 10) == agency_type)
        {
            number_of_agencies_by_type++;
        }
        for (size_t i = 0; i < count_of_fields; i++)
        {
            free(*(agency_info + i));
        }
        free(agency_info);
    }

    return number_of_agencies_by_type;
}

void set_indices_of_agency_from_agensies_info_by_type(enum AgencyTypes agency_type, size_t * indices, char **agenсies_info, size_t count_of_agencies)
{
    const size_t agency_type_index = 7;
    size_t indices_index = 0;

    for (size_t agency_index = 0; agency_index < count_of_agencies; agency_index++)
    {
        char ** agency_info = (char **)calloc(0, sizeof(char *));
        size_t count_of_fields = split(&agency_info, *(agenсies_info + agency_index), " ");
        if (strtol( *(agency_info + agency_type_index), NULL, 10) == agency_type)
        {
            *(indices + indices_index) = agency_index;
        }
        for (size_t i = 0; i < count_of_fields; i++)
        {
            free(*(agency_info + i));
        }
        free(agency_info);
    }
}

