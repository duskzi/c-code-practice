#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_option(int *opt){
    while(scanf("%i", opt) != 1){
        printf("Invalid option\n");

        while (getchar() != '\n');
    }
}

int main(void){

    int items = 0;
    char **task_list = NULL;

    while(1){

        int option;

        printf(
        "[1] Add task\n"
        "[2] List tasks\n"
        "[3] Remove task\n"
        "[0] Exit\n");

        get_option(&option);

        switch(option){

            case 0:

                for(int i = 0; i < items; i++)
                {
                    free(task_list[i]);
                }

                free(task_list);
                return 0;

            case 1: {

                char string[64];

                printf("Task name: ");
                scanf("%63s", string);

                items++;

                task_list = realloc(task_list, items * sizeof(char*));

                task_list[items - 1] = malloc(strlen(string) + 1);

                strcpy(task_list[items - 1], string);

                break;
            }

            case 2:

                if(items == 0){
                    printf("No tasks\n");
                    break;
                }

                for(int i = 0; i < items; i++)
                {
                    printf("%i: %s\n", i + 1, task_list[i]);
                }

                break;

            case 3:

                if(items == 0){
                    printf("No tasks to remove\n");
                    break;
                }

                free(task_list[items - 1]);

                items--;
                task_list = realloc(task_list, items * sizeof(char*));

                break;

            default:
                printf("Invalid option\n");
        }
    }
}