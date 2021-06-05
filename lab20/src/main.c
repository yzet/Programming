/**
 * @mainpage
 * # Загальне завдання
 * 1. **Додати** до роботи програми модливість виводу дати та часу виклику функції, ім'я поточної функції,
 * виведення загального часу роюоти програми при макровизначенні DEBUG;
 *
 * @author Zhuravlev Y.
 * @date 29-may-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи роботи розроблених функцій
 *
 * @author Zhuravlev Y.
 * @date 28-may-2021
 * @version 1.0
 */

#include "list.h"
#include "data.h"
#include "ui.h"
#include <time.h>


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

    return 0;
}