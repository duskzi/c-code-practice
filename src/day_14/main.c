#include <stdio.h>

/*
File I/O:
|         |                    |
| 'r'     |  Read files        |
| 'w'     |  W/Overwrite files |
| 'a'     |  Append to file    |
| remove  |  Remove file       |
|         |                    |
*/

int main(void)
{
    FILE *fp = fopen("index.html", "w");
    
    fprintf(fp, "<h1>HTML with C test</h1>\n");
    fprintf(fp, "<p>There's a house in New Orleans, "
    "they call the rising sun, and its been the ruin of many poor boys, "
    "and good, I know, i was one.</p>"
    );

    fclose(fp);
}

