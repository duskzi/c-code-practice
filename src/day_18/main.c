#include <stdarg.h>
#include <stdio.h>

float average(int count, ...){
    va_list arguments;
    va_start(arguments, count);

    int arg = 0;
    float sum;

    while(arg < count) {
        sum += va_arg(arguments, int);
        arg++;
    }

    return sum/count;
}

int main(void)
{
    float average_scores = average(8, 4, 8, 92, 2.6, 9, 1, 2, 3);
    printf("Average: %.2f", average_scores);
}
