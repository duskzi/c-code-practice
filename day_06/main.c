#include <stdio.h>
// Exercise: Char frequency
// Let's get it

// Create array for char data
// Using {} here to fill array with 0

const int STR_LENGHT = 256;

int main(void)
{
    int char_data[256] = {0};

    char str[STR_LENGHT];

    FILE *f = fopen("./file.txt", "r");
    if(f == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int c;
    int i = 0;
    while((c = fgetc(f)) != EOF && i < 255)
    {
        str[i] = c;
        i++;
    }

    printf("%s", str);
}

// Read document char by char

// Store frequency of each one

