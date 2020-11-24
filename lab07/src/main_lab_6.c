#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// from minimal_value to (maximal_value - 1)
int get_random_number_with_limit_int(int minimal_value, int maximum_value);
float get_random_number_with_limit_float(float minimal_value, float maximum_value);

double sqrt(double number);

// return random letter or space
char get_random_letter_or_space();

// fill array with random numbers from minimal_limit to (maximum_limit - 1)
void fill_array_wih_random_numbers_int(int array[], int array_size, int minimal_limit, int maximal_limit);

// centered string
void centered_string_with_filler(char string[], char centered_string[], char filler, int string_length);
int get_number_of_letters(char string[], int string_length);

//
void fill_array_with_prime_numbers(int array[], int array_size);
bool get_is_prime_number(int number);

//
void get_number_in_string(int number, char number_in_string[]);

//
void fill_string_with_letters(char string[], int string_length);
int get_count_of_words(char string[], int string_length);

//
void fill_squere_array_with_int(size_t array_size, int array[array_size][array_size], int minimal_limit, int maximal_limit);
void round_move_elements_left(size_t array_size, int array[array_size][array_size], int buffer_array[array_size][array_size], int step);

//
void set_matrix_in_squere(size_t matrix_size, int matrix[matrix_size][matrix_size], int buffer_matrix[matrix_size][matrix_size]);

//
void get_number_in_string(int number, char number_in_string[]);
void fill_string_with_spaces(int string_size, char string[]);

void copy_squre_array_to_squere_array(size_t array_size, int from[array_size][array_size], int to[array_size][array_size]);

int main()
{

    #define MINIMAL_LIMIT 1
    #define MAXIMUM_LIMIT 10000

    #define FIILER '_'
    #define STRING_LENGTH 15

    #define ARRAY_SIZE 5

    #define STRING_SIZE 256

    srand( time(NULL) );

    // task 1. centered string
    const char INPUT_STRING[STRING_LENGTH] = "Ivanov        \0";
    char centered_string[STRING_LENGTH];
    centered_string_with_filler(INPUT_STRING, centered_string, FIILER, STRING_LENGTH);
    // end task 1. centered string

    // task 2. fill array of given size with prime numbers
    const ARRAY_OF_PRIME_NUMBERS_SIZE = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    int array_of_prime_numbers[ARRAY_OF_PRIME_NUMBERS_SIZE];
    fill_array_with_prime_numbers(array_of_prime_numbers, ARRAY_OF_PRIME_NUMBERS_SIZE);
    // end task 2. fill array of given size with prime numbers

    // task 3. transform number into string
    const int number = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    char number_in_string[STRING_SIZE];
    fill_string_with_spaces(STRING_SIZE, number_in_string);
    get_number_in_string(number, number_in_string);

    // end task 3. transform number into string

    // task 4. search count of words
    const STRING_WITH_LETTERS_LENGTH = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    char string_with_letters[STRING_WITH_LETTERS_LENGTH];
    fill_string_with_letters(string_with_letters, STRING_WITH_LETTERS_LENGTH);
    int count_of_words = get_count_of_words(string_with_letters, STRING_WITH_LETTERS_LENGTH);
    // end task 4. search count of words

    // task 5. round move elements of matrix line from right to left
    int squre_array[ARRAY_SIZE][ARRAY_SIZE];
    int buffer_squre_array[ARRAY_SIZE][ARRAY_SIZE];
    const int MINIMAL_VALUE_OF_ELEMENT = 0;
    const int MAXIMAL_VALUE_OF_ELEMENT = 9;
    fill_squere_array_with_int(ARRAY_SIZE, squre_array, MINIMAL_VALUE_OF_ELEMENT, MAXIMAL_VALUE_OF_ELEMENT + 1);
    round_move_elements_left(ARRAY_SIZE, squre_array, buffer_squre_array, 1);
    // end task 5. round move elements of matrix line from right to left

    // task 6. multiply matrix with size matrix_size on itself
    int matrix[ARRAY_SIZE][ARRAY_SIZE];
    int buffer_matrix[ARRAY_SIZE][ARRAY_SIZE];
    fill_squere_array_with_int(ARRAY_SIZE, matrix, MINIMAL_VALUE_OF_ELEMENT, MAXIMAL_VALUE_OF_ELEMENT + 1);
    set_matrix_in_squere(ARRAY_SIZE, matrix, buffer_matrix);
    // end task 6

    return 0;
}

int get_random_number_with_limit_int(int minimal_value, int maximum_value)
{
    return (rand() % (maximum_value - 1) + minimal_value);
}

float get_random_number_with_limit_float(float minimal_value, float maximum_value)
{
    return (rand() / (float)(RAND_MAX)*maximum_value + minimal_value);
}

double sqrt(double number)
{
    double eps = 0.00;
    int sqr_is_complex_number = 0;
    int iterations = 0;

    if (number < 0)
        sqr_is_complex_number = 1;

    double sqr_of_number = number / 2.0;
    double mistake = sqr_of_number - (number / sqr_of_number);
    if (mistake < 0)
        mistake = -mistake;

    if (sqr_is_complex_number != 1)
    {
        if (number == 0)
            sqr_of_number = 0.0;
        else
        {
            while (mistake > eps)
            {
                sqr_of_number = 0.5 * (sqr_of_number + (number / sqr_of_number));
                mistake = sqr_of_number - (number / sqr_of_number);
                if (mistake < 0)
                    mistake = -mistake;
                iterations++;
                if (iterations > 40)
                {
                    eps += 0.01;
                    iterations = 0;
                }
            }
        }
    }
    return sqr_of_number;
}

void fill_array_wih_random_numbers_int(int array[], int array_size, int minimal_limit, int maximal_limit)
{
    for (int i = 0; i < array_size; i++)
    {
        array[i] = get_random_number_with_limit_int(minimal_limit, maximal_limit);
    }
}

void centered_string_with_filler(char string[], char centered_string[], char filler, int string_length)
{
    int number_of_letters = get_number_of_letters(string, string_length);
    int count_of_filling_symbols = (STRING_LENGTH - number_of_letters) / 2;
    int left_part_filler_last_index = count_of_filling_symbols;
    int text_part_last_index = left_part_filler_last_index + number_of_letters;
    int right_part_first_index = text_part_last_index;
    for (int i = 0; i < left_part_filler_last_index; i++)
    {
        centered_string[i] = filler;
    }

    int given_string_index = 0;
    for (int i = left_part_filler_last_index; i < text_part_last_index; i++, given_string_index++)
    {
        centered_string[i] = string[given_string_index];
    }

    for (int i = right_part_first_index; i < STRING_LENGTH - 1; i++)
    {
        centered_string[i] = filler;
    }
}

int get_number_of_letters(char string[], int string_length)
{
    int number_of_letters = 0;
    for (int i = 0; i < string_length; i++)
    {
        if ((string[i] != ' ') && (string[i] != '\0'))
        {
            number_of_letters++;
        }
        else
        {
            return number_of_letters;
        }
    }
    return number_of_letters;
}

void fill_array_with_prime_numbers(int array[], int array_size)
{
    int last_number = 2;

    for (int i = 0; i < array_size; i++)
    {

        for (int number = last_number; number < __INT_MAX__; number++)
        {

            bool is_prime_number = get_is_prime_number(number);

            if (is_prime_number == true)
            {
                array[i] = number;
                last_number = number + 1;
                break;
            }
        }
    }
}

bool get_is_prime_number(int number)
{
    bool is_prime_number = false;
    if (number < 2)
        return is_prime_number;
    else if (number == 2)
    {
        is_prime_number = true;
        return is_prime_number;
    }
    else if (number % 2 == 0)
        return is_prime_number;
    else
    {
        for (int i = 3; i < sqrt((double)number) + 1; i += 2)
        {
            if (number % i == 0)
            {
                return is_prime_number;
            }
        }
        is_prime_number = true;
        return is_prime_number;
    }
}

void fill_string_with_spaces(int string_size, char string[]){
    for (int i = 0; i < string_size; i++){
        string[i] = ' ';
    }
}


void get_number_in_string(int number, char number_in_string[])
{
    int thousands, hundreds, dozens, units;
    thousands = number / 1000;
    hundreds = number / 100 % 10;
    dozens = number / 10 % 10;
    units = number % 10;

    char *thousands_strings[9] = {"одна тисяча", "дві тисячі", "три тисячі", "чотири тисячі", "п'ять тисяч", "шість тисяч",  "сім тисяч",  "вісім тисяч",  "дев'ять тисяч"};
    char *hungreds_strings[9] = {"сто", "двісті", "триста", "чотириста", "п'ятсот", "шістсот",  "сімсот",  "вісімсот",  "дев'ятьсот"};
    char *dozens_strings[9] = {"десять", "двадцять", "тридцять", "сорок", "п'ятдесят", "шіcтдесят", "сімдесят",  "вісімдесят",  "дев'яносто"};
    char *from_ten_to_nineteen_strings[9] = {"одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п'ятнадцять", "шістнадцять",  "сімнадцять",  "вісімнадцять",  "дев'ятнадцять"};
    char *units_strings[9] = {"один", "два", "три", "чотири", "п'ять", "шість", "сім", "вісім", "дев'ять"};

    char *searched_strings[4] = {"\0", "\0", "\0", "\0"};

    if (thousands != 0) searched_strings[0] = thousands_strings[thousands - 1];
    if (hundreds != 0) searched_strings[1] = hungreds_strings[hundreds - 1];
    if (dozens == 1 && units > 0) searched_strings[2] = from_ten_to_nineteen_strings[units - 1];
    else if (dozens != 0) searched_strings[2] = dozens_strings[dozens - 1];
    if (dozens != 1 && units != 0) searched_strings[3] = units_strings[units - 1];

    int index_number_in_string = 0, index_searched_strings = 0;
    const int number_in_string_size = 256;
    for (int i = 0; i < number_in_string_size; i++){
        for (int inside_index_searched_string = 0; searched_strings[index_searched_strings][inside_index_searched_string] != '\0'; inside_index_searched_string++){
            number_in_string[index_number_in_string] = searched_strings[index_searched_strings][inside_index_searched_string];
            index_number_in_string++;
        }
        index_searched_strings++;
        number_in_string[index_number_in_string] = ' ';
        index_number_in_string++;
        if (index_searched_strings > 3) break;
    }

}


char get_random_letter_or_space()
{
    char symbol;
    const int FIRST_LETTTER_INDEX = 97;
    const int LAST_LETTTER_INDEX = 122;
    const int COUNT_OF_LETTERS = LAST_LETTTER_INDEX - FIRST_LETTTER_INDEX + 1;
    int symbol_code = rand() % LAST_LETTTER_INDEX;
    if (symbol_code >= FIRST_LETTTER_INDEX)
    {
        symbol = ' ';
    }
    else
    {
        int code = rand() % COUNT_OF_LETTERS + FIRST_LETTTER_INDEX;
        symbol = (char)code;
    }
    return symbol;
}

void fill_string_with_letters(char string[], int string_length)
{
    for (int i = 0; i < string_length - 1; i++)
    {
        string[i] = get_random_letter_or_space();
    }
}

int get_count_of_words(char string[], int string_length)
{
    int count_of_words = 0;
    bool is_in_the_word = false;
    for (int i = 0; i < string_length; i++)
    {
        if (string[i] != ' ' && is_in_the_word != true)
        {
            count_of_words++;
            is_in_the_word = true;
        }
        else if (string[i] == ' ' && is_in_the_word == true)
        {
            is_in_the_word = false;
        }
    }
    return count_of_words;
}

void fill_squere_array_with_int(size_t array_size, int array[array_size][array_size], int minimal_limit, int maximal_limit)
{

    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            array[i][j] = get_random_number_with_limit_int(minimal_limit, maximal_limit);
        }
    }
}

void round_move_elements_left(size_t array_size, int array[array_size][array_size], int buffer_array[array_size][array_size], int step)
{
    if (array_size > 1)
    {
        int new_index_of_column = 0;

        for (int column_index = 0; column_index < array_size; column_index++)
        {

            if (column_index < step)
            {

                new_index_of_column = array_size - step + column_index;
            }
            else
            {

                new_index_of_column = column_index - step;
            }

            for (int line_index = 0; line_index < array_size; line_index++)
            {
                buffer_array[line_index][new_index_of_column] = array[line_index][column_index];
            }
        }
        
        copy_squre_array_to_squere_array(array_size, buffer_array, array); 
    }
}

void set_matrix_in_squere(size_t matrix_size, int matrix[matrix_size][matrix_size], int buffer_matrix[matrix_size][matrix_size])
{
    int left_matrix_column = 0, right_matrix_line = 0;
    int sum_buffer = 0;
    for (int left_matrix_line = 0; left_matrix_line < matrix_size; left_matrix_line++)
    {

        for (int right_matrix_column = 0; right_matrix_column < matrix_size; right_matrix_column++)
        {

            for (int changing_index = 0; changing_index < matrix_size; changing_index++)
            {

                sum_buffer += matrix[left_matrix_line][changing_index] * matrix[changing_index][right_matrix_column];
            }
            buffer_matrix[left_matrix_line][right_matrix_column] = sum_buffer;
            sum_buffer = 0;
        }
    }
    copy_squre_array_to_squere_array(matrix_size, buffer_matrix, matrix); 

}

void copy_squre_array_to_squere_array(size_t array_size, int from[array_size][array_size], int to[array_size][array_size])
{
    for (int i = 0; i < array_size; i++){
        for (int j = 0; j < array_size; j++){
            to[i][j] = from[i][j];
        }
    }
}