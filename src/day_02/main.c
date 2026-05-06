#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define true 1
#define false 0

#define PRGSBAR_WIDTH 16

void print_progress(float prgs)
{
        printf("\r");
        printf("Progress: [");

        for(int p=0; p<PRGSBAR_WIDTH; p++)
        {
            if(p < ((float)prgs/1.0*PRGSBAR_WIDTH))
            {
                printf("#");
            }
            else
            {
                printf("-");
            }
        }

        printf("]");
        printf(" %.2f%%", prgs*100.0);
        fflush(stdout);
}

int main(void)
{
    float i=0;
    while(true)
    {
        i+=0.45;
        usleep(240000);
        print_progress(sin(i)*0.5 + 0.5);
    }
    return 0;
}
