#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"
#include "stdbool.h"

#define STRING_SIZE 256

struct DynamicArray
{
    void * array;
    size_t length;
    size_t size_of_elements;
};

struct Person
{
    // char surname[STRING_SIZE];
    // char name[STRING_SIZE];
    // char email[STRING_SIZE];
    char * surname;
    char * name;
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
    // char name[STRING_SIZE];
    char *name;
    size_t years_on_market;
    struct Person director;
    enum Cities city;
};

void set_person(struct Person *person, char *surname, char *name, char *email);
void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city);
void print_agency(struct Agency *agency, FILE *file);
void is_weekends_to_string(char **is_weekends_string, bool is_weekeds);
void cities_to_string(char **city_string, enum Cities city);

void init_dynamic_array(struct DynamicArray * dynamic_array, size_t size_of_elements);
void free_dynamic_array(struct DynamicArray *dynamic_array);
void insert(struct DynamicArray * dynamic_array, void * inserted_data, size_t count_of_elements, size_t from_index);
void reduce(struct DynamicArray * dynamic_array, size_t start_index, size_t end_index);
void print_dynamic_char_array(struct DynamicArray *dynamic_array, FILE * file);



#endif