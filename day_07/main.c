#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip_a_coin(void){
    return rand()%2;
}

int main(void)
{
    const int TIMES = 90000000;

    srand(time(NULL));

    char parent1[2];
    char parent2[2];

    parent1[0] = 'A';
    parent1[1] = 'a';

    parent2[0] = 'A';
    parent2[1] = 'a';

    char son1;
    char son2;

    // Count
    int AA = 0;
    int Aa = 0;
    int aa = 0;

    int i = 0;
    while(i < TIMES)
    {   

        son1 = parent1[flip_a_coin()];
        son2 = parent2[flip_a_coin()];

        // Prevent from 'Aa' be 'aA'
        if(son1 > son2){
            char temp = son1;
            son1 = son2;
            son2 = temp;
        }

        if(son1=='A' && son2=='A') {AA++;}
        else if(son1=='A' && son2=='a') {Aa++;}
        else if(son1=='a' && son2=='a') {aa++;}

        i++;
    }
    printf(" Theory - Quantity - Percentage  |\n");
    printf("--------------------------------´\n");
    printf("~25%%  |  AA: %d  |  %.2f%%\n", AA, (float)AA/TIMES*100.0);
    printf("~50%%  |  Aa: %d  |  %.2f%%\n", Aa, (float)Aa/TIMES*100.0);
    printf("~25%%  |  aa: %d  |  %.2f%%\n", aa, (float)aa/TIMES*100.0);
    printf("\nTimes: %d\n", TIMES);
    return 0;
}