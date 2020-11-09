int main(){

    // task 1
    // determine the greatest common factor
    #define NUMBER_1 85
    #define NUMBER_2 84

    int larger_number, less_number;

    if (NUMBER_1 > NUMBER_2){
        larger_number = NUMBER_1;
        less_number = NUMBER_2;
    } 
    else{
        larger_number = NUMBER_2;
        less_number = NUMBER_1;
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
    
    // task 2
    // determine if a number is prime
    #define NUMBER_TASK_2 17

    int number_is_prime = 1; // if number_is_prime == 1 then number is prime
    if (NUMBER_TASK_2 <= 1) 
        number_is_prime = 0;
    if (NUMBER_TASK_2 == 2 || NUMBER_TASK_2 == 3) {
        number_is_prime = 0;    
    }
    if (NUMBER_TASK_2 % 2 == 0)
        number_is_prime = 0;
    for (int i = 3; i <= NUMBER_TASK_2 / 2; i+=2 ){
        if (NUMBER_TASK_2 % i == 0) {
            number_is_prime = 0;
        }
    }

    // task 3
    // determine if the ticket is lucky
    #define NUMBER_TASK_3 997999

    int count_of_digits = 6;

    int left_part_sum = 0;
    int right_part_sum = 0;

    int int_devider = 1;
    int int_devider_power = 5;

    int part_index = 0; // 0 - left part, 1 - right part


    for (int digit_index = 0; digit_index < count_of_digits; digit_index++){
        int buffer = 0;
        
        for (int power = 0; power < int_devider_power; power++){
            int_devider *= 10;
        }
        int_devider_power--;

        buffer = (NUMBER_TASK_3 / int_devider) % 10;

        if (part_index == 0){
            left_part_sum += buffer; 
        } 
        else{
            right_part_sum += buffer;    
        }

        if (digit_index == 2) part_index = 1;
        int_devider = 1;
    }

    int is_lucky_ticket = 0; // if is_lucky_ticket == 1, then it is lucky ticket
    if (left_part_sum == right_part_sum) is_lucky_ticket = 1;

    // task 4
    // determine if number is perfect
    #define NUMBER_TASK_4 10 // int type

    int is_perfect_number = 0;
    int divider_sum_of_number = 1;

    // for loop
    for (int divider = 2; divider <= NUMBER_TASK_4 / 2; divider++)
    {
        if (NUMBER_TASK_4 % divider == 0) divider_sum_of_number += divider;
    }
    if (divider_sum_of_number == NUMBER_TASK_4 && NUMBER_TASK_4 > 1) is_perfect_number = 1;

    divider_sum_of_number = 1;
    is_perfect_number = 0;

    // while loop
    int divider = 2;
    while (divider <= NUMBER_TASK_4 / 2)
    {
        if (NUMBER_TASK_4 % divider == 0) divider_sum_of_number += divider;
        divider++;
    }
    if (divider_sum_of_number == NUMBER_TASK_4 && NUMBER_TASK_4 > 1) is_perfect_number = 1;

    divider_sum_of_number = 1;
    is_perfect_number = 0;
    divider = 2;

    // do while loop
    if (NUMBER_TASK_4 > 1){
        do {
            if (NUMBER_TASK_4 % divider == 0) divider_sum_of_number += divider;
            divider++;
        } while (divider <= NUMBER_TASK_4 / 2);
    }
    if (divider_sum_of_number == NUMBER_TASK_4 && NUMBER_TASK_4 > 1) is_perfect_number = 1;


    // task 5
    // determine square root of number
    #define NUMBER_TASK_5 1.0
    // number 18837926214255625 takes 31 iterations
    double eps = 0.00;
    int sqr_is_complex_number = 0;
    int iterations = 0;

    if (NUMBER_TASK_5 < 0) sqr_is_complex_number = 1;
    
    double sqr_of_number = NUMBER_TASK_5 / 2.0;
    double mistake =  sqr_of_number - (NUMBER_TASK_5 / sqr_of_number);
    if (mistake < 0) mistake = -mistake;

    if (sqr_is_complex_number != 1)
    {
        if (NUMBER_TASK_5 == 0) sqr_of_number = 0.0;
        else
        {
            while (mistake > eps )
            {
                sqr_of_number = 0.5 * (sqr_of_number + (NUMBER_TASK_5 / sqr_of_number));
                mistake =  sqr_of_number - (NUMBER_TASK_5 / sqr_of_number);
                if (mistake < 0) mistake = -mistake;
                iterations++;
                if (iterations > 40){
                    eps+= 0.01;
                    iterations = 0;
                }
            }
        }
    }

    return 0;
}