#ifndef _AGENCY_LAB15_
#define _AGENCY_LAB15_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 256
#define N 9

struct Person
{
    char surname[STRING_SIZE];
    char name[STRING_SIZE];
    char email[STRING_SIZE];
};

enum Cities
{
    Kharkiv,
    Kyiv,
    London,
    NumberOfCities
};

struct Agency
{
    bool is_weekends;
    char name[STRING_SIZE];
    size_t years_on_market;
    struct Person director;
    enum Cities city;
};

enum AgencyInfoFields
{
    SurnameField,
    NameField,
    EmailField,
    IsWeekendsField,
    AgencyNameField,
    YearsOnMarketField,
    CityField,
};

void set_person(struct Person *person, char *surname, char *name, char *email);

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city);


void get_info_from_console(char *to, size_t max_to_length, char *message);

void read_agencies_text_file(char *to, size_t max_to_length);

size_t split(char ***lexemes, char *string, char *delim);

void set_agencies(struct Agency ** agencies, char **agencies_info, size_t count_of_agencies);

size_t set_agency_info(char *** agency_info, char ** agencies_info, size_t agency_info_index);

void print_agency(struct Agency * agency, FILE * file);

void is_weekends_to_string(char **is_weekends_string, bool is_weekeds);
void cities_to_string(char **city_string, enum Cities city);

void generate_agency_info_text(size_t id, char * path_to_file);

void write_agency_binary(struct Agency * agency, FILE * file);
void load_agency_binary_by_index(struct Agency * agency, FILE * file, size_t index);

enum AgencySortingOptions
{
    YearsOnMarketOption, 
    CityOption,
    NumberOfAgencySortingOptions
};

void sort_agencies_by_options(struct Agency **agencies, size_t count_of_agencies, enum AgencySortingOptions agency_sorting_option);
size_t get_agencies_from_kharkiv_with_3_or_more_years_on_market(struct Agency *agencies, struct Agency ** geting_agencies, size_t count_of_agencies);

#endif