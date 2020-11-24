#include <stdarg.h>

int get_indicator_of_order_in_sequence(int count_of_elements, ...);

int main()
{
    #define COUNT_OF_ELEMENTS_IN_SEQUENCE 5
    
    int indicator_of_order = get_indicator_of_order_in_sequence(COUNT_OF_ELEMENTS_IN_SEQUENCE, 4, 1, 6, 3, 2);

    return 0;
}

int get_indicator_of_order_in_sequence(int count_of_elements, ...)
{
    int indicator_of_order = 0;
    va_list factor;
    va_start(factor, count_of_elements);
    for (int i = 0; i < count_of_elements - 1; i++){
        for (int j = i + 1; j < count_of_elements; j++){
            if (va_arg(factor, int) < va_arg(factor, int)) indicator_of_order++;
        }
    }
    va_end(factor);
    return indicator_of_order;
}
