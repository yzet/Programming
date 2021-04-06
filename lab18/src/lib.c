#include "lib.h"

void init_dynamic_array(struct DynamicArray *dynamic_array, size_t size_of_elements)
{
    dynamic_array->array = (void *)malloc(size_of_elements * 0);
    dynamic_array->length = 0;
    dynamic_array->size_of_elements = size_of_elements;
}

void free_dynamic_array(struct DynamicArray *dynamic_array)
{
    free(dynamic_array->array);
}

void insert(struct DynamicArray *dynamic_array, void *inserted_data, size_t count_of_elements, size_t from_index)
{
    size_t new_length = dynamic_array->length + count_of_elements;
    void *new_array = (void *)malloc(new_length * dynamic_array->size_of_elements);
    // for (size_t i = 0; i < new_length; i++)
    // {
        memset((new_array), '\0', dynamic_array->size_of_elements * new_length);
    // }
    if (from_index > dynamic_array->length)
        from_index = dynamic_array->length;

    size_t last_free_index_in_new_array = 0;
    for (; last_free_index_in_new_array < from_index; last_free_index_in_new_array++)
    {
        // memcpy((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + last_free_index_in_new_array), dynamic_array->size_of_elements);
        memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + last_free_index_in_new_array * dynamic_array->size_of_elements), dynamic_array->size_of_elements);
    }
    for (size_t i = 0; i < count_of_elements; i++)
    {
        // memcpy((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (inserted_data + i), dynamic_array->size_of_elements);
        memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (inserted_data + i * dynamic_array->size_of_elements), dynamic_array->size_of_elements);
        last_free_index_in_new_array++;
    }
    for (size_t i = from_index; i < dynamic_array->length; i++)
    {
        // memcpy((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + i), dynamic_array->size_of_elements);
        memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + i * dynamic_array->size_of_elements), dynamic_array->size_of_elements);
        last_free_index_in_new_array++;
    }

    free(dynamic_array->array);
    dynamic_array->array = new_array;
    dynamic_array->length = new_length;
}

void reduce(struct DynamicArray *dynamic_array, size_t start_index, size_t end_index)
{
    if (start_index < dynamic_array->length && end_index < dynamic_array->length)
    {
        size_t new_length = dynamic_array->length - (end_index - start_index + 1);
        void *new_array = (void *)malloc(new_length * dynamic_array->size_of_elements);
        for (size_t i = 0; i < new_length; i++)
        {
            memset((new_array + i), '\0', dynamic_array->size_of_elements);
        }
        size_t last_free_index_in_new_array = 0;
        for (; last_free_index_in_new_array < start_index; last_free_index_in_new_array++)
        {
            // memcpy((new_array + last_free_index_in_new_array), (dynamic_array->array + last_free_index_in_new_array), dynamic_array->size_of_elements);
            memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + last_free_index_in_new_array * dynamic_array->size_of_elements), dynamic_array->size_of_elements);
        }
        for (size_t i = end_index + 1; i < dynamic_array->length; i++)
        {
            // memcpy((new_array + last_free_index_in_new_array), (dynamic_array->array + i), dynamic_array->size_of_elements);
            memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + i * dynamic_array->size_of_elements), dynamic_array->size_of_elements);
        }
        free(dynamic_array->array);
        dynamic_array->array = new_array;
        dynamic_array->length = new_length;
    }
    else
    {
        puts("Reduce: Not indecies in array\n");
    }
}

void print_dynamic_char_array(struct DynamicArray *dynamic_array, FILE *file)
{
    for (size_t i = 0; i < dynamic_array->length; i++)
    {
        putc(*(char *)(dynamic_array->array + i), file);
    }
}

void set_person(struct Person *person, char *surname, char *name, char *email)
{
    // strcpy(person->surname, surname);
    // strcpy(person->name, name);
    // strcpy(person->email, email);
    person->surname = surname;
    person->name = name;
    person->email = email;

}

void set_agency(struct Agency *agency, bool is_weakends, char *agency_name, size_t years_on_market, struct Person agency_director, enum Cities city)
{
    agency->is_weekends = is_weakends;
    agency->name = agency_name;
    // strcpy(agency->name, agency_name);
    agency->years_on_market = years_on_market;
    agency->director = agency_director;
    agency->city = city;
}

void print_agency(struct Agency *agency, FILE *file)
{
    char *output = (char *)calloc(2 * STRING_SIZE, sizeof(char));

    char *is_weekends_string = (char *)calloc(STRING_SIZE, sizeof(char));
    is_weekends_to_string(&is_weekends_string, agency->is_weekends);

    char *city_string = (char *)calloc(STRING_SIZE, sizeof(char));
    cities_to_string(&city_string, agency->city);

    sprintf(output, "Agency Name: %s\nDirector: %s %s Email: %s\nWeekends: %s\nYears on market: %d\nCity: %s\n",
            agency->name, agency->director.name, agency->director.surname, agency->director.email,
            is_weekends_string, (int)agency->years_on_market, city_string);

    fputs(output, file);

    free(is_weekends_string);
    free(city_string);
    free(output);
}

void is_weekends_to_string(char **is_weekends_string, bool is_weekeds)
{
    if (is_weekeds)
    {
        strcpy(*is_weekends_string, "Yes");
    }
    else
    {
        strcpy(*is_weekends_string, "No");
    }
}

void cities_to_string(char **city_string, enum Cities city)
{
    switch (city)
    {
    case Kharkiv:
        strcpy(*city_string, "Kharkiv");
        break;
    case Kyiv:
        strcpy(*city_string, "Kyiv");
        break;
    case London:
        strcpy(*city_string, "London");
        break;
    default:
        break;
    }
}