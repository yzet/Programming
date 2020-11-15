int main(){
    // round move elements of matrix line from right to left

    #define ARRAY_SIZE 3
    #define COUNT_OF_SHIFT_STEPS 1

    int array[ARRAY_SIZE][ARRAY_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    if (ARRAY_SIZE > 1){

        int result_array[ARRAY_SIZE][ARRAY_SIZE] = {0};
        int new_index_of_column = 0;

        for (int column_index = 0; column_index < ARRAY_SIZE; column_index++){

            if (column_index < COUNT_OF_SHIFT_STEPS){

                new_index_of_column = ARRAY_SIZE - COUNT_OF_SHIFT_STEPS + column_index;
            } else {

                new_index_of_column = column_index - COUNT_OF_SHIFT_STEPS;
            }

            for (int line_index = 0; line_index < ARRAY_SIZE; line_index++){

                result_array[line_index][new_index_of_column] = array[line_index][column_index];
            }
        }
        for (int line_index = 0; line_index < ARRAY_SIZE; line_index++){
            for (int column_index = 0; column_index < ARRAY_SIZE; column_index++){

                array[line_index][column_index] = result_array[line_index][column_index];
            }
        }
    }
    
    
    return 0;
}