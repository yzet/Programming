#ifndef _CHECK_AGENCIES_INFO_
#define _CHECK_AGENCIES_INFO_

/**
 * @file check_agencies_info.h
 * @brief Файл з описом функцій для роботи з регулярними виразами
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Функція перевірки строки
 *
 * Функція перевіряє чи починається строки з великої літери та чи не має повторюваних розділових знаків
 * @param string строка для перевірки
 * @return функція повертає true якщо строка пройшла перевірку
 */
bool is_std_regex(char * string);
/**
 * Функція перевірки строки на два а бо більше слів
 *
 * Функція перевіряє чи є в строці два або більше слів
 * @param string строка для перевірки
 * @return функція повертає true якщо строка пройшла перевірку
 */
bool is_two_or_more_words_regex(char * string);

/**
 * Функція перетворення коду повернення у bool
 *
 * Функція перетворює цілочисленний код повернення до bool
 * @param result код
 * @return функція повертає true якщо код дорівнює 0
 */
bool regex_result_to_bool(int result);


#endif