#include "list.h"

int init_agencies_list(struct AgenciesList *agencies_list)
{
    agencies_list->head = NULL;
    return 0;
}

int add_element_to_list_by_index(struct AgenciesList *agencies_list, struct Agency *element, size_t index)
{
    struct AgenciesListElement *current = agencies_list->head;

    if (current == NULL)
    {
        agencies_list->head = (struct AgenciesListElement *)malloc(sizeof(struct AgenciesListElement));
        agencies_list->head->next = NULL;
        agencies_list->head->prev = NULL;

        char *agency_name = calloc(strlen(element->name) + 1, sizeof(char));
        strcpy(agency_name, element->name);

        char *agency_director_name = calloc(strlen(element->director.name) + 1, sizeof(char));
        strcpy(agency_director_name, element->director.name);

        char *agency_director_surname = calloc(strlen(element->director.surname) + 1, sizeof(char));
        strcpy(agency_director_surname, element->director.surname);

        char *agency_director_email = calloc(strlen(element->director.email) + 1, sizeof(char));
        strcpy(agency_director_email, element->director.email);

        memcpy(&agencies_list->head->data, element, sizeof(struct Agency));
        agencies_list->head->data.name = agency_name;
        agencies_list->head->data.director.name = agency_director_name;
        agencies_list->head->data.director.surname = agency_director_surname;
        agencies_list->head->data.director.email = agency_director_email;

        agencies_list->tail = agencies_list->head;
        return 0;
    }

    if (index == 0)
    {
        struct AgenciesListElement *new_object = (struct AgenciesListElement *)malloc(sizeof(struct AgenciesListElement));
        new_object->next = current;
        current->prev = new_object;
        new_object->prev = NULL;
        agencies_list->head = new_object;

        char *agency_name = calloc(strlen(element->name) + 1, sizeof(char));
        strcpy(agency_name, element->name);

        char *agency_director_name = calloc(strlen(element->director.name) + 1, sizeof(char));
        strcpy(agency_director_name, element->director.name);

        char *agency_director_surname = calloc(strlen(element->director.surname) + 1, sizeof(char));
        strcpy(agency_director_surname, element->director.surname);

        char *agency_director_email = calloc(strlen(element->director.email) + 1, sizeof(char));
        strcpy(agency_director_email, element->director.email);

        memmove(&new_object->data, element, sizeof(struct Agency));

        new_object->data.name = agency_name;
        new_object->data.director.name = agency_director_name;
        new_object->data.director.surname = agency_director_surname;
        new_object->data.director.email = agency_director_email;
        return 0;
    }

    for (size_t i = 0; i < index - 1 && current->next != NULL; i++)
    {
        current = current->next;
    }

    struct AgenciesListElement *new_object = (struct AgenciesListElement *)malloc(sizeof(struct AgenciesListElement));

    char *agency_name = calloc(strlen(element->name) + 1, sizeof(char));
    strcpy(agency_name, element->name);

    char *agency_director_name = calloc(strlen(element->director.name) + 1, sizeof(char));
    strcpy(agency_director_name, element->director.name);

    char *agency_director_surname = calloc(strlen(element->director.surname) + 1, sizeof(char));
    strcpy(agency_director_surname, element->director.surname);

    char *agency_director_email = calloc(strlen(element->director.email) + 1, sizeof(char));
    strcpy(agency_director_email, element->director.email);

    memcpy(&new_object->data, element, sizeof(struct Agency));

    new_object->data.name = agency_name;
    new_object->data.director.name = agency_director_name;
    new_object->data.director.surname = agency_director_surname;
    new_object->data.director.email = agency_director_email;

    new_object->next = current->next;
    if (new_object->next != NULL)
        new_object->next->prev = new_object;
    else
        agencies_list->tail = new_object;
    new_object->prev = current;
    current->next = new_object;

    return 0;
}

int add_element_to_list_end(struct AgenciesList *agencies_list, struct Agency *element)
{
    struct AgenciesListElement *current = agencies_list->head;

    struct AgenciesListElement *new_object = (struct AgenciesListElement *)malloc(sizeof(struct AgenciesListElement));

    char *agency_name = calloc(strlen(element->name) + 1, sizeof(char));
    strcpy(agency_name, element->name);

    char *agency_director_name = calloc(strlen(element->director.name) + 1, sizeof(char));
    strcpy(agency_director_name, element->director.name);

    char *agency_director_surname = calloc(strlen(element->director.surname) + 1, sizeof(char));
    strcpy(agency_director_surname, element->director.surname);

    char *agency_director_email = calloc(strlen(element->director.email) + 1, sizeof(char));
    strcpy(agency_director_email, element->director.email);

    memmove(&new_object->data, element, sizeof(struct Agency));
    new_object->data.name = agency_name;
    new_object->data.director.name = agency_director_name;
    new_object->data.director.surname = agency_director_surname;
    new_object->data.director.email = agency_director_email;

    new_object->next = NULL;

    if (current == NULL)
    {
        new_object->prev = NULL;
        agencies_list->head = new_object;
        agencies_list->tail = new_object;
        return 0;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_object;
    new_object->prev = current;

    agencies_list->tail = new_object;

    return 0;
}

int delete_element_from_list_by_index(struct AgenciesList *agencies_list, size_t index)
{
    struct AgenciesListElement *current = agencies_list->head;

    for (size_t i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("%s\n", "No index in list");
        return 1;
    }

    if (current->prev == NULL)
    {
        agencies_list->head = current->next;
        if (agencies_list->head != NULL)
            agencies_list->head->prev = NULL;
    }
    else
    {
        current->prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    free(current->data.name);
    free(current->data.director.name);
    free(current->data.director.surname);
    free(current->data.director.email);
    free(current);
    return 0;
}

int get_element_by_index(struct AgenciesList *agencies_list, struct AgenciesListElement **element, size_t index)
{
    struct AgenciesListElement *current = agencies_list->head;
    for (size_t i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }
    *element = current;
    return 0;
}

size_t get_list_length(struct AgenciesList *agencies_list)
{
    size_t list_length = 0;
    struct AgenciesListElement *current = agencies_list->head;
    while (current != NULL)
    {
        list_length++;
        current = current->next;
    }
    return list_length;
}

int sort_agencies_list_by_years_on_market(struct AgenciesList *agencies_list)
{
    struct AgenciesListElement *current;
    struct AgenciesListElement *next;

    size_t list_length = get_list_length(agencies_list);

    for (size_t i = 0; i < list_length; i++)
    {
        for (size_t j = 0; j < list_length - 1; j++)
        {
            get_element_by_index(agencies_list, &current, j);
            get_element_by_index(agencies_list, &next, j + 1);

            if (agencies_cmp_by_years_on_market(&current->data, &next->data) == 1)
            {
                current->next = next->next;
                next->next = current;
                if (current == agencies_list->head)
                    agencies_list->head = next;
                next->prev = current->prev;
                current->prev = next;
                if (next->prev != NULL)
                    next->prev->next = next;
                if (current->next != NULL)
                    current->next->prev = current;
            }
        }
    }
    return 0;
}

int get_element_with_city_from_index(struct AgenciesList *agencies_list, size_t from_index, enum Cities city, struct AgenciesListElement **element)
{
    size_t list_length = get_list_length(agencies_list);

    *element = NULL;

    struct AgenciesListElement *current = NULL;

    for (size_t i = from_index; i < list_length; i++)
    {
        get_element_by_index(agencies_list, &current, i);
        if (current->data.city == city)
        {
            *element = current;
            break;
        }
    }

    return 0;
}

int free_agencies_list(struct AgenciesList *agencies_list)
{
    struct AgenciesListElement *current = agencies_list->head;
    if (current != NULL)
    {
        while (current->next != NULL)
        {
            current = current->next;
            if (current != NULL)
            {
                free(current->prev->data.name);
                free(current->prev->data.director.name);
                free(current->prev->data.director.surname);
                free(current->prev->data.director.email);
                free(current->prev);
            }
            else
                break;
        }
        free(current->data.name);
        free(current->data.director.name);
        free(current->data.director.surname);
        free(current->data.director.email);
        free(current);
    }
    // free(agencies_list);
    return 0;
}

void print_agencies_list_on_screen(struct AgenciesList *agencies_list)
{
    struct AgenciesListElement *current = agencies_list->head;
    while (current != NULL)
    {
        print_agency(&current->data, stdout);
        current = current->next;
        printf("\n");
    }
}

void print_agencies_list_on_screen_reverse(struct AgenciesList *agencies_list)
{
     struct AgenciesListElement *current = agencies_list->tail;
     while (current != NULL)
     {
        print_agency(&current->data, stdout);
        current = current->prev;
        printf("\n");
     }
     
}

void print_agencies_list_to_file(struct AgenciesList *agencies_list, FILE *file)
{
    struct AgenciesListElement *current = agencies_list->head;
    while (current != NULL)
    {
        write_agency_data(&current->data, file);
        if (current->next != NULL)
            fputc('\n', file);
        current = current->next;
    }
}

int set_agencies_list_from_text_array(struct AgenciesList *agencies_list, char **agencies_text_array, size_t count_of_agencies)
{
    if (agencies_list->head != NULL)
    {
        free_agencies_list(agencies_list);
        init_agencies_list(agencies_list);
    }
    for (size_t agency_index = 0; agency_index < count_of_agencies; agency_index++)
    {
        char **agency_info = (char **)calloc(0, sizeof(char *));
        size_t number_of_characteristic = set_agency_info(&agency_info, agencies_text_array, agency_index);
        bool is_weekends = false;
        if (strtol(*(agency_info + IsWeekendsField), NULL, 10) == 1)
            is_weekends = true;
        struct Agency new_agency = {is_weekends, *(agency_info + AgencyNameField), (size_t)strtol(*(agency_info + YearsOnMarketField), NULL, 10), {*(agency_info + SurnameField), *(agency_info + NameField), *(agency_info + EmailField)}, (unsigned int)strtol(*(agency_info + CityField), NULL, 10)};
        add_element_to_list_end(agencies_list, &new_agency);
        for (size_t i = 0; i < number_of_characteristic; i++)
        {
            free(*(agency_info + i));
        }
        free(agency_info);
    }
    return 0;
}