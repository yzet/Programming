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