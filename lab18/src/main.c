#include "lib.h"

int main()
{
    // struct DynamicArray string_dynamic_array;
    // init_dynamic_array(&string_dynamic_array, sizeof(char));
    // void * inserted_data = (void *)"hello";

    // insert(&string_dynamic_array, inserted_data, strlen((char *)inserted_data), 0);
    // reduce(&string_dynamic_array, 1, 3);
    
    // free_dynamic_array(&string_dynamic_array);

    struct DynamicArray agencies_dynamic_array;
    init_dynamic_array(&agencies_dynamic_array, sizeof(struct Agency));

    void * new_agency = (void *)malloc(sizeof(struct Agency) * 1);
    struct Person director;
    set_person(&director, "Surname1", "Name1", "Email1@gmail.com");
    set_agency((struct Agency *)new_agency, true, "Agency Name 1", 3, director, Kharkiv);

    insert(&agencies_dynamic_array, new_agency, 1, 0);

    set_person(&director, "Surname2", "Name2", "Email2@gmail.com");
    set_agency((struct Agency *)new_agency, false, "Agency Name 2", 4, director, London);

    insert(&agencies_dynamic_array, new_agency, 1, 1);

    set_person(&director, "Surname3", "Name3", "Email3@gmail.com");
    set_agency((struct Agency *)new_agency, true, "Agency Name 3", 2, director, Kyiv);
    insert(&agencies_dynamic_array, new_agency, 1, 1);

    for (size_t i = 0; i < agencies_dynamic_array.length; i++)
    {
        print_agency((struct Agency *)agencies_dynamic_array.array + i, stdout);
        printf("%c", '\n');
    }

    reduce(&agencies_dynamic_array, 1, 2);

    for (size_t i = 0; i < agencies_dynamic_array.length; i++)
    {
        print_agency((struct Agency *)agencies_dynamic_array.array + i, stdout);
        printf("%c", '\n');
    }

    free_dynamic_array(&agencies_dynamic_array);
    free(new_agency);

    return 0;
}