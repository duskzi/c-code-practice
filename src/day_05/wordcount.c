#include <stdio.h>
#define WC_SIZE 256

int main(void)
{
    printf("Which file would you like to open? ");
    char fname[WC_SIZE];
    scanf("%s", fname);

    FILE *f = fopen(fname, "r");

    // If file not found or sum
    if(f == NULL)
    {
        printf("Can't open the file");
        return 1;
    }

    // Letter and words counters
    int l_count = 0;
    int w_count = 0;

    // Word state
    int is_word = 0;

    int c;
    while((c = fgetc(f)) != EOF)
    {
        if((c != ' ') && (c != '\n')){
            l_count++;
            is_word = 1;
        }

        if(is_word && ((c == ' ') || (c == '\n'))){  
            w_count++;
            is_word = 0;
        }
    }
    if(is_word){
        is_word = 0;
        w_count++;
    }

    printf("The %s has %i letters, and %i words", fname, l_count, w_count);
    fclose(f); 
}