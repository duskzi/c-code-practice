#include <stdio.h>

#define ARRAY_MAX 5

int main(void)
{
    int ind = 0;
    float num = 0;

    float array[ARRAY_MAX];

    while(ind < ARRAY_MAX)
    {
        printf("Pick a number to append in array: \n");
        scanf("%f", &num);

        array[ind] = num;
        ind++;
    }
    
    float sum = 0, lowest = array[0], highest = array[0];
    for(int i=0; i<ARRAY_MAX; i++)
    {
        sum += array[i];

        if(array[i] < lowest) lowest = array[i];
        if(array[i] > highest) highest = array[i];
    }

    printf("Your array has a lenght of %d\n", ind);
    printf("Your array has a sum of %.2f\n", sum);
    printf("The lowest value: %.2f\nThe highest value: %.2f\n", lowest, highest);

    return 0;
}