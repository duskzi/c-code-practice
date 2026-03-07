/*
DISCLAIMER:

Dear reader,

I'm not using pointers to my calculator because
a pointer is, in my PC, 8 bytes long, and I do
not want to spend precious 2 bytes of memory.

Thanks for reading, Dusk.
*/

#include <stdio.h>


float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}


int main(void)
{
    int cont = 1;

    while(cont) {
        printf("What operation would you choose?\n\n");

        printf("[1] Add\n");
        printf("[2] Subtract\n");
        printf("[3] Divide\n");
        printf("[4] Multiply\n");
        printf("[0] Exit\n");

        int option;
        scanf("%i", &option);

        if(option == 0.0)
        {
            cont = 0;
            return 0;
        }

        float a, b;
        printf("Type your first number\n");
        scanf("%f", &a);
        printf("Type your second number\n");
        scanf("%f", &b);

        float result;

        switch(option) {
            case 1:
                result = add(a, b);
                break;
            case 2:
                result = subtract(a, b);
                break;
            case 3:
                result = divide(a, b);
                break;
            case 4:
                result = multiply(a, b);
                break;
        }
        printf("-> %f\n", result);
    }

    return 0;
}
