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
#include "lib.h"

int main()
{
    printf("%s %s %s\n", "Author: Zhuravlev Yaroslav.", "Laboratory 12.", "Interaction with the user through the mechanism of input and output.");
    char *input = (char *)calloc(256, sizeof(char)); 
    // printf and scanf
    
    //long *numbers = (long *)calloc(0, sizeof(long));
    use_scanf_and_printf(input);
    use_gets_and_puts(input);
    free(input);
    input = (char *)calloc(256, sizeof(char));
    use_getc_and_putc(input, 255);
    use_read_and_write(input);

    if (input != NULL)
        free(input);

    return 0;
}