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

enum MarriageAgencyCountries
{
    Ukraine = 1,
    Poland = 2,
    Romania = 4,
    MaxBitMaskOfCountries = Ukraine + Poland + Romania 
};

struct MarriageAgency
{
    struct Agency main_info;
    enum MarriageAgencyServicesTypes service_type;
    size_t countries;
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
    CountriesField = 9
};

void set_person(struct Person *person, char *surname, char *name, char *email);

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city);

void set_legal_agency(struct LegalAgency *legal_agency, struct Agency main_info, enum LegalAgencyServicesTypes service_type, size_t number_of_succes_fees);

void set_marriage_agency(struct MarriageAgency *marriage_agency, struct Agency main_info, enum MarriageAgencyServicesTypes service_type, size_t countries);

void get_info_from_console(char *to, size_t max_to_length, char *message);

void read_agencies_text_file(char *to, size_t max_to_length);

size_t split(char ***lexemes, char *string, char *delim);

void set_agencies(struct LegalAgency **legal_agencies, struct MarriageAgency **marriage_agencies, char **agensies_info, size_t count_of_agencies, size_t * legal_and_marriage_number);

size_t get_number_of_agencies_by_type(enum AgencyTypes agency_type, char **agenсies_info, size_t count_of_agencies);

//void set_indices_of_agency_from_agensies_info_by_type(enum AgencyTypes agency_type, size_t * indices, char **agenсies_info, size_t count_of_agencies);

size_t set_agency_info(char *** agency_info, char ** agencies_info, size_t agency_info_index);

void print_legal_agency(struct LegalAgency * legal_agency, FILE * file);
void print_marriage_agency(struct MarriageAgency * marriage_agency, FILE * file);

void is_weekends_to_string(char **is_weekends_string, bool is_weekeds);
void cities_to_string(char **city_string, enum Cities city);

void legal_agency_service_type_to_string(char **service_type_string, enum LegalAgencyServicesTypes service_type);
void marriage_agency_service_type_to_string(char ** service_type_string, enum MarriageAgencyServicesTypes service_type);
void marriage_agency_countries_to_string(char ** countries_string, size_t countries);

void filter_legal_agencies_by_city(struct LegalAgency * legal_agencies, size_t number_of_legal_agencies,  struct LegalAgency ** legal_agencies_in_city, enum Cities city, size_t * count_of_legal_agencies_in_city);
void filter_marriage_agencies_by_city(struct MarriageAgency * marriage_agencies, size_t number_of_marriage_agencies, struct MarriageAgency ** marriage_agencies_in_city, enum Cities city, size_t * count_of_marriage_agencies_in_city);

//void sort_legal_agencies_by_succes_fees(struct LegalAgency ** legal_agencies, size_t number_of_legal_agencies);
void generate_agency_info_text(size_t id);

#endif