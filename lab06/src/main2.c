int main(){
    // fill array of given size with prime numbers 
    #define ARRAY_OF_PRIME_NUMBERS_SIZE 1000

    int prime_numbers_array[ARRAY_OF_PRIME_NUMBERS_SIZE] = {0};

    int last_number = 2;

    for (int i = 0; i < ARRAY_OF_PRIME_NUMBERS_SIZE; i++){

        for(int number = last_number; number < __INT_MAX__; number++){

            int is_prime_number = 1;

            for (int divider = 2; divider <= number / 2; divider++){
                if (number % divider == 0){
                    is_prime_number = 0;
                    break;
                }
            }

            if (is_prime_number == 1){
                    prime_numbers_array[i] = number;
                    last_number = number + 1;
                    break;
            }
        }
    }

    return 0;
}