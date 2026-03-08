#include <stdio.h>
#include <unistd.h>

#define PROGRESS 100
#define BAR_WIDTH 16
int main(void)
{
    for(int i=0; i<=PROGRESS; i+=1)
    {
        usleep(32000);
        printf("\r");
        printf("Progress: [");

        for(int p=0; p<BAR_WIDTH; p++)
        {
            if(p < ((float)i/PROGRESS*BAR_WIDTH))
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }

        printf("]");
        printf(" %i%%", i);
        fflush(stdout);
    }
    return 0;
}
