#include <stdio.h>

void swapc(char *a, char *b)
{
    char temp = *a;
    *a   = *b;
    *b   = temp;
}

void strinv(char *string)
{
    // Set left pointer to start
    char *first = string;
    char *last = string;

    // Prevent from using str lenght
    while(*last != '\0') last++;
    last--;

    while(first < last)
    {
        swapc(first, last);
        first++;
        last--;
    }
}

int main(void)
{
    char string[128];
    scanf("%127s", string);

    strinv(string);

    printf("->%s", string);

    return 0;
}