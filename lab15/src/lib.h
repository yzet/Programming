#ifndef _AGENCY_LAB15_
#define _AGENCY_LAB15_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 256

struct Person
{
    char *surname;
    char *name;
    char *email;
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
    char *name;
    size_t years_on_market;
    struct Person director;
    enum Cities city;
};

enum AgencyTypes
{
    Legal,
    Marriage
};

enum LegalAgencyServicesTypes
{
    DivorceConsultation,
    DefenseInCourt,
    NumberOfLegalAgencyServices
};

struct LegalAgency
{
    struct Agency main_info;
    enum LegalAgencyServicesTypes service_type;
    size_t number_of_success_fees;
};

enum MarriageAgencyServicesTypes
{
    MailingOrganization,
    DatingOrganization,
    NumberOfMarriageAgencyServices
};

enum MarriageAgencyCountryies
{
    Ukraine = 1,
    Poland = 2,
    Romania = 4
};

struct MarriageAgency
{
    struct Agency main_info;
    enum MarriageAgencyServicesTypes service_type;
    size_t countryies;
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
    AgencyTypeField,
    ServiceTypeField,
    NumberOfSuccesFeesField,
    CountOfCountriesField = 9,
    CountriesFirstField
};

void set_person(struct Person *person, char *surname, char *name, char *email);

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city);

void set_legal_agency(struct LegalAgency *legal_agency, struct Agency main_info, enum LegalAgencyServicesTypes service_type, size_t number_of_succes_fees);

void set_marriage_agency(struct MarriageAgency *marriage_agency, struct Agency main_info, enum MarriageAgencyServicesTypes service_type, enum MarriageAgencyCountryies *countries, size_t count_of_countries);

void get_info_from_console(char *to, size_t max_to_length, char *message);

void read_agencies_text_file(char *to, size_t max_to_length);

size_t split(char ***lexemes, char *string, char *delim);

void set_agencies(struct LegalAgency ***legal_agencies, struct MarriageAgency ***marriage_agencies, char **agensies_info, size_t count_of_agencies);

size_t get_number_of_agencies_by_type(enum AgencyTypes agency_type, char **agenсies_info, size_t count_of_agencies);

void set_indices_of_agency_from_agensies_info_by_type(enum AgencyTypes agency_type, size_t * indices, char **agenсies_info, size_t count_of_agencies);

size_t set_agency_info(char *** agency_info, char ** agencies_info, size_t agency_info_index);

#endif