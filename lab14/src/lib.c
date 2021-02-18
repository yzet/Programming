#include "lib.h"

void show_directory_file_struct(char *directory_name, int count_of_space)
{
    DIR *folder;
    struct dirent *entry;

    folder = opendir(directory_name);
    if (folder != NULL)
    {
        while ((entry = readdir(folder)))
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                printf("%*c", count_of_space, ' ');
                printf("%s\n", entry->d_name);
                char *full_inner_directory_name = (char *)calloc(strlen(directory_name) + 1 + strlen(entry->d_name), sizeof(char) + 1);
                strcat(full_inner_directory_name, directory_name);
                strcat(full_inner_directory_name, "/");
                strcat(full_inner_directory_name, entry->d_name);
                show_directory_file_struct(full_inner_directory_name, count_of_space + 1);
                free(full_inner_directory_name);
            }
        }
    }

    closedir(folder);
}

void show_directory_size()
{
    char *directory_name = (char *)calloc(256, sizeof(char));
    get_directory_name(directory_name);

    double directory_size = calculate_directory_size(directory_name);
    directory_size /= 1024.0;
    char *directory_size_str = (char *)calloc(256, sizeof(char));
    sprintf(directory_size_str, "%3.2f", directory_size);

    for (size_t i = 0; directory_size_str[i] != '.'; i++)
    {
        if (i > 2)
            directory_size_str[i] = '0';
    }

    printf("%s %s: %s%s\n", "Size of", directory_name, directory_size_str, " KB");
    free(directory_name);
    free(directory_size_str);
}

void get_directory_name(char *to)
{
    printf("%s\n", "Enter directory name:");
    scanf("%s", to);
}

double calculate_directory_size(char *directory_name)
{
    double directory_size = 0.0;

    DIR *folder;
    struct dirent *entry;

    folder = opendir(directory_name);
    if (folder == NULL)
    {
        FILE *file;
        file = fopen(directory_name, "r");

        if (file != NULL)
        {
            directory_size += (double)calculate_file_size(file);
            fclose(file);
        }
    }
    else
    {
        while ((entry = readdir(folder)))
        {

            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                char *full_inner_directory_name = (char *)calloc(strlen(directory_name) + 1 + strlen(entry->d_name), sizeof(char) + 1);

                strcat(full_inner_directory_name, directory_name);
                strcat(full_inner_directory_name, "/");
                strcat(full_inner_directory_name, entry->d_name);

                directory_size += calculate_directory_size(full_inner_directory_name);
                free(full_inner_directory_name);
            }
        }
    }
    closedir(folder);
    return directory_size;
}

long int calculate_file_size(FILE *file)
{
    long int save_pos = ftell(file);
    fseek(file, 0L, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, save_pos, SEEK_SET);
    return file_size;
}

void calculate_count_of_digits()
{
    printf("%s\n", "Enter name of file with input:");
    move_carriage_to_next_raw(" ");
    char *input_filename = (char *)calloc(256, sizeof(char));
    fgets(input_filename, 255, stdin);
    input_filename = strtok(input_filename, "\n");
    
    char *text = (char *)calloc(256, sizeof(char));
    read_from_file(input_filename, &text, 255);

    size_t count_of_numbers_in_text = get_count_of_numbers_in_text(text);
    long *numbers = calloc(count_of_numbers_in_text, sizeof(long));
    get_numbers_in_text(text, numbers);

    printf("%s\n", "Enter name of file for output:");
    char *output_filename = (char *)calloc(256, sizeof(char));
    fgets(output_filename, 255, stdin);
    output_filename = strtok(output_filename, "\n");
    write_to_file(output_filename, numbers, count_of_numbers_in_text);

    free(input_filename);
    free(text);
    free(numbers);
    free(output_filename);
}

void read_from_file(char *filename, char **result, size_t buf_size)
{
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
        printf("%s\n", "Unable file");
        exit(1);
    }
    
    char * buf_str = (char *)calloc(buf_size, sizeof(char));

    while (fgets(buf_str, (int)buf_size, input_file) != NULL)
    {
        strcat(*result, buf_str);
    }
    free(buf_str);
}

void write_to_file(char *filename, long *numbers, size_t count_of_numbers)
{
    FILE *output_file = fopen(filename, "w");
    if (output_file != NULL)
    { 
        fclose(output_file);
    }

    output_file = fopen(filename, "ab");
    if (output_file == NULL)
    {
        printf("%s\n", "Unable file");
        exit(1);
    }

    for (size_t i = 0; i < count_of_numbers; i++)
    {
        fprintf(output_file, "%ld", *(numbers + i));
        if (i < count_of_numbers - 1)
            fprintf(output_file, "%s", "; ");
    }
    if (count_of_numbers == 0)
        fprintf(output_file, "%s", "No numbers");
    fprintf(output_file, "%c", '\n');

    fclose(output_file);
}

size_t get_count_of_numbers_in_text(char *text)
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

void get_numbers_in_text(char *text, long *numbers_in_text)
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