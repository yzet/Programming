#ifndef __UI_AGENCIES_LIST__
#define __UI_AGENCIES_LIST__

/**
 * @file ui.h
 * @brief Файл з описом функцій для роботи з діалоговим режимом
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include <string.h>
#include "data.h"
#include <string.h>
#include <ctype.h>
#include "list.h"
#include <stdio.h>

/**
 * Перелік станів діалогового режиму
 */
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

/**
 * Функція зчитування даних з файлу
 *
 * Функція зчитує файл і записує його вміст у строку
 * @param to строка для запису вмісту
 * @param max_to_length максимальна довжина вмісту
 */
void get_info_from_console(char *to, size_t max_to_length, char *message);

// void command_handler(char * command);

/**
 * Функція запуску діалогового режиму
 *
 * Функція є точкою входу для запуску діалогового режиму, контролює запуск меню і обробляє команди
 */
void start();

/**
 * Функція виведення початкового меню
 *
 * Функція виводить початкове меню і отримує команду
 * @param command змінна для збереження команди
 */
void print_main_menu(char * command);
/**
 * Функція виведення меню запису списку у файл
 *
 * Функція виводить меню і отримує шлях до файлу виведення
 * @param path_to_file змінна для збереження шляху до файлу
 */
void print_list_to_file_menu(char * path_to_file);
/**
 * Функція виведення меню виведення списку на екран
 *
 * Функція виводить меню
 */
void print_list_on_screen_menu();
/**
 * Функція виведення меню зчитування списку з файлу
 *
 * Функція виводить меню і отримує шлях до файлу введення
 * @param path_to_file змінна для збереження шляху до файлу
 */
void print_read_list_from_file_menu(char * path_to_file);
/**
 * Функція виведення меню для пошуку
 *
 * Функція виводить меню, запитує місто та початковий індекс для пошуку
 * @param city змінна для збереження міста
 * @param index змінна початку пошуку
 */
void print_search_object_by_city_menu(enum Cities * city, int * index);
/**
 * Функція виведення меню для сортування
 *
 * Функція виводить меню
 */
void print_sort_by_years_on_market_menu();
/**
 * Функція виведення меню для додавання елемента
 *
 * Функція виводить меню, значення для агенства, та індекс, додає агенство до зв'язного списку
 * @param agency змінна для збереження агенства
 * @param agencies_list зв'язний список
 * @param index змінна для індексу
 */
void print_add_element_to_list_menu(struct Agency * agency, struct AgenciesList * agencies_list,int * index);
/**
 * Функція виведення меню для видалення елемента
 *
 * Функція виводить меню, запитує індекс для видалення елементу
 * @param index змінна для збереження індексу
 */
void print_delete_element_from_list_by_index_menu(int * index);


#endif