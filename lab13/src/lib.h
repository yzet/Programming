
/**
 * @file lib.h
 * @brief File with declaration offunction for work with strings
 * @author Zhuravlev Y.
 * @date 15-dec-2020
 * @version 0.1
 */

#ifndef _LABORATORY_13_
#define _LABORATORY_13_

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <ctype.h>
#include <stdlib.h>


/**
 * Return count of numbers in text
 *
 * @param text text
 * @return count of numbers in text
 *
**/
size_t get_count_of_numbers_in_text(char text[]);

/**
 * Set numbers from text into numbers in text array
 *
 * @param text text
 * @param numbers_in_text array for numbers
 * @return
 *
**/
void get_numbers_in_text(char text[], int *numbers_in_text);

/**
 * Determine symbol if it is digit
 *
 * @param symbol symbol
 * @return true if symbol is digit else false
 *
**/
bool symbol_is_digit(char symbol);

// split text by words and sort it by alphabet
size_t get_count_of_words(char *string);
void str_split(char *string, char *delim, size_t count_of_words, char *words[count_of_words]);
//void str_split1(char *string, char *delim, size_t count_of_words, char *words);
void str_buble_sort(size_t count_of_words, char *words[count_of_words]);

void delete_dublicates(size_t count_of_words, char *words[count_of_words]);
bool is_word_dublicate(size_t count_of_words, char *words[count_of_words], char *word);
void set_text_without_dublicates(char new_text[], size_t count_of_words, char *words[]);

void generate_random_symbol_sequence(size_t count_of_symbols, char char_array[]);
void calclulate_frequency(size_t count_of_symbols, char char_array[], char frequency_table_chars[], float frequency_table_float[]);
void calculate_count_of_symbols_in_text(size_t count_of_symbols, char char_array[], char count_of_symbols_in_text[]);
int is_value_repeats(int value, char array_with_repeats[]);

#endif