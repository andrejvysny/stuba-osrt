#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int r = rand() % (atoi(argv[2]) + 1 - atoi(argv[1])) + atoi(argv[1]), n, c=0;

   do{
        printf("Zadajte vaše číslo: ");
        scanf("%d", &n);
        c++;
        if(r == n){
            break;
        }
        if(r < n){
            printf("Zadajte menšie číslo!\n");
        }else{
            printf("Zadajte väčšie číslo!\n");
        }

    } while (r != n);

    printf("Zadali ste správne číslo: %d = %d\n Počet pokusov: %d\n", r,n,c);
    return 0;
}