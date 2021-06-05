/**
 * @mainpage
 * # Загальне завдання
 * 1. **Розробити** функцію, яка перевіряє вхідні дані за допомогою регулярних виразів;
 * 2. **Розробити** функцію, яка перевіряє дані, записані у полі на наявність двох слів за допомогою регулярних виразів;
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи розроблених функцій
 *
 * @author Zhuravlev Y.
 * @date 28-may-2021
 * @version 1.0
 */

#include "list.h"
#include "data.h"
#include "ui.h"
#include <time.h>
#include "check_agencies_info.h"

/**
* Головна функція.
*
* Послідовність дій:
* - викликає функцію запуску діалогового режиму
* @return успішний код повернення з програми (0)
*/
int main() {
    setbuf(stdout, 0);
#ifdef DEBUG
    time_t begin = clock();
    printf("Debug\n");
#endif
    start();
#ifdef DEBUG
    time_t end = clock();
    printf("Time: %f\n", (double) (end - begin) / CLOCKS_PER_SEC);
#endif

//    char alphabet[27];
//    for (int i = 'a'; i <= 'z'; i++) {
//        alphabet[i - 'a'] = i;
//    }
//    alphabet[26] = '\0';
//    bool result = is_std_regex("hello");
//    result = is_std_regex("?");
//    result = is_std_regex(alphabet);
//    result = is_std_regex("Hellohello?");
//    result = is_std_regex(".");
//    result = is_std_regex("Y");
//    result = is_std_regex("hello");
//    result = is_std_regex("3");
//    printf("%i", result);

    return 0;
}