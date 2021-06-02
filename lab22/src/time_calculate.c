#include "time_calculate.h"

void print_function_and_now_time(const char function_name[33], time_t now_time) {
    putc('\n', stdout);
    struct tm *now_time_ptr;
    now_time_ptr = localtime(&now_time);
    printf("Time: %s", asctime(now_time_ptr));
    printf("Function: %s\n", function_name);
    putc('\n', stdout);
}

void print_time_delta(clock_t begin, clock_t end) {
    double  time = (double)(end - begin) / CLOCKS_PER_SEC;
//    printf("Time: %d\n", (double) (end - begin) / CLOCKS_PER_SEC);
    printf("Time: %f\n", time);

}

