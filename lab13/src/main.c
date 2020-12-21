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

#include "lib.h"

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

    return 0;
}