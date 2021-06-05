#ifndef __AGENCIES_LIST__
#define __AGENCIES_LIST__

/**
 * @file list.h
 * @brief Файл з описом функцій для роботи зі списком
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include "data.h"
#include "stdlib.h"
#include "memory.h"

/**
 * Структура "Елемент зв'язкового список"
 */
struct AgenciesListElement
{
    struct AgenciesListElement * next;
    struct AgenciesListElement * prev;
    struct Agency data;
};

/**
 * Структура "Зв'язковий список"
 */
struct AgenciesList
{
    struct AgenciesListElement * head;
    struct AgenciesListElement *tail;
};

/**
 * Функція ініціалізації AgenciesList
 *
 * Функція втановлює значення полів для змінних типу Agencies List
 * @param agencies_list вказівник на зв'язковий список
 * @return 0 при вдалому виконанні
 */
int init_agencies_list(struct AgenciesList *agencies_list);
/**
 * Функція додавання до AgenciesList
 *
 * Функція додає елементи до AgenciesList за заданим індексом
 * @param agencies_list вказівник на зв'язковий масив
 * @param element вказівник на данні для вставки
 * @param index індекс вставденого елементу
 * @return 0 при вдалому виконанні
 */
int add_element_to_list_by_index(struct AgenciesList *agencies_list, struct Agency *element, size_t index);
/**
 * Функція додавання в кінець AgenciesList
 *
 * Функція додає елементи до AgenciesList
 * @param agencies_list вказівник на зв'язковий масив
 * @param element вказівник на данні для вставки
 * @return 0 при вдалому виконанні
 */
int add_element_to_list_end(struct AgenciesList *agencies_list, struct Agency *element);
/**
 * Функція видалення із AgenciesList
 *
 * Функція видаляє елементи із AgenciesList за індексом
 * @param agencies_list вказівник на зв'язковий масив
 * @param index індекс елементу який необхідно видалити
 * @return 0 при вдалому виконанні
 */
int delete_element_from_list_by_index(struct AgenciesList *agencies_list, size_t index);
/**
 * Функція отримання елемента із AgenciesList
 *
 * Функція записує вказівник на елемент у element згідно індексу
 * @param agencies_list вказівник на зв'язковий масив
 * @param element вказівник на вказівник до якого необхідно записати результат виконання
 * @param index індекс елементу
 * @return 0 при вдалому виконанні
 */
int get_element_by_index(struct AgenciesList *agencies_list, struct AgenciesListElement **element, size_t index);
/**
 * Функція довжини AgenciesList
 *
 * Функція вираховує довжину agencies_list
 * @param agencies_list вказівник на зв'язковий масив
 * @return довжину AgenciesList
 */
size_t get_list_length(struct AgenciesList *agencies_list);
/**
 * Функція сортування AgenciesList
 *
 * Функція сортує agencies_list за роками на ринку
 * @param agencies_list вказівник на зв'язковий масив
 * @return 0 при вдалому виконанні
 */
int sort_agencies_list_by_years_on_market(struct AgenciesList *agencies_list);
/**
 * Функція отримання елементу за заданим парметром
 *
 * Функція записує у element вказівник на перший елемент який задовільняє умові
 * @param agencies_list вказівник на зв'язковий масив
 * @param from_index початковий індекс
 * @param city місто-умова
 * @param element вказівник на вказівник до якого необхідно записати результат виконання
 * @return 0 при вдалому виконанні
 */
int get_element_with_city_from_index(struct AgenciesList *agencies_list, size_t from_index, enum Cities city, struct AgenciesListElement **element);

/**
 * Функція виведення AgenciesList
 *
 * Функція виводить agencies_list у файл
 * @param agencies_list вказівник на зв'язковий масив
 * @param file вказівник на файл для виведення
 */
void print_agencies_list_to_file(struct AgenciesList *agencies_list, FILE * file);

/**
 * Функція виведення AgenciesList на екран
 *
 * Функція виводить agencies_list на екран
 * @param agencies_list вказівник на зв'язковий масив
 */
void print_agencies_list_on_screen(struct AgenciesList *agencies_list);
/**
 * Функція виведення AgenciesList на екран у зворотньому порядку
 *
 * Функція виводить agencies_list на екран у зворотньому порядку
 * @param agencies_list вказівник на зв'язковий масив
 */
void print_agencies_list_on_screen_reverse(struct AgenciesList *agencies_list);

/**
 * Функція ініціалізаціх AgenciesList із масиву строк
 *
 * Функція встановлює AgenciesList використовуючи дані із масиву
 * @param agencies_list вказівник на зв'язковий масив
 * @param agencies_text_array масив строк описів
 * @param count_of_agencies кількість агенств
 * @return 0 при вдалому виконанні
 */
int set_agencies_list_from_text_array(struct AgenciesList *agencies_list, char ** agencies_text_array, size_t count_of_agencies);

/**
 * Функція очищення AgenciesList
 *
 * Функція звільняє пам'ять виділену для agencies_list
 * @param agencies_list вказівник на зв'язковий масив
 */
int free_agencies_list(struct AgenciesList *agencies_list);



#endif