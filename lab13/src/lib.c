/**
 * @file lib.c
 * @brief File with realization of function for work with strings
 * @author Zhuravlev Y.
 * @date 15-dec-2020
 * @version 0.1
 */

#include "lib.h"

size_t get_count_of_numbers_in_text(char text[])
{
    bool is_in_number = false;
    size_t count_of_numbers = 0;
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (symbol_is_digit(text[i]))
        {
            if (!is_in_number)
            {
                is_in_number = true;
                count_of_numbers++;
            }
        }
        else
        {
            is_in_number = false;
        }
    }
    return count_of_numbers;
}

void get_numbers_in_text(char text[], int *numbers_in_text)
{
    size_t string_size = 256;
    char buffer[string_size];
    size_t last_index_in_buffer = 0;
    size_t index_of_numbers_in_text = 0;
    bool is_digit = false;
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (symbol_is_digit(text[i]))
        {
            buffer[last_index_in_buffer] = text[i];
            buffer[++last_index_in_buffer] = '\0';
            is_digit = true;
        }
        else
        {
            if (is_digit)
            {

                 *(numbers_in_text + index_of_numbers_in_text) = atoi(buffer);
                 index_of_numbers_in_text++;
                 is_digit = false;
            }
            last_index_in_buffer = 0;
        }
    }
}

bool symbol_is_digit(char symbol)
{
    if (symbol - '0' >= 0 && symbol - '0' <= 9)
        return true;
    return false;
}

size_t get_count_of_words(char *string)
{
    char string_copy[strlen(string) + 1];
    strcpy(string_copy, string);
    size_t count_of_words = 0;
    char *word = strtok(string_copy, " ,.");
    while (word != NULL)
    {
        count_of_words++;
        word = strtok(NULL, " ,.");
    }
    return count_of_words;
}

void str_split(char *string, char *delim, size_t count_of_words, char *words[count_of_words])
{
    char string_copy[strlen(string) + 1];
    strcpy(string_copy, string);
    if (count_of_words > 0)
        words[0] = strtok(string_copy, delim);
    for (size_t i = 1; i < count_of_words; i++)
    {
        words[i] = strtok(NULL, delim);
    }
}

void str_buble_sort(size_t count_of_words, char *words[count_of_words])
{
    char *buffer;
    for (size_t i = 0; i < count_of_words; i++)
    {
        for (size_t j = 0; j < count_of_words - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                buffer = words[j];
                words[j] = words[j + 1];
                words[j + 1] = buffer;
            }
        }
    }
}

void delete_dublicates(size_t count_of_words, char *words[count_of_words])
{
    char *deleted_string = "none";
    for (size_t i = 0; i < count_of_words; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (strcmp(words[i], words[j]) == 0) words[i] = deleted_string;
        }
    }
}

void set_text_without_dublicates(char new_text[], size_t count_of_words, char *words[])
{
    for (size_t i = 0; i < count_of_words; i++)
    {
        if (strcmp(words[i], "none") != 0)
        {
            strcat(new_text, words[i]);
            if (i != count_of_words - 1)
            {
                strcat(new_text,  ",");
            }
        }
    }
}

void generate_random_symbol_sequence(size_t count_of_symbols, char char_array[])
{
    char first_symbol = ' ';
    char last_symbol = '~' + 1;

    for (size_t i = 0; i < count_of_symbols; i++)
    {
        char_array[i] = first_symbol + rand() % (last_symbol - first_symbol);
    }
}

void calclulate_frequency(size_t count_of_symbols, char char_array[], char frequency_table_chars[], float *frequency_table_float)
{
    char count_of_symbols_in_text[count_of_symbols * 2];
    calculate_count_of_symbols_in_text(count_of_symbols, char_array, count_of_symbols_in_text);
    size_t index_in_frequency = 0;
    for (int i = 0; count_of_symbols_in_text[i] != 0; i += 2)
    {
        frequency_table_chars[index_in_frequency] = count_of_symbols_in_text[i];
        frequency_table_float[index_in_frequency] = count_of_symbols_in_text[i + 1] / (float)count_of_symbols;

        index_in_frequency++;
    }

}

void calculate_count_of_symbols_in_text(size_t count_of_symbols, char char_array[], char count_of_symbols_in_text[])
{
    size_t next_index_in_repeats = 0;
    for (size_t i = 0; i < count_of_symbols; i++)
    {
        int index_in_repeats = is_value_repeats(char_array[i], count_of_symbols_in_text);
        if (index_in_repeats == -1)
        {
            count_of_symbols_in_text[next_index_in_repeats] = char_array[i];
            count_of_symbols_in_text[next_index_in_repeats + 1]++; 
            next_index_in_repeats += 2;
        } else
        {
            count_of_symbols_in_text[index_in_repeats + 1]++;
        }
        
    }
}

int is_value_repeats(int value, char array_with_repeats[])
{
    for (int i = 0; array_with_repeats[i + 1] != 0; i += 2)
    {
        if (array_with_repeats[i] == value)
        {
            return i;
        }
    }
    return -1;
}