#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("./file.txt", "r");
    FILE *outfp = fopen("out.html", "w");

    if(fp == NULL){
        printf("Can't open file\n");
        return 1;
    }

    char c;
    int is_key = 0, key_count = 0;
    char key[16];

    int is_value = 0, value_count = 0;
    char value[32];

    while((c = fgetc(fp)) != EOF){
        if(c == '}'){
            is_value = 0;
            value[value_count] = '\0';
            key[key_count] = '\0';

            if (strcmp(key, "t") == 0) {
                fprintf(outfp, "<title>%s</title>", value);
            }
            else if (strcmp(key, "*") == 0) {
                fprintf(outfp, "<b>%s</b>", value);
            }
            else if (strcmp(key, "_") == 0) {
                fprintf(outfp, "<i>%s</i>", value);
            }
            else if (strcmp(key, "h") == 0) {
                fprintf(outfp, "<h1>%s</h1>", value);
            }
            else if (strcmp(key, "color") == 0) {
                fprintf(outfp, "<span style=\"color: red;\">%s</span>", value);
            }

            key_count = 0;
            value_count = 0;
        }
        else if(c == '{'){
            is_key = 0;
            is_value = 1;
        }
        else if(c == '@'){
            is_key = 1;
        }
        else {
            if(is_value){
                value[value_count++] = c;
            }
            else if(is_key){
                key[key_count++] = c;
            }
        }
    }

    fclose(fp);
    fclose(outfp);
}