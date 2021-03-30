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

    // get_info_from_console(path_to_file, STRING_SIZE - 1, "Enter path to agencies text file");
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

void set_agencies(struct Agency **agencies, char **agencies_info, size_t count_of_agencies)
{
    free(*agencies);
    *(agencies) = (struct Agency *)calloc(count_of_agencies, sizeof(struct Agency));

    for (size_t agency_index = 0; agency_index < count_of_agencies; agency_index++)
    {
        char **agency_info = (char **)calloc(0, sizeof(char *));
        size_t number_of_characteristic = set_agency_info(&agency_info, agencies_info, agency_index);
        struct Person director;
        set_person(&director, *(agency_info + SurnameField), *(agency_info + NameField), *(agency_info + EmailField));
        bool is_weekends = false;
        if (strtol(*(agency_info + IsWeekendsField), NULL, 10) == 1)
            is_weekends = true;
        struct Agency new_agency;
        set_agency(&new_agency, is_weekends, *(agency_info + AgencyNameField), (size_t)strtol(*(agency_info + YearsOnMarketField), NULL, 10), director, (unsigned int)strtol(*(agency_info + CityField), NULL, 10));
        memcpy((*agencies) + agency_index, &new_agency, sizeof(struct Agency));
        for (size_t i = 0; i < number_of_characteristic; i++)
        {
            free(*(agency_info + i));
        }
        free(agency_info);
    }
}

size_t set_agency_info(char ***agency_info, char **agencies_info, size_t agency_info_index)
{
    return split(agency_info, *(agencies_info + agency_info_index), ";");
}


void print_agency(struct Agency *agency, FILE *file)
{
    char *output = (char *)calloc(2 * STRING_SIZE, sizeof(char));

    char *is_weekends_string = (char *)calloc(STRING_SIZE, sizeof(char));
    is_weekends_to_string(&is_weekends_string, agency->is_weekends);

    char *city_string = (char *)calloc(STRING_SIZE, sizeof(char));
    cities_to_string(&city_string, agency->city);

    sprintf(output, "Agency Name: %s\nDirector: %s %s Email: %s\nWeekends: %s\nYears on market: %d\nCity: %s\n",
            agency->name, agency->director.name, agency->director.surname, agency->director.email,
            is_weekends_string, (int)agency->years_on_market, city_string);

    fputs(output, file);

    free(is_weekends_string);
    free(city_string);
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



void generate_agency_info_text(size_t id, char *path_to_file)
{

    FILE *file = fopen(path_to_file, "a");
    if (file == NULL)
    {
        puts("File not available");
        exit(1);
    }

    char *buff = (char *)calloc(STRING_SIZE, sizeof(char));

    char *surname = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(surname, "Surname#");
    sprintf(buff, "%d", (int)id);
    strcat(surname, buff);

    char *name = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(name, "Name#");
    strcat(name, buff);

    char *email = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(email, "Email#");
    strcat(email, buff);

    char *agency_name = (char *)calloc(STRING_SIZE, sizeof(char));
    strcat(agency_name, "AgencyName#");
    strcat(agency_name, buff);

    int is_weekends = rand() % 2;
    int years_on_market = rand() % (N * 10 - N) + N;
    int city = rand() % NumberOfCities;

    fprintf(file, "%s;%s;%s;%d;%s;%d;%d", surname, name, email, is_weekends, agency_name, years_on_market, city);
  

    free(agency_name);
    free(email);
    free(name);
    free(surname);
    free(buff);
    fclose(file);
}

void write_agency_binary(struct Agency *agency, FILE *file)
{
    fwrite(agency, sizeof(*agency), 1, file);
}

void load_agency_binary_by_index(struct Agency *agency, FILE *file, size_t index)
{
    fseek(file, (long)(sizeof(*agency) * index), SEEK_SET);
    fread(agency, sizeof(*agency), 1, file);
}

void sort_agencies_by_options(struct Agency **agencies, size_t count_of_agencies, enum AgencySortingOptions agency_sorting_option)
{
    switch (agency_sorting_option)
    {
    case YearsOnMarketOption:
        for (size_t i = 0; i < count_of_agencies; i++)
        {
            for (size_t j = 0; j < (count_of_agencies - 1); j++)
            {
                if ((*agencies + j)->years_on_market > ((*agencies + j + 1))->years_on_market)
                {
                    struct Agency buff;
                    memcpy(&buff, (*agencies + j), sizeof(struct Agency));
                    memcpy(*agencies + j, *agencies + j + 1, sizeof(struct Agency));
                    memcpy(*agencies + j + 1, &buff, sizeof(struct Agency));
                }
            }
        }
        break;
    case CityOption:
        for (size_t i = 0; i < count_of_agencies; i++)
        {
            for (size_t j = 0; j < (count_of_agencies - 1); j++)
            {
                char *city_name_left = (char *)calloc(STRING_SIZE, sizeof(char));
                cities_to_string(&city_name_left, (*agencies + j)->city);
                char *city_name_right = (char *)calloc(STRING_SIZE, sizeof(char));
                cities_to_string(&city_name_right, (*agencies + j + 1)->city);
                if (strcmp(city_name_left, city_name_right) > 0)
                {
                    struct Agency buff;
                    memcpy(&buff, (*agencies + j), sizeof(struct Agency));
                    memcpy(*agencies + j, *agencies + j + 1, sizeof(struct Agency));
                    memcpy(*agencies + j + 1, &buff, sizeof(struct Agency));
                }
                free(city_name_left);
                free(city_name_right);
            }
        }
        break;
    default:
        break;
    }
}

size_t get_agencies_from_kharkiv_with_3_or_more_years_on_market(struct Agency *agencies, struct Agency **geting_agencies, size_t count_of_agencies)
{
    free(*geting_agencies);
    size_t geting_agencies_count = 0;
    for (size_t i = 0; i < count_of_agencies; i++)
    {
        if ((agencies + i)->city == Kharkiv && (agencies + i)->years_on_market >= 3)
        {
            geting_agencies_count++;
        }
    }

    (*geting_agencies) = (struct Agency *)calloc(geting_agencies_count, sizeof(struct Agency));
    size_t geting_agencies_last_index = 0;

    for (size_t i = 0; i < count_of_agencies; i++)
    {
        if ((agencies + i)->city == Kharkiv && (agencies + i)->years_on_market >= 3)
        {
            memcpy((*geting_agencies) + geting_agencies_last_index, (agencies + i), sizeof(struct Agency));
            geting_agencies_last_index++;
        }
    }
    return geting_agencies_count;
}