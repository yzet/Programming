#include "data.h"
#include <stdio.h>

void set_person(struct Person *person, char *surname, char *name, char *email)
{
    // strcpy(person->surname, surname);
    // strcpy(person->name, name);
    // strcpy(person->email, email);
    person->surname = surname;
    person->name = name;
    person->email = email;

}

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city)
{
    agency->is_weekends = is_weakends;
    agency->name = agency_name;
    // strcpy(agency->name, agency_name);
    agency->years_on_market = years_on_market;
    agency->director = agency_director;
    agency->city = city;
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

int agencies_cmp_by_years_on_market(struct Agency *agency1, struct Agency *agency2)
{
    int result = -2;
    if (agency1->years_on_market > agency2->years_on_market) result = 1;
    else if (agency1->years_on_market == agency2->years_on_market) result = 0;
    else if (agency1->years_on_market < agency2->years_on_market) result = -1;
    return result;
}

void read_agencies_text_file(char *to, size_t max_to_length)
{
    int max_to_length_check = (int)max_to_length;
    char *path_to_file = (char *)calloc(STRING_SIZE, sizeof(char));

    // get_info_from_console(path_to_file, STRING_SIZE - 1, "Enter path to agencies text file");
    strcpy(path_to_file, "./data_files/agencies.txt");

    FILE *agencies_text_file = fopen(path_to_file, "r");
    if (agencies_text_file == NULL)
    {
        puts("Unable file");
        exit(1);
    }

    // char *buff = (char *)calloc(1, sizeof(char));
    char buff;



    // while (fgets(buff, STRING_SIZE - 1, agencies_text_file) != NULL)
    // {
    //     max_to_length_check -= strlen(buff);
    //     if (max_to_length_check < 0)
    //     {
    //         puts("File text did not fit(read_agencies_text_file)");
    //         break;
    //     }
    //     else
    //     {
    //         strcat(to, buff);
    //     }
    // }
    size_t last_index_in_to = 0;
    while (fscanf(agencies_text_file, "%c", &buff) != EOF)
    {
        max_to_length--;
        if (max_to_length_check < 0)
        {
            puts("File text did not fit(read_agencies_text_file)");
            break;
        }
        else
        {
            *(to + last_index_in_to) = buff;
        }
        last_index_in_to++;
    } 
    fclose(agencies_text_file);
    free(path_to_file);
    // free(buff);
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

void write_agency_data(struct Agency *agency, FILE * file)
{
    fprintf(file ,"%s;%s;%s;%i;", agency->director.surname, agency->director.name, agency->director.email, agency->is_weekends);
    fputs(agency->name, file);
    fputc(';', file);
    fprintf(file, "%i;%i", (int)agency->years_on_market, agency->city);
}

size_t set_agency_info(char ***agency_info, char **agencies_info, size_t agency_info_index)
{
    return split(agency_info, *(agencies_info + agency_info_index), ";");
}