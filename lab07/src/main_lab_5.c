#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// from minimal_value to (maximal_value - 1)
int get_random_number_with_limit_int(int minimal_value, int maximum_value);
float get_random_number_with_limit_float(float minimal_value, float maximum_value);

// fill array with random numbers from minimal_limit to (maximum_limit - 1)
void fill_array_wih_random_numbers_int(int array[], int array_size, int minimal_limit, int maximal_limit);

// calculate greatest common factor
int get_greatest_common_factor(int a, int b);
// calculate squre of number
double sqrt(double number);
// return true if number is prime
bool get_is_prime_number(int number);
// set sums in sums_of_array_parts array
void set_summs_of_ticket_digits_parts(int ticket_digits[], int array_size,int sums_of_array_parts[]);
// return true if sums are equal
bool get_is_lucky_ticket(int sums_of_array_parts[]);
// return true if number is perfect
bool get_is_perfect_number(int number);


int main(){

    // task 1, 2 input data
    #define MINIMAL_LIMIT 1
    #define MAXIMUM_LIMIT 10000
    // task 3 input data
    #define COUNT_OF_DIGITS 6
    #define MINIMAL_VALUE_OF_DIGIT 0
    #define MAXIMAL_VALUE_OF_DIGIT 9


    srand( time(NULL) );

    // task 1. get greatest common factor 
    const int NUMBER_A = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    const int NUMBER_B = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    int greatest_common_factor = get_greatest_common_factor(NUMBER_A, NUMBER_B);
    // end task 1. get greatest common factor

    // task 2. determine if number is prime
    const int CHECKING_NUMBER = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    bool is_prime_number = get_is_prime_number(CHECKING_NUMBER);
    // end task 2. determine if number is prime

    // task 3. determine if ticket is lucky
    int ticket_digits[COUNT_OF_DIGITS];
    fill_array_wih_random_numbers_int(ticket_digits, COUNT_OF_DIGITS, MINIMAL_VALUE_OF_DIGIT, MAXIMAL_VALUE_OF_DIGIT + 1);
    int sums_of_ticket_parts[2] = {0};
    set_summs_of_ticket_digits_parts(ticket_digits, COUNT_OF_DIGITS, sums_of_ticket_parts);
    bool is_lucky_ticket = get_is_lucky_ticket(sums_of_ticket_parts);
    // end task 3. determine if ticket is lucky

    // task 4. determine if number is perfect
    const int CHECKING_NUMBER_T4 = get_random_number_with_limit_int(MINIMAL_LIMIT, MAXIMUM_LIMIT);
    bool is_perfect_number = get_is_perfect_number(CHECKING_NUMBER);
    // end task 4. determine if number is perfect

    // task 5. get squere of number
    const float NUMBER = get_random_number_with_limit_float((float)MINIMAL_LIMIT, (float)MAXIMUM_LIMIT);
    float sqrt_of_number = sqrt(NUMBER);
    // end task 5. get squere of number

    return 0;
}

int get_random_number_with_limit_int(int minimal_value, int maximum_value){
    return (rand() % (maximum_value - 1) + minimal_value);
}

float get_random_number_with_limit_float(float minimal_value, float maximum_value){
    return (rand() / (float)(RAND_MAX) * maximum_value + minimal_value);
}

void fill_array_wih_random_numbers_int(int array[], int array_size, int minimal_limit, int maximal_limit){
    for (int i = 0; i < array_size; i++){
        array[i] = get_random_number_with_limit_int(minimal_limit, maximal_limit); 
    }
}


int get_greatest_common_factor(int a, int b){
    int larger_number, less_number;

    if (a > b){
        larger_number = a;
        less_number = b;
    } 
    else{
        larger_number = b;
        less_number = a;
    }
    int greatest_common_factor = less_number;
    int remainder_of_the_division;

    // implementation of the Euclidean algorithm
    do {
        remainder_of_the_division = larger_number % less_number;
        if (remainder_of_the_division != 0) greatest_common_factor = remainder_of_the_division;
        larger_number = less_number;
        less_number = remainder_of_the_division;
    } while(remainder_of_the_division != 0);

    return greatest_common_factor;
}

double sqrt(double number){
    double eps = 0.00;
    int sqr_is_complex_number = 0;
    int iterations = 0;

    if (number < 0) sqr_is_complex_number = 1;
    
    double sqr_of_number = number / 2.0;
    double mistake =  sqr_of_number - (number / sqr_of_number);
    if (mistake < 0) mistake = -mistake;

    if (sqr_is_complex_number != 1)
    {
        if (number == 0) sqr_of_number = 0.0;
        else
        {
            while (mistake > eps )
            {
                sqr_of_number = 0.5 * (sqr_of_number + (number / sqr_of_number));
                mistake =  sqr_of_number - (number / sqr_of_number);
                if (mistake < 0) mistake = -mistake;
                iterations++;
                if (iterations > 40){
                    eps+= 0.01;
                    iterations = 0;
                }
            }
        }
    }
    return sqr_of_number;
}

bool get_is_prime_number(int number){
    bool is_prime_number = false;
    if (number < 2) return is_prime_number;
    else if (number % 2 == 0) return is_prime_number;
    else
    {
         for (int i = 3; i < sqrt((double)number) + 1; i+=2){
             if (number % i == 0){
                 return is_prime_number;
             }
         }
         is_prime_number = true;
         return is_prime_number;
    }
    
}

void set_summs_of_ticket_digits_parts(int ticket_digits[], int array_size,int  sums_of_array_parts[]){
    for (int i = 0; i < array_size / 2; i++){
        sums_of_array_parts[0] += ticket_digits[i];
        sums_of_array_parts[1] += ticket_digits[array_size- i - 1];
    }
}

bool get_is_lucky_ticket(int sums_of_array_parts[]){
    if (sums_of_array_parts[0] == sums_of_array_parts[1])
        return true;
    else
        return false;
}

bool get_is_perfect_number(int number){
    bool is_perfect_number = false;
    int sum_of_dividers = 0;

    for (int divider = 2; divider <= number / 2; divider++)
    {
        if (number % divider == 0) sum_of_dividers += divider;
    }
    if (sum_of_dividers == number && number > 1) is_perfect_number = true;

    return is_perfect_number;
}