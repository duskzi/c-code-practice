#include <stdio.h>

int strl(char *str)
{
    int i = 0; 
    while(str[i] != '\0') i++;
    return i;
}

void swapc(char *a, char *b)
{
    char temp = *a;
    *a   = *b;
    *b   = temp;
}

void strinv(char *string)
{
    // Find end of string
    int len = strl(string);

    // Set left pointer to start
    char *first = string;
    char *last = string + len - 1;

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
