#include <stdio.h>
#include <unistd.h>

#define PROGRESS_MAX 10

int main(void)
{
    for(int i=0; i<=PROGRESS_MAX; i++)
    {
        usleep(500000);
        printf("\r");
        printf("[");
        int p = 0;
        while(p < PROGRESS_MAX)
        {
            p++;
            for(int i=0; i<PROGRESS_MAX; i++)
            {
                if(i < p)
                {
                    printf("#");
                }
                else
                {
                    printf("-");
                }
            }
        }

        printf("]");
        fflush(stdout);
    }

    return 0;
}