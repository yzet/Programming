/**
 * @mainpage
 * # General task
 * Fill array with main diagonal elements and sort it in ascending order
 *
 * @author Zhuravlev Y.
 * @date 30-dec-2020
 * @version 0.1
 */

/**
 * @file main.c
 * @brief Demo file of the fill_array_with_main_diagonal_elements_of_square_array and buble_sort functions
 * @author Zhuravlev Y.
 * @date 07-dec-2020
 * @version 0.1
 */

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/**
 * Return random number from minimal value to maximum value
 *
 * @param minimal_value minimal value
 * @param maximum_value maximum value
 * @return random number
 */
int get_random_number_with_limit_int(int minimal_value, int maximum_value);

/**
 * Fill two dimensional array with random elements
 *
 * @param x_size count of raws
 * @param y_size count of columns
 * @param array array for filling
 * @param low_limit minimal value
 * @param high_limit maximal value
 * @return
 */
void fill_two_dimensional_array_with_random_number(size_t x_size, size_t y_size, int array[x_size][y_size], int low_limit, int high_limit);

/**
 * Fill array with main diagonal elements of square array
 *
 * @param side_size side size
 * @param square_array array for using
 * @param main_diagonal_array array for filling
 * @return
 */
void fill_array_with_main_diagonal_elements_of_square_array(size_t side_size, int square_array[side_size][side_size], int main_diagonal_array[side_size]);

/**
 * Sorting array in ascending order
 *
 * @param array_size array size
 * @param array array for sorting
 * @return
 */
void buble_sort(size_t array_size, int array[]);


/**
 * Main function.
 * Sequencing:
 * - determine count of elements in square array
 * - filling array with main diagonal elements
 * - sort array with main diagonal elements
 * @return successfull code returns (0)
 */
int main()
{
#define ARRAY_SIZE 5
#define LOW_LIMIT -10
#define HIGH_LIMIT_MULTIPLIED_BY_2 20

    int array[ARRAY_SIZE][ARRAY_SIZE];
    fill_two_dimensional_array_with_random_number(ARRAY_SIZE, ARRAY_SIZE, array, LOW_LIMIT, HIGH_LIMIT_MULTIPLIED_BY_2);

    int main_diagonal_elements[ARRAY_SIZE] = {0};
    fill_array_with_main_diagonal_elements_of_square_array(ARRAY_SIZE, array, main_diagonal_elements);

    buble_sort(ARRAY_SIZE, main_diagonal_elements);
    return 0;
}

int get_random_number_with_limit_int(int minimal_value, int maximum_value)
{
    return (rand() % (maximum_value - 1) + minimal_value);
}

void fill_two_dimensional_array_with_random_number(size_t x_size, size_t y_size, int array[x_size][y_size], int low_limit, int high_limit)
{
    for (size_t i = 0; i < x_size; i++)
    {
        for (size_t j = 0; j < y_size; j++)
        {
            array[i][j] = get_random_number_with_limit_int(low_limit, high_limit);
        }
    }
}

void fill_array_with_main_diagonal_elements_of_square_array(size_t side_size, int square_array[side_size][side_size], int main_diagonal_array[side_size])
{
    for (int i = 0; i < side_size; i++)
    {
        main_diagonal_array[i] = square_array[i][i];
    }
}

void buble_sort(size_t array_size, int array[])
{

    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] -= array[j + 1];
            }
        }
    }
}
