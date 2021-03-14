#include "lib.h"

void set_person(struct Person *person, char *surname, char *name, char *email)
{
    strcpy(person->surname, surname);
    strcpy(person->name, name);
    strcpy(person->email, email);
}

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city)
{
    agency->is_weekends = is_weakends;
    // agency->name = agency_name;
    strcpy(agency->name, agency_name);
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

void set_marriage_agency(struct MarriageAgency *marriage_agency, struct Agency main_info, enum MarriageAgencyServicesTypes service_type, size_t countries)
{
    marriage_agency->main_info = main_info;
    marriage_agency->service_type = service_type;
    marriage_agency->countries = countries;
}

void get_info_from_console(char *to, size_t max_to_length, char *message)
{
    puts(message);
    fgets(to, (int)max_to_length, stdin);
    to = strtok(to, "\n");
}

void read_agencies_text_file(char *to, size_t max_to_length)
{
    int max_to_length_check = (int)max_to_length;
    char *path_to_file = (char *)calloc(STRING_SIZE, sizeof(char));

    get_info_from_console(path_to_file, STRING_SIZE - 1, "Enter path to agencies text file");
    // strcpy(path_to_file, "agencies.txt");

    FILE *agencies_text_file = fopen(path_to_file, "r");
    if (agencies_text_file == NULL)
    {
        puts("Unable file");
        exit(1);
    }

    char *buff = (char *)calloc(STRING_SIZE, sizeof(char));

    while (fgets(buff, STRING_SIZE - 1, agencies_text_file) != NULL)
    {
        max_to_length_check -= strlen(buff);
        if (max_to_length_check < 0)
        {
            puts("File text did not fit(read_agencies_text_file)");
            break;
        }
        else
        {
            strcat(to, buff);
        }
    }

    fclose(agencies_text_file);
    free(path_to_file);
    free(buff);
}

size_t split(char ***lexemes, char *string, char *delim)
{
    char *string_copy = (char *)calloc(strlen(string) + 1, sizeof(char));
    strcpy(string_copy, string);

    size_t count_of_lexemes = 1;
    size_t string_length = strlen(string);
    for (size_t symbol_index = 0; symbol_index < string_length; symbol_index++)
    {
        char buff[2];
        buff[0] = string[symbol_index];
        buff[1] = '\0';
        if (strcmp(buff, delim) == 0 && symbol_index != string_length - 1)
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

void set_agencies(struct LegalAgency **legal_agencies, struct MarriageAgency **marriage_agencies, char **agensies_info, size_t count_of_agencies, size_t *legal_and_marriage_number)
{
    size_t legal_agencies_number = get_number_of_agencies_by_type(Legal, agensies_info, count_of_agencies);
    size_t marriage_agencies_number = get_number_of_agencies_by_type(Marriage, agensies_info, count_of_agencies);

    *(legal_and_marriage_number) = legal_agencies_number;
    *(legal_and_marriage_number + 1) = marriage_agencies_number;

    free(*legal_agencies);
    free(*marriage_agencies);

    *legal_agencies = (struct LegalAgency *)calloc(legal_agencies_number, sizeof(struct LegalAgency));
    *marriage_agencies = (struct MarriageAgency *)calloc(marriage_agencies_number, sizeof(struct MarriageAgency));

    const size_t agency_type_index = 7;
    size_t legal_agency_index = 0;
    size_t marriage_agency_index = 0;
    for (size_t agency_index = 0; agency_index < count_of_agencies; agency_index++)
    {
        char **agency_info = (char **)calloc(0, sizeof(char *));
        size_t numbers_of_characteristics = set_agency_info(&agency_info, agensies_info, agency_index);
        struct Person director;
        set_person(&director, *(agency_info + SurnameField), *(agency_info + NameField), *(agency_info + EmailField));
        struct Agency agency;
        bool is_weekends = false;
        if (strtol(*(agency_info + IsWeekendsField), NULL, 10) == 1)
            is_weekends = true;
        set_agency(&agency, is_weekends, *(agency_info + AgencyNameField), (size_t)strtol(*(agency_info + YearsOnMarketField), NULL, 10), director, (unsigned int)strtol(*(agency_info + CityField), NULL, 10));

        if (strtol(*(agency_info + agency_type_index), NULL, 10) == Legal)
        {
            struct LegalAgency legal_agency;
            set_legal_agency(&legal_agency, agency, (unsigned int)strtol(*(agency_info + ServiceTypeField), NULL, 10), (size_t)strtol(*(agency_info + NumberOfSuccesFeesField), NULL, 10));
            memcpy((*legal_agencies) + legal_agency_index, &legal_agency, sizeof(struct LegalAgency));
            legal_agency_index++;
        }
        else if (strtol(*(agency_info + agency_type_index), NULL, 10) == Marriage)
        {
            struct MarriageAgency marriage_agency;
            set_marriage_agency(&marriage_agency, agency, (unsigned int)strtol(*(agency_info + ServiceTypeField), NULL, 10), (unsigned int)strtol(*(agency_info + CountriesField), NULL, 10));
            memcpy((*marriage_agencies) + marriage_agency_index, &marriage_agency, sizeof(struct MarriageAgency));
            marriage_agency_index++;
        }

        for (size_t i = 0; i < numbers_of_characteristics; i++)
        {
            free(*(agency_info + i));
        }
        free(agency_info);
    }
}

size_t get_number_of_agencies_by_type(enum AgencyTypes agency_type, char **agenсies_info, size_t count_of_agencies)
{
    //char ** agency_info = (char **)calloc(0, sizeof(char *));
    const size_t agency_type_index = 7;
    size_t number_of_agencies_by_type = 0;

    for (size_t agency_index = 0; agency_index < count_of_agencies; agency_index++)
    {
        char **agency_info = (char **)calloc(0, sizeof(char *));
        size_t count_of_fields = split(&agency_info, *(agenсies_info + agency_index), " ");
        if (strtol(*(agency_info + agency_type_index), NULL, 10) == agency_type)
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

size_t set_agency_info(char ***agency_info, char **agencies_info, size_t agency_info_index)
{
    return split(agency_info, *(agencies_info + agency_info_index), " ");
}

void print_legal_agency(struct LegalAgency *legal_agency, FILE *file)
{
    char *output = (char *)calloc(2 * STRING_SIZE, sizeof(char));

    char *is_weekends_string = (char *)calloc(STRING_SIZE, sizeof(char));
    is_weekends_to_string(&is_weekends_string, legal_agency->main_info.is_weekends);

    char *city_string = (char *)calloc(STRING_SIZE, sizeof(char));
    cities_to_string(&city_string, legal_agency->main_info.city);

    char *service_type_string = (char *)calloc(STRING_SIZE, sizeof(char));
    legal_agency_service_type_to_string(&service_type_string, legal_agency->service_type);

    sprintf(output, "Agency Name: %s\nAgency type: Legal agency\nDirector: %s %s Email: %s\nWeekends: %s\nYears on market: %d\nCity: %s\nService type: %s\nNumber of success fees: %d\n\n",
            legal_agency->main_info.name, legal_agency->main_info.director.name, legal_agency->main_info.director.surname, legal_agency->main_info.director.email,
            is_weekends_string, (int)legal_agency->main_info.years_on_market, city_string, service_type_string, (int)legal_agency->number_of_success_fees);

    fputs(output, file);

    free(is_weekends_string);
    free(city_string);
    free(service_type_string);
    free(output);
}

void print_marriage_agency(struct MarriageAgency *marriage_agency, FILE *file)
{
    char *output = (char *)calloc(2 * STRING_SIZE, sizeof(char));

    char *is_weekends_string = (char *)calloc(STRING_SIZE, sizeof(char));
    is_weekends_to_string(&is_weekends_string, marriage_agency->main_info.is_weekends);

    char *city_string = (char *)calloc(STRING_SIZE, sizeof(char));
    cities_to_string(&city_string, marriage_agency->main_info.city);

    char *service_type_string = (char *)calloc(STRING_SIZE, sizeof(char));
    marriage_agency_service_type_to_string(&service_type_string, marriage_agency->service_type);

    char *countries_string = (char *)calloc(STRING_SIZE, sizeof(char));
    marriage_agency_countries_to_string(&countries_string, marriage_agency->countries);

    sprintf(output, "Agency Name: %s\nAgency type: Marriage agency\nDirector: %s %s Email: %s\nWeekends: %s\nYears on market: %d\nCity: %s\nService type: %s\nCountries: %s\n\n",
            marriage_agency->main_info.name, marriage_agency->main_info.director.name, marriage_agency->main_info.director.surname, marriage_agency->main_info.director.email,
            is_weekends_string, (int)marriage_agency->main_info.years_on_market, city_string, service_type_string, countries_string);

    fputs(output, file);

    free(countries_string);
    free(service_type_string);
    free(city_string);
    free(is_weekends_string);
    free(output);
}

void is_weekends_to_string(char **is_weekends_string, bool is_weekeds)
{
    if (is_weekeds)
    {
        strcpy(*is_weekends_string, "Yes");
    }
    else
    {
        strcpy(*is_weekends_string, "No");
    }
}

void cities_to_string(char **city_string, enum Cities city)
{
    switch (city)
    {
    case Kharkiv:
        strcpy(*city_string, "Kharkiv");
        break;
    case Kyiv:
        strcpy(*city_string, "Kyiv");
        break;
    case London:
        strcpy(*city_string, "London");
        break;
    default:
        break;
    }
}

void legal_agency_service_type_to_string(char **service_type_string, enum LegalAgencyServicesTypes service_type)
{
    switch (service_type)
    {
    case DivorceConsultation:
        strcpy(*service_type_string, "Divorce consultation");
        break;
    case DefenseInCourt:
        strcpy(*service_type_string, "Defense in court");
        break;
    default:
        break;
    }
}

void marriage_agency_service_type_to_string(char **service_type_string, enum MarriageAgencyServicesTypes service_type)
{
    switch (service_type)
    {
    case MailingOrganization:
        strcpy(*service_type_string, "Mailing organization");
        break;
    case DatingOrganization:
        strcpy(*service_type_string, "Dating organization");
        break;
    default:
        break;
    }
}

void marriage_agency_countries_to_string(char **countries_string, size_t countries)
{
    if ((countries & Ukraine) != 0)
        strcat(*countries_string, "Ukraine ");
    if ((countries & Poland) != 0)
        strcat(*countries_string, "Poland ");
    if ((countries & Romania) != 0)
        strcat(*countries_string, "Romania");
}

void generate_agency_info_text(size_t id, char * path_to_file)
{

    FILE * file = fopen(path_to_file, "a");
    if (file == NULL)
    {
        puts("File not available");
        exit(1);
    }

    char * buff = (char *)calloc(STRING_SIZE, sizeof(char));

    char * surname = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(surname, "Surname#");
    sprintf(buff, "%d", (int)id);
    strcat(surname, buff);

    char * name = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(name, "Name#");
    strcat(name, buff);

    char * email = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(email, "Email#");
    strcat(email, buff);
    
    char * agency_name = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(agency_name, "AgencyName#");
    strcat(agency_name, buff);

    int is_weekends = rand() % 2;
    int years_on_market = rand() % (N * 10 - N) + N;
    int city = rand() % NumberOfCities;
    int agency_type = rand() % 2;
    int service_type = rand() % NumberOfLegalAgencyServices;
    int number_of_success_fees =  rand() % (N * 10 - N + 1) + N;
    int countries_bit_mask = rand() % MaxBitMaskOfCountries + 1;

    fprintf(file, "%s %s %s %d %s %d %d %d %d ", surname, name, email, is_weekends, agency_name, years_on_market, city, agency_type, service_type);
    if (agency_type == 0)
        fprintf(file, "%d", number_of_success_fees);
    else
        fprintf(file, "%d", countries_bit_mask);

    free(agency_name);
    free(email);
    free(name);
    free(surname);
    free(buff);
    fclose(file);
    // free(path_to_file);
}

void write_legal_agency_binary(struct LegalAgency * legal_agency, FILE * bin_file)
{
    fwrite(legal_agency, sizeof(*legal_agency), 1, bin_file);
}

void write_marriage_agency_binary(struct MarriageAgency * marriage_agency, FILE * bin_file)
{
    fwrite(marriage_agency, sizeof(*marriage_agency), 1, bin_file);
}

void load_legal_agency_from_binary_by_index(struct LegalAgency * legal_agency, FILE * bin_file, size_t index)
{
    fseek(bin_file, (long)(sizeof(*legal_agency) * index), SEEK_SET);
    fread(legal_agency, sizeof(*legal_agency), 1, bin_file);
}

void load_marriage_agency_from_binary_by_index(struct MarriageAgency * marriage_agency, FILE * bin_file, size_t index)
{
    fseek(bin_file, (long)(sizeof(*marriage_agency) * index), SEEK_SET);
    fread(marriage_agency, sizeof(*marriage_agency), 1, bin_file);
}