#include <stdio.h>

#define CHAR_LENGHT 256

int main(void)
{
    char char_data[CHAR_LENGHT] = {0};

    FILE *f = fopen("./file.txt", "r");
    if(f == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int c;
    int i = 0;
    // Read document char by char
    while((c = fgetc(f)) != EOF)
    {
        // Store frequency of each one
        char_data[c] += 1;
        i++;
    }

    // Listen, brain
    // J      -> char
    // data   -> Frequency
    // J + %d -> Ascci value
    int data;
    for(int j=0; j<CHAR_LENGHT; j++)
    {  
        data = char_data[j];
        if(!(data == 0 || j=='\n' || j==' '))
        {
            printf("%c: %d | ascci value: %d\n", j, data, j);
        }
    }

    fclose(f);
}