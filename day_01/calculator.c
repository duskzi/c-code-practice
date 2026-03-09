/*
DISCLAIMER:

Dear reader,

I'm not using pointers to my calculator because
a pointer is, in my PC, 8 bytes long, and I do
not want to spend precious 2 bytes of memory.

Thanks for reading, Dusk.
*/

#include <stdio.h>

float add(float a, float b){
    return a + b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b){   
    return a / b;
}

int scan_input(float *input){
    if(scanf("%f", input) != 1)
    {
        printf("Invalid input\n");
        return 1;
    }
    // Safety purposes
    return 0;
}

int main(void){
    // True because i'm returning with 0
    while(1) {
        printf("What operation would you choose?\n");

        printf("[1] Add\n");
        printf("[2] Subtract\n");
        printf("[3] Divide\n");
        printf("[4] Multiply\n");
        printf("[0] Exit\n");

        int option;

        // Don't know why BUT it's a buffer
        // issue that happens
        if (scanf("%i", &option) != 1) {
            printf("Invalid option\n");
            while (getchar() != '\n');
            continue;
        }

        if(option == 0){
            return 0;
        }

        if(option < 1 || option > 4){
            printf("Invalid option\n");
            return 0;
        }

        float result;
        float a, b;
        printf("\nType your first number: ");
        if(scan_input(&a)) continue;
        printf("Type your second number: ");
        if(scan_input(&b)) continue;
        printf("\n");

        switch(option){
            case 1:
                result = add(a, b);
                break;
            case 2:
                result = subtract(a, b);
                break;
            case 3:
                if(b == 0.0){
                    printf("-> Can't divide by 0\n");
                    continue;
                }   
                result = divide(a, b);
                break;
            case 4:
                result = multiply(a, b);
                break;
            default:
                printf("Something went wrong...\n");
                return 0;
        }
        printf("-> %f\n", result);
    }
    return 0;
}