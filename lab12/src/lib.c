#include "lib.h"

size_t get_count_of_numbers_in_text(char text[])
{
    bool is_in_number = false;
    size_t count_of_numbers = 0;
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (isdigit(text[i]))
        {
            if (!is_in_number)
            {
                is_in_number = true;
                count_of_numbers++;
            }
        }
        else
        {
            is_in_number = false;
        }
    }
    return count_of_numbers;
}

void get_numbers_in_text(char text[], long *numbers_in_text)
{
    size_t string_size = 256;
    char buffer[string_size];
    size_t last_index_in_buffer = 0;
    size_t index_of_numbers_in_text = 0;
    bool is_digit = false;
    for (size_t i = 0; i < strlen(text); i++)
    {
        if (isdigit(text[i]))
        {
            buffer[last_index_in_buffer] = text[i];
            buffer[++last_index_in_buffer] = '\0';
            is_digit = true;
        }
        else
        {
            if (is_digit)
            {

                *(numbers_in_text + index_of_numbers_in_text) = strtol(buffer, NULL, 10);
                index_of_numbers_in_text++;
                is_digit = false;
            }
            last_index_in_buffer = 0;
        }
    }
    if (is_digit)
        *(numbers_in_text + index_of_numbers_in_text) = strtol(buffer, NULL, 10);
}

//Hello,whatisy0urname?Myn2m31s9873.
void use_scanf_and_printf(char *input)
{
    printf("%s\n", "Enter text");
    scanf("%255s", input);
    size_t count_of_numbers_in_text = get_count_of_numbers_in_text(input);
    long *numbers = (long *)calloc(count_of_numbers_in_text, sizeof(long));
    get_numbers_in_text(input, numbers);
    print_numbers_by_printf(numbers, count_of_numbers_in_text);
    move_carriage_to_next_raw(input);
    free(numbers);
}

void print_numbers_by_printf(long *numbers, size_t count_of_numbers)
{
    printf("%s", "using printf\n");
    for (size_t i = 0; i < count_of_numbers; i++)
    {
        printf("%ld", *(numbers + i));
        if (i < count_of_numbers - 1)
            printf("%s", "; ");
    }
    if (count_of_numbers == 0)
        printf("%s", "No numbers");
    printf("%c", '\n');
}

void create_output_string(char *output, long *numbers, size_t count_of_numbers)
{
    for (size_t i = 0; i < count_of_numbers; i++)
    {
        char number_str[25];
        sprintf(number_str, "%ld", *(numbers + i));
        strcat(output, number_str);
        if (i < count_of_numbers - 1)
        {
            strcat(output, "; ");
        }
    }
}

//Hello, what is y0ur name? My n2m3 1s 9873.
void use_gets_and_puts(char *input)
{
    printf("%s\n", "Enter text");
    // implicit declaration of function 'gets' is invalid in C99
    //gets(input);
    fgets(input, 255, stdin);
    size_t count_of_numbers_in_text = get_count_of_numbers_in_text(input);
    long *numbers = (long *)calloc(count_of_numbers_in_text, sizeof(long));
    get_numbers_in_text(input, numbers);
    print_numbers_by_puts(numbers, count_of_numbers_in_text);
    move_carriage_to_next_raw(input);
    free(numbers);
}

void print_numbers_by_puts(long *numbers, size_t count_of_numbers)
{
    char *output = (char *)calloc(256, sizeof(char));
    puts("using puts");
    create_output_string(output, numbers, count_of_numbers);
    if (count_of_numbers == 0)
        puts("No numbers");
    else
        puts(output);
    free(output);
}

void use_getc_and_putc(char *input, size_t input_length)
{
    printf("%s\n", "Enter text");
    char symbol;
    size_t index = 0;
    while ((symbol = (char)getc(stdin)) != '\n' && index <= input_length)
    {
        input[index] = symbol;
        index++;
    }
    size_t count_of_numbers_in_text = get_count_of_numbers_in_text(input);
    long *numbers = (long *)calloc(count_of_numbers_in_text, sizeof(long));
    get_numbers_in_text(input, numbers);
    print_numbers_by_putc(numbers, count_of_numbers_in_text);
    free(numbers);
}

void print_numbers_by_putc(long *numbers, size_t count_of_numbers)
{
    char *output = (char *)calloc(256, sizeof(char));
    puts("using putc");
    create_output_string(output, numbers, count_of_numbers);
    if (count_of_numbers == 0)
        puts("No numbers");
    else
    {
        for (size_t i = 0; i < strlen(output); i++)
        {
            putc(output[i], stdout);
        }
    }
    putc('\n', stdout);
    free(output);
}

void use_read_and_write(char *input)
{
    printf("%s\n", "Enter text");
    size_t nbytes = 255 * sizeof(char);
    ssize_t bytes_read;
    int fields = 1;
    bytes_read = read(fields, input, nbytes);
    size_t count_of_numbers_in_text = get_count_of_numbers_in_text(input);
    long *numbers = (long *)calloc(count_of_numbers_in_text, sizeof(long));
    get_numbers_in_text(input, numbers);
    print_numbers_by_write(numbers, count_of_numbers_in_text);
    free(numbers);
}

void print_numbers_by_write(long *numbers, size_t count_of_numbers)
{
    write(1, "using write\n", sizeof("using write\n"));
    char *output = (char *)calloc(256, sizeof(char));
    create_output_string(output, numbers, count_of_numbers);
    if (count_of_numbers == 0)
        puts("No numbers");
    else
    {
        size_t nbytes;
        int fields = 1;
        nbytes = strlen(output);
        write(fields, output, nbytes);
    }
    char buf = '\n';
    write(1, &buf, 1);
    free(output);
}

void move_carriage_to_next_raw(char *input)
{
    if (input[strlen(input) - 1] != '\n')
    {
        while (true)
        {
            char buff[256];
            fgets(buff, 255, stdin);
            if (buff[strlen(buff) - 1] == '\n')
                break;
        }
    }
}