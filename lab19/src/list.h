#ifndef __AGENCIES_LIST__
#define __AGENCIES_LIST__

#include "data.h"
#include "stdlib.h"
#include "memory.h"

struct AgenciesListElement
{
    struct AgenciesListElement * next;
    struct AgenciesListElement * prev;
    struct Agency data;
};

struct AgenciesList
{
    struct AgenciesListElement * head;
    struct AgenciesListElement *tail;
};

int init_agencies_list(struct AgenciesList *agencies_list);
int add_element_to_list_by_index(struct AgenciesList *agencies_list, struct Agency *element, size_t index);
int add_element_to_list_end(struct AgenciesList *agencies_list, struct Agency *element);
int delete_element_from_list_by_index(struct AgenciesList *agencies_list, size_t index);
int get_element_by_index(struct AgenciesList *agencies_list, struct AgenciesListElement **element, size_t index);
size_t get_list_length(struct AgenciesList *agencies_list);
int sort_agencies_list_by_years_on_market(struct AgenciesList *agencies_list);
int get_element_with_city_from_index(struct AgenciesList *agencies_list, size_t from_index, enum Cities city, struct AgenciesListElement **element);

void print_agencies_list_to_file(struct AgenciesList *agencies_list, FILE * file);
void print_agencies_list_on_screen(struct AgenciesList *agencies_list);
void print_agencies_list_on_screen_reverse(struct AgenciesList *agencies_list);

int set_agencies_list_from_text_array(struct AgenciesList *agencies_list, char ** agencies_text_array, size_t count_of_agencies);

int free_agencies_list(struct AgenciesList *agencies_list);



#endif