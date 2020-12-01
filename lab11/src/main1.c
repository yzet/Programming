#include <stdlib.h>

int get_random_number_with_limit_int(int minimal_value, int maximum_value);
void fill_array_with_random_numbers(size_t array_size, int array[], int low_limit, int high_limit);


int main(){
    #define ARRAY_SIZE 10
    #define LOW_LIMIT 0
    #define HIGH_LIMIT 20

    int array[ARRAY_SIZE] = {0};
    fill_array_with_random_numbers(ARRAY_SIZE, array, LOW_LIMIT, HIGH_LIMIT);
    

    return 0;
}


int get_random_number_with_limit_int(int minimal_value, int maximum_value)
{
    return (rand() % (maximum_value - 1) + minimal_value);
}

void fill_array_with_random_numbers(size_t array_size, int array[], int low_limit, int high_limit)
{
    for (int i = 0; i < array_size; i++){
        array[i] = get_random_number_with_limit_int(low_limit, high_limit);
    }
}