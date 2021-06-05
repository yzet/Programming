#ifndef __AGENCIES_DATA__
#define __AGENCIES_DATA__

/**
 * @file data.h
 * @brief Файл з описом структури агенств, перерахуванням міст та функцій
 * оперування агенствами
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

#define STRING_SIZE 256

#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    // char surname[STRING_SIZE];
    // char name[STRING_SIZE];
    // char email[STRING_SIZE];
    char * surname;
    char * name;
    char * email;
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
    // char  name[STRING_SIZE];
    char * name;
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
void print_agency(struct Agency *agency, FILE *file);
void is_weekends_to_string(char **is_weekends_string, bool is_weekeds);
void cities_to_string(char **city_string, enum Cities city);
void write_agency_data(struct Agency *agency, FILE * file);

int agencies_cmp_by_years_on_market(struct Agency *agency1, struct Agency *agency2);
void read_agencies_text_file(char *to, size_t max_to_length, char *path_to_file_with_data);
size_t split(char ***lexemes, char *string, char *delim);
size_t set_agency_info(char ***agency_info, char **agencies_info, size_t agency_info_index);


#endif