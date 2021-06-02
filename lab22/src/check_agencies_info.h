#ifndef _CHECK_AGENCIES_INFO_
#define _CHECK_AGENCIES_INFO_

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool is_std_regex(char * string);
bool is_two_or_more_words_regex(char * string);
bool regex_result_to_bool(int result);


#endif