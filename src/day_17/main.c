#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i <= 107) {
        printf("  %d : ", i);
        printf("\033[%dm SEIS\033[0m \n", i);
        i++;
    }
    
}