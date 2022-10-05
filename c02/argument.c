#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int i = atoi(argv[1]);

    if ((i % 2) == 0 || i < 0) {
        printf("Input argument must be odd positive number!\n");
        return 1;
    }

    for (int y = 0; y < i; y++) {
        for (int x = 0; x < i; x++)
            printf((y<i/2 && x+1 > y && i - y>x || y>i/2 &&  x-1 < y && i - y<x+2 ||  y == i/2 && x == i/2) ? "*" : " ");
        printf("\n");
    }

    return 0;
}