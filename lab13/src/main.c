/**
 * @mainpage
 * # General task
 * Find all numbers in text
 *
 * @author Zhuravlev Y.
 * @date 15-dec-2020
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Demo file of the get_numbers_in_text function
 * @author Zhuravlev Y.
 * @date 15-dec-2020
 * @version 0.1
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

/**
 * Main function.
 * Sequencing:
 * - determine count of numbers in text
 * - filling array with numbers with numbers
 * @return successfull code returns (0)
 */
int main()
{
    char text[] = "Hello, what is y0ur name? My n2m3 1s 9873.";
    size_t count_of_numbers = get_count_of_numbers_in_text(text);
    int *numbers_in_text = (int *)calloc(count_of_numbers, sizeof(int));
    get_numbers_in_text(text, numbers_in_text); 
    free(numbers_in_text);
}

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