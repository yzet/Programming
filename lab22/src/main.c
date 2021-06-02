#include "list.h"
#include "data.h"
#include "ui.h"
#include <time.h>
#include "check_agencies_info.h"

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