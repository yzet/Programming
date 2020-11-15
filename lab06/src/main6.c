int main()
{
    // multiply matrix with size MATRIX_SIZE on itself

    #define MATRIX_SIZE 4

    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {5, 6, 3, 7},
        {1, 2, 3, 8},
        {4, 5, 6, 9},
        {4, 5, 6, 9}
        };

    int result[MATRIX_SIZE][MATRIX_SIZE] = {0};

    int left_matrix_column = 0, right_matrix_line = 0;
    for (int left_matrix_line = 0; left_matrix_line < MATRIX_SIZE; left_matrix_line++){

        for (int right_matrix_column = 0; right_matrix_column < MATRIX_SIZE; right_matrix_column++){
            
           for (int changing_index = 0; changing_index < MATRIX_SIZE; changing_index++){

               result[left_matrix_line][right_matrix_column] += matrix[left_matrix_line][changing_index] * matrix[changing_index][right_matrix_column];

           }

        }
    }


    return 0;
}