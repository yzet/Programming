#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int get_random_number_with_limit_int(int minimal_value, int maximum_value);
void fill_array_with_random_numbers(size_t array_size, int array[], int low_limit, int high_limit);
void calculate_count_of_repeats(size_t array_size, int array[], int *array_with_repeats);
int is_value_repeats(int value, int *array_with_repeats);
void set_array_with_elements_that_repeats(size_t array_size, int *array_with_elements_that_repeats, int *array_with_repeats);
int trim_array_with_elements_that_repeats(size_t array_size, int *array_with_elements_that_repeats);

int main()
{
    #define ARRAY_SIZE 10
    #define LOW_LIMIT 0
    #define HIGH_LIMIT 20

    srand(time(NULL));

    bool is_not_enough_memory = false;

    int array[ARRAY_SIZE] = {0};
    fill_array_with_random_numbers(ARRAY_SIZE, array, LOW_LIMIT, HIGH_LIMIT);

    int *array_with_repeats = (int *)calloc(ARRAY_SIZE * 2, sizeof(int));
    int *array_with_elements_that_repeats = (int *)calloc(ARRAY_SIZE * 2, sizeof(int));

    if (!array_with_repeats || !array_with_elements_that_repeats)
    {
        is_not_enough_memory = true;
        return 0;
    }

    calculate_count_of_repeats(ARRAY_SIZE, array, array_with_repeats);
    set_array_with_elements_that_repeats(ARRAY_SIZE * 2, array_with_elements_that_repeats, array_with_repeats);
    free(array_with_repeats);

    int array_with_elements_that_repeats_size = trim_array_with_elements_that_repeats(ARRAY_SIZE, array_with_elements_that_repeats);
   
    free(array_with_elements_that_repeats);

    return 0;
}

int get_random_number_with_limit_int(int minimal_value, int maximum_value)
{
    return (rand() % (maximum_value - 1) + minimal_value);
}

void fill_array_with_random_numbers(size_t array_size, int array[], int low_limit, int high_limit)
{
    for (int i = 0; i < array_size; i++)
    {
        array[i] = get_random_number_with_limit_int(low_limit, high_limit);
    }
}

void calculate_count_of_repeats(size_t array_size, int array[], int *array_with_repeats)
{
    int index_of_value_in_repeats = -1;
    int next_index_for_value_in_repeats = 0;
    for (int i = 0; i < array_size; i++)
    {
        index_of_value_in_repeats = is_value_repeats(array[i], array_with_repeats);
        if (index_of_value_in_repeats != -1)
        {
            *(array_with_repeats + index_of_value_in_repeats + 1) += 1;
        }
        else
        {
            *(array_with_repeats + next_index_for_value_in_repeats) = array[i];
            *(array_with_repeats + next_index_for_value_in_repeats + 1) += 1;
            next_index_for_value_in_repeats += 2;
        }
    }
}

int is_value_repeats(int value, int *array_with_repeats)
{
    for (int i = 0; *(array_with_repeats + i + 1) != 0; i += 2)
    {
        if (*(array_with_repeats + i) == value)
        {
            return i;
        }
    }
    return -1;
}

void set_array_with_elements_that_repeats(size_t array_size, int *array_with_elements_that_repeats, int *array_with_repeats)
{
    int next_index_in_array_with_elements_that_repeats = 0;
    for (int i = 0; *(array_with_repeats + i + 1) != 0; i += 2)
    {
        if (*(array_with_repeats + i + 1) != 1)
        {
            *(array_with_elements_that_repeats + next_index_in_array_with_elements_that_repeats) = *(array_with_repeats + i);
            *(array_with_elements_that_repeats + next_index_in_array_with_elements_that_repeats + 1) = *(array_with_repeats + i + 1);
            next_index_in_array_with_elements_that_repeats += 2;
        }
    }
}
int trim_array_with_elements_that_repeats(size_t array_size, int *array_with_elements_that_repeats)
{
    int index_of_last_element_that_repeats = 0;
    int size_after_trim = 0;
    for (int i = 0; i < array_size - 2; i += 2)
    {
        if (*(array_with_elements_that_repeats + i + 1) == 0)
        {
            index_of_last_element_that_repeats = i;
            break;
        }
    }

    array_with_elements_that_repeats = (int *)realloc(array_with_elements_that_repeats, index_of_last_element_that_repeats * sizeof(int));
    size_after_trim = index_of_last_element_that_repeats;
    return size_after_trim;
}