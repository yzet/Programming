#include "check_agencies_info.h"

// const char * std_regex = "[A-Z0-9]([A-Za-z0-9]*(\.|,|\?)?)*";
const char * two_or_more_words_regex = "^[A-Z][a-zA-Z]* ((( |-|$)?[a-zA-Z])*|$)?$";
// ^[^ ]+[ \t][^ ]+
bool is_std_regex(char *string)
{
    //char std_regex[] = "^[A-Z0-9]((([a-zA-Z0-9]+)(/.|/?)?)+)$";
    char std_regex[] = "^[A-Z][a-zA-Z]*((( |-|$)?[a-zA-Z])*|$)?$";
    regex_t regex;
    int return_value = regcomp(&regex, std_regex, REG_EXTENDED);
    return_value = regexec(&regex, string, 0, NULL, 0);
    regfree(&regex);
    return regex_result_to_bool(return_value);
}

bool is_two_or_more_words_regex(char *string)
{
    regex_t regex;
    int return_value = regcomp(&regex, two_or_more_words_regex, REG_EXTENDED);
    return_value = regexec(&regex, string, 0, NULL, 0);
    regfree(&regex);
    return regex_result_to_bool(return_value);
}

bool regex_result_to_bool(int result)
{
    bool bool_result;
    if (result == 0)
        bool_result = true;
    else if (result == REG_NOMATCH)
        bool_result = false;
    else
    {
        printf("Regex error");
        exit(1);
    }
    return bool_result;
}
