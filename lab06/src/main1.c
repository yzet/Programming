int main(){
    // center the given line with the given placeholder

    #define FILLER '_'
    #define STRING_LENGTH 16

    char given_string[STRING_LENGTH] = "Ivano          \0";
    char result_task_1[STRING_LENGTH];

    int count_of_symbols_in_given_string = 0;

    for (int i = 0; i < STRING_LENGTH; i++)
    {
        if (given_string[i] != ' ') count_of_symbols_in_given_string++;
    }
    
    count_of_symbols_in_given_string--; // delete \0 
    int count_of_filling_symbols = (STRING_LENGTH - count_of_symbols_in_given_string) / 2;

    int left_part_filler_last_index = count_of_filling_symbols;
    int text_part_last_index = left_part_filler_last_index + count_of_symbols_in_given_string;
    int right_part_first_index = text_part_last_index;

    for (int i = 0; i < left_part_filler_last_index; i++){
        result_task_1[i] = FILLER;
    }

    int given_string_index = 0;
    for (int i = left_part_filler_last_index; i < text_part_last_index; i++, given_string_index++){
        result_task_1[i] = given_string[given_string_index];
    }
    
    for (int i = right_part_first_index; i < STRING_LENGTH - 1; i++){
        result_task_1[i] = FILLER;
    }
    return 0;
}