#include "ui.h"

void start()
{
    struct AgenciesList agencies_list;
    init_agencies_list(&agencies_list);
    char *command = (char *)calloc(STRING_SIZE, sizeof(char));
    char *path_to_file = (char *)calloc(STRING_SIZE, sizeof(char));
    enum Cities city;
    struct Agency agency;
    int index;

    while (true)
    {
        print_main_menu(command);
        if (strcmp(command, "quit") == 0)
        {
            free_agencies_list(&agencies_list);
            exit(0);
        }
        if (isdigit(*(command + 0)))
        {
            long command_int = strtol(command, NULL, 10);
            switch (command_int)
            {
            case 1:
                print_list_to_file_menu(path_to_file);
                FILE *output_file = fopen(path_to_file, "w");
                if (output_file != NULL)
                {
                    print_agencies_list_to_file(&agencies_list, output_file);
                    printf("%s\n", "AgenciesList written.");
                    fclose(output_file);
                }
                else
                {
                    printf("%s\n", "No such file.");
                }
                break;
            case 2:
                print_list_on_screen_menu();
                print_agencies_list_on_screen(&agencies_list);
                break;
            case 3:
                print_read_list_from_file_menu(path_to_file);
                FILE *input_file = fopen(path_to_file, "r");
                if (input_file != NULL)
                {
                    // print_agencies_list_to_file(agencies_list, output_file);
                    char *text = (char *)calloc(STRING_SIZE, sizeof(char));
                    read_agencies_text_file(text, STRING_SIZE - 1);
                    char **agencies_text = (char **)(calloc(0, sizeof(char *)));
                    size_t count_of_agencies = split(&agencies_text, text, "\n");
                    set_agencies_list_from_text_array(&agencies_list, agencies_text, count_of_agencies);
                    printf("%s\n", "AgenciesList read.");
                    fclose(input_file);
                }
                else
                {
                    printf("%s\n", "No such file.");
                }
                break;
            case 4:
                print_search_object_by_city_menu(&city, &index);
                struct AgenciesListElement *searched_element = NULL;
                get_element_with_city_from_index(&agencies_list, (size_t)index, city, &searched_element);
                if (searched_element != NULL)
                {
                    printf("%s\n", "Founded item");
                    print_agency(&searched_element->data, stdout);
                }
                else
                {
                    printf("%s\n", "No items found");
                }
                break;
            case 5:
                print_sort_by_years_on_market_menu();
                sort_agencies_list_by_years_on_market(&agencies_list);
                print_agencies_list_on_screen(&agencies_list);
                break;
            case 6:
                print_add_element_to_list_menu(&agency, &agencies_list, &index);
                printf("%s\n", "Agency added");
                break;
            case 7:
                print_delete_element_from_list_by_index_menu(&index);
                delete_element_from_list_by_index(&agencies_list, (size_t)index);
                break;
            default:
                printf("%s\n", "Not available command.");
                // print_main_menu();
                break;
            }
        }
        else
        {
            printf("%s\n", "Not available command.");
        }
    }
}

void get_info_from_console(char *to, size_t max_to_length, char *message)
{
    puts(message);
    fgets(to, (int)max_to_length, stdin);
    to = strtok(to, "\n");
}

void print_main_menu(char *command)
{
    printf("%s\n", "AgenciesList Main menu.");
    printf("%s\n", "1 - Print AgenciesList to file");
    printf("%s\n", "2 - Print AgenciesList on screen");
    printf("%s\n", "3 - Read AgenciesList from file");
    printf("%s\n", "4 - Search object by city");
    printf("%s\n", "5 - Sort AgenciesList by years on market");
    printf("%s\n", "6 - Add element to list");
    printf("%s\n", "7 - Delete element from list");

    get_info_from_console(command, STRING_SIZE - 1, "Enter command or quit for quit:");
}

void print_list_to_file_menu(char *path_to_file)
{
    get_info_from_console(path_to_file, STRING_SIZE - 1, "Enter path to file for print:");
}

void print_list_on_screen_menu()
{
    printf("%s\n", "AgenciesList:");
}

void print_read_list_from_file_menu(char *path_to_file)
{
    get_info_from_console(path_to_file, STRING_SIZE - 1, "Enter path to file for read:");
}

void print_search_object_by_city_menu(enum Cities *city, int *index)
{
    char *input = (char *)calloc(STRING_SIZE, sizeof(char));
    printf("%s\n", "0 - Kharkiv");
    printf("%s\n", "1 - Kyiv");
    printf("%s\n", "2 - London");
    get_info_from_console(input, STRING_SIZE - 1, "Enter city:");
    *city = (enum Cities)strtol(input, NULL, 10);
    free(input);
    input = (char *)calloc(STRING_SIZE, sizeof(char));
    get_info_from_console(input, STRING_SIZE - 1, "Enter start index:");
    *index = (int)strtol(input, NULL, 10);
    free(input);
}

void print_sort_by_years_on_market_menu()
{
    printf("%s\n", "AgenciesList sorted.");
}

void print_add_element_to_list_menu(struct Agency *agency, struct AgenciesList *agencies_list, int *index)
{
    char *input = (char *)calloc(STRING_SIZE, sizeof(char));
    get_info_from_console(input, STRING_SIZE - 1, "Enter director surname:");
    char surname[STRING_SIZE];
    strcpy(surname, input);
    agency->director.surname = surname;
    // free(input);
    get_info_from_console(input, STRING_SIZE - 1, "Enter director name:");
    char name[STRING_SIZE];
    strcpy(name, input);
    agency->director.name = name;
    // free(input);
    get_info_from_console(input, STRING_SIZE - 1, "Enter director email:");
    char email[STRING_SIZE];
    strcpy(email, input);
    agency->director.email = email;
    // free(input);
    get_info_from_console(input, STRING_SIZE - 1, "Agency has a weekend?(y/n):");
    bool is_weekends = false;
    if (*(input) == 'y')
        is_weekends = true;
    agency->is_weekends = true;
    // free(input);
    get_info_from_console(input, STRING_SIZE - 1, "Enter agency name:");
    char agency_name[STRING_SIZE];
    strcpy(agency_name, input);
    agency->name = agency_name;
    // free(input);
    get_info_from_console(input, STRING_SIZE - 1, "Enter agency years on market:");
    agency->years_on_market = (size_t)strtol(input, NULL, 10);
    // free(input);
    printf("%s\n", "0 - Kharkiv");
    printf("%s\n", "1 - Kyiv");
    printf("%s\n", "2 - London");
    get_info_from_console(input, STRING_SIZE - 1, "Enter city:\n");
    agency->city = (enum Cities)strtol(input, NULL, 10);
    // free(input);
    get_info_from_console(input, STRING_SIZE - 1, "Enter index or push_back:");
    if (strcmp(input, "push_back") == 0)
    {
        add_element_to_list_end(agencies_list, agency);
    }
    else
    {
        *index = (int)strtol(input, NULL, 10);
        add_element_to_list_by_index(agencies_list, agency, (size_t)*index);
    }
    free(input);
}

void print_delete_element_from_list_by_index_menu(int *index)
{
    char *input = (char *)calloc(STRING_SIZE, sizeof(char));
    get_info_from_console(input, STRING_SIZE - 1, "Enter index:");
    *index = (int)strtol(input, NULL, 10);
    free(input);
}
