#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__

/**
 * @file lib.h
 * @brief Файл з описом структури агенств, перерахуванням міст, функцій
 * оперування агенствами, структури динамічсного агенства та функцій оперування динамічними масивами
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */


#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"
#include "stdbool.h"

#define STRING_SIZE 256

/**
 * Структура "Динамічний масив"
 */
struct DynamicArray
{
    void * array;
    size_t length;
    size_t size_of_elements;
};

/**
 * Структура "Людина"
 */
struct Person
{
    // char surname[STRING_SIZE];
    // char name[STRING_SIZE];
    // char email[STRING_SIZE];
    char * surname;
    char * name;
    char *email;
};

/**
 * Перелік міст
 */
enum Cities
{
    Kharkiv,
    Kyiv,
    London,
    NumberOfCities
};

/**
 * Структура "Агенство"
 */
struct Agency
{
    bool is_weekends;
    // char name[STRING_SIZE];
    char *name;
    size_t years_on_market;
    struct Person director;
    enum Cities city;
};

/**
 * Функція ініціалізації Person
 *
 * Функція втановлює значення полів для змінних типу Person
 * @param person структура для ініціалізації
 * @param surname
 * @param name
 * @param email
 */
void set_person(struct Person *person, char *surname, char *name, char *email);
/**
 * Функція ініціалізації Agency
 *
 * Функція втановлює значення полів для змінних типу Agency
 * @param agency структура для ініціалізації
 * @param is_weakends наявність вихідних
 * @param agency_name
 * @param years_on_market
 * @param agency_director
 * @param city місто агенства
 */
void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city);

/**
 * Функція виводу
 *
 * Функція виводить агентсво
 * @param agency агенство
 * @param file файл для виводу
 */
 void print_agency(struct Agency *agency, FILE *file);
/**
* Функція перетворення значення типу bool у строку
*
* Функція перетворює значення поля агенства у строку
* @param is_weekends_string строка для запису результату
* @param is_weekeds значення для перетворення
*/
void is_weekends_to_string(char **is_weekends_string, bool is_weekeds);
/**
 * Функція перетворення значення типу City у строку
 *
 * Функція перетворює значення поля агенства у строку
 * @param city_string строка для запису результату
 * @param city значення для перетворення
 */
void cities_to_string(char **city_string, enum Cities city);

/**
 * Функція ініціалізації DynamicArray
 *
 * Функція встановлю розмір змінних записаних у динамічний масив
 * @param dynamic_array вказівник на динаміний масив
 * @param size_of_elements розмір одного елементу
 */
void init_dynamic_array(struct DynamicArray * dynamic_array, size_t size_of_elements);
/**
 * Функція очищення DynamicArray
 *
 * Функція звільнює пам'ять виділену під динамчний масив
 * @param dynamic_array вказівник на динаміний масив
 */
void free_dynamic_array(struct DynamicArray *dynamic_array);

/**
 * Функція втавлення у DynamicArray
 *
 * Функція додає елементи до DynamicArray заданим індексом
 * @param dynamic_array вказівник на динаміний масив
 * @param inserted_data вказівник на данні для вставки
 * @param count_of_elements кількість елементів для втавлення
 * @param from_index перший індекс для втавлення
 */
void insert(struct DynamicArray * dynamic_array, void * inserted_data, size_t count_of_elements, size_t from_index);
/**
 * Функція видалення із DynamicArray
 *
 * Функція видаляє едементи із DynamicArray за заданими індексами початку і кінця
 * @param dynamic_array вказівник на динаміний масив
 * @param start_index початковий індекс
 * @param end_index кінцевий індекс
 */
void reduce(struct DynamicArray * dynamic_array, size_t start_index, size_t end_index);
/**
 * Функція виведення динамічного масиву символів
 *
 * Функція вивовить динаміний масив символів
 * @param dynamic_array вказівник на динаміний масив
 * @param file вказівник на файлдля виведення
 */
void print_dynamic_char_array(struct DynamicArray *dynamic_array, FILE * file);



#endif