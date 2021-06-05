#ifndef _AGENCY_LAB15_
#define _AGENCY_LAB15_

/**
 * @file lib.h
 * @brief Файл з описом структури агенств, перерахуванням міст та функцій
 * оперування агенствами
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 256
#define N 9

/**
 * Структура "Людина"
 */
struct Person
{
    char surname[STRING_SIZE];
    char name[STRING_SIZE];
    char email[STRING_SIZE];
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
    char name[STRING_SIZE];
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
 * Функція запросу даних з консолі
 *
 * Функція виводить на екран повідомлення і зчитує дані
 * @param to строка для запису результатів вводу
 * @param max_to_length максимальна довжина вводу
 * @param message повідомлення для виведення
 */
void get_info_from_console(char *to, size_t max_to_length, char *message);

/**
 * Функція зчитування даних з файлу
 *
 * Функція зчитує файл і записує його вміст у строку
 * @param to строка для запису вмісту
 * @param max_to_length максимальна довжина вмісту
 */
void read_agencies_text_file(char *to, size_t max_to_length);

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
 * Функція ініціалізації масиву структур {@link Agency}
 *
 * Функція на основі масиву строк з описом агенств формує масив структур
 * @param agencies масив структур {@link Agency}
 * @param agencies_info строки з описом агенств
 * @param count_of_agencies кількість агентсв
 */
void set_agencies(struct Agency ** agencies, char **agencies_info, size_t count_of_agencies);

/**
 * Функція втановлення опису агенства за індексом
 *
 * Функція на основі масиву строк з описом агенств створює масив з описом одного агенства
 * @param agency_info опис агенства
 * @param agencies_info строки з описом агенств
 * @param agency_info_index індекс потрібного агенства
 * @return index
 */
size_t set_agency_info(char *** agency_info, char ** agencies_info, size_t agency_info_index);

/**
 * Функція виводу
 *
 * Функція виводить агентсво
 * @param agency агенство
 * @param file файл для виводу
 */
void print_agency(struct Agency * agency, FILE * file);

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
 * Функція генерації строки-опису агенства
 *
 * Функція генерує строку та записує її у файл
 * @param id id агенства
 * @param path_to_file шлях до файлу запису
 */
void generate_agency_info_text(size_t id, char * path_to_file);

/**
 * Функція запису у бінарний файл
 *
 * Функція записує агенство до бінарного файлу
 * @param agency агенство
 * @param file файл для запису
 */
void write_agency_binary(struct Agency * agency, FILE * file);

/**
 * Функція читання із бінарного файлу
 *
 * Функція зчитує агенство із бінарного файлу
 * @param agency агенство
 * @param file файл для запису
 * @param index індекс агенства серед записанних
 */
void load_agency_binary_by_index(struct Agency * agency, FILE * file, size_t index);

/**
 * Перерахування опцій сортування
 */
enum AgencySortingOptions
{
    YearsOnMarketOption, 
    CityOption,
    NumberOfAgencySortingOptions
};

/**
 * Функція сортування агенств
 *
 * Функція сортує агенства згідно опціх сортування
 * @param agencies масив агенств
 * @param count_of_agencies кількість агенств у масиві
 * @param agency_sorting_option опція сортування
 */
void sort_agencies_by_options(struct Agency **agencies, size_t count_of_agencies, enum AgencySortingOptions agency_sorting_option);

/**
 * Функція вибору агенств
 *
 * Функція обирає агенства, які працюють у місті Харків та мають 3+ років на ринку
 * @param agencies масив агенств
 * @param geting_agencies вказівник на масив для запису отриманих агенств
 * @param count_of_agencies кількість агенств у масиві
 * @return повертає кількість обраних агенств
 */
size_t get_agencies_from_kharkiv_with_3_or_more_years_on_market(struct Agency *agencies, struct Agency ** geting_agencies, size_t count_of_agencies);

#endif