/**
 * @mainpage
 * # General task
 * 1. Generate a function that determines the indicator of the order 
 * in sequence of numbers
 *
 * @author Zhuravlev Y.
 * @date 30-nov-2020
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Demo file of the get_indicator_of_order_in_sequence function
 * @author Zhuravlev Y.
 * @date 14-nov-2020
 * @version 0.1
 */

#include <stdarg.h>

int get_indicator_of_order_in_sequence(int count_of_elements, ...);

/**
 * Main function.
 * Sequencing:
 * - determine count of elements in sequence
 * - determine indicator of order by get_indicator_of_order_in_sequence function call
 * @return successfull code returns (0)
 */
int main()
{
    #define COUNT_OF_ELEMENTS_IN_SEQUENCE 5
    
    int indicator_of_order = get_indicator_of_order_in_sequence(COUNT_OF_ELEMENTS_IN_SEQUENCE, 4, 1, 6, 3, 2);

    return 0;
}

/**
 * Determine indicator of order in secuence
 *
 * @param count_of_elements count of elements in sequence
 * @param args sequence of numbers
 * @return indicator of order
 */
int get_indicator_of_order_in_sequence(int count_of_elements, ...)
{
    int indicator_of_order = 0;
    va_list factor;
    va_start(factor, count_of_elements);
    for (int i = 0; i < count_of_elements - 1; i++){
        for (int j = i + 1; j < count_of_elements; j++){
            if (va_arg(factor, int) < va_arg(factor, int)) indicator_of_order++;
        }
    }
    va_end(factor);
    return indicator_of_order;
}
