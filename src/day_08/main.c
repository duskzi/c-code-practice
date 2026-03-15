#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Genes
// x: Allele 1
// y: Allele 2
typedef struct plants{
    // 1 -> A
    // 0 -> a
    int x;
    int y;
} plants;

int evenodd()
{
    return rand()%2;
}

void get_genes(plants *A, plants *B, plants *Son)
{
    if(evenodd())   {Son->x = A->x;}
    else            {Son->x = A->y;}

    if(evenodd())   {Son->y = B->x;}
    else            {Son->y = B->y;}

    // Swap to prevent allele 'aA'
    if(Son->y > Son->x)
    {
        Son->x = 1 - Son->x;
        Son->y = 1 - Son->y;
    }
}

int main(void)
{
    srand(time(NULL));

    plants Father = {1, 1};
    plants Mother = {1, 0};
    plants Son;
    
    int TIMES = 8000000;
    int i = 0;
    int AA = 0;
    int Aa = 0;
    int aa = 0;
    while(i < TIMES)
    {
        get_genes(&Father, &Mother, &Son);

        if(Son.x && Son.y) AA++;
        else if(Son.x || Son.y) Aa++;
        else if(!(Son.x && Son.y)) aa++;
        i++;
    }

    printf("AA: %.2f, Aa: %.2f, aa: %.2f", (float)AA/TIMES*100.0, (float)Aa/TIMES*100.0, (float)aa/TIMES*100.0);

    return 0;
}