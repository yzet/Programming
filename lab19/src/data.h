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
    char * email;
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
    // char  name[STRING_SIZE];
    char * name;
    size_t years_on_market;
    struct Person director;
    enum Cities city;
};

/**
 * Перерахування індексів полів агенства
 */
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
 * Функція генерації строки-опису агенства
 *
 * Функція генерує строку та записує її у файл
 * @param id id агенства
 * @param path_to_file шлях до файлу запису
 */
void cities_to_string(char **city_string, enum Cities city);
/**
 * Функція виводу
 *
 * Функція виводить агентсво
 * @param agency агенство
 * @param file файл для виводу
 */
void write_agency_data(struct Agency *agency, FILE * file);

/**
 * Функція порівняння агенств
 *
 * Функція порівнює два агенства за роками на ринку
 * @param agency1
 * @param agency2
 */
int agencies_cmp_by_years_on_market(struct Agency *agency1, struct Agency *agency2);
/**
 * Функція зчитування даних з файлу
 *
 * Функція зчитує файл і записує його вміст у строку
 * @param to строка для запису вмісту
 * @param max_to_length максимальна довжина вмісту
 */
void read_agencies_text_file(char *to, size_t max_to_length, char *path_to_file_with_data);
/**
 * Функція розділення строки
 *
 * Функція розділяє строку за розділювачем та записує підстроки до масиву строк
 * @param lexemes масив строк для запису підстрок
 * @param string строка для розділення
 * @param delim розділювач
 * @return кількість підстрок
 */
size_t split(char ***lexemes, char *string, char *delim);
/**
 * Функція втановлення опису агенства за індексом
 *
 * Функція на основі масиву строк з описом агенств створює масив з описом одного агенства
 * @param agency_info опис агенства
 * @param agencies_info строки з описом агенств
 * @param agency_info_index індекс потрібного агенства
 * @return index
 */
size_t set_agency_info(char ***agency_info, char **agencies_info, size_t agency_info_index);


#endif