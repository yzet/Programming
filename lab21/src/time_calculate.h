#ifndef LAB20_TIME_CALCULATE_H
#define LAB20_TIME_CALCULATE_H

#include <time.h>
#include <stdio.h>

void print_function_and_now_time(const char function_name[33], time_t now_time);
void print_time_delta(clock_t begin, clock_t end);

#endif
