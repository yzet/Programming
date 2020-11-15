int main(){
    // search count of words
    #define TEXT_LENGTH 26
    char text[] = "String with words    test";
    int count_of_words = 0;
    int is_in_the_word = 0;
    for (int i = 0; i < TEXT_LENGTH; i++)
    {
        if (text[i] != ' ' && is_in_the_word != 1){
            count_of_words++;
            is_in_the_word = 1;
        } else if (text[i] == ' ' && is_in_the_word == 1){
            is_in_the_word = 0;
        } 
    }
    
    return 0;
}