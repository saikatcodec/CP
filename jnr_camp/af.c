#include <stdio.h>
#include <stdlib.h>

void pr() {
    printf("Yu");
    return;
}

int *fun(int a, int b) {
    int sum = a + b;
    int *ptr = (int *)malloc(4);
    *ptr = a + b;
    return ptr;
}

int main() {
    int *sum = fun(13, 13);
    printf("%d", *sum);
    free(sum);

    return 0;
}