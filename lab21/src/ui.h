#ifndef __UI_AGENCIES_LIST__
#define __UI_AGENCIES_LIST__

// #include "list.h"
// #include "data.h"

#include "agencies.h"
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

enum UIStates
{
    MainMenuUIState,
    PrintListToFileUIState,
    PrintListOnScreenUIState,
    ReadListFromFileUIState,
    SearchObjectByCityUIState,
    SortByYearsOnMarketUIState,
    AddElementToListUIState,
    DeleteElementFromListByIndex,
};

// size_t now_state = MainMenuUIState;

void get_info_from_console(char *to, size_t max_to_length, char *message);

// void command_handler(char * command);

void start();

void print_main_menu(char * command);
void print_list_to_file_menu(char * path_to_file);
void print_list_on_screen_menu();
void print_read_list_from_file_menu(char * path_to_file);
void print_search_object_by_city_menu(enum Cities * city, int * index);
void print_sort_by_years_on_market_menu();
void print_add_element_to_list_menu(struct Agency * agency, struct AgenciesList * agencies_list,int * index);
void print_delete_element_from_list_by_index_menu(int * index);


#endif