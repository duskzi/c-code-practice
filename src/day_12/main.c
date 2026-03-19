#include <stdio.h>
#include <stdlib.h>

#define GRID_MAX 9
typedef struct {
    char ctype;
} Cell;

typedef struct {
    int size;
    Cell cells_grid[GRID_MAX][GRID_MAX];
} Grid;

#define CGRID_DEF cgrid.cells_grid[i][j].ctype
Grid create_cgrid() 
{
    Grid cgrid;

    for(int i=0; i<GRID_MAX; i++){
        for(int j=0; j<GRID_MAX; j++){
            
            int chance = rand() % 3;

            switch(chance) {
                case 0:
                    CGRID_DEF = '#';
                    break;
                case 1:
                    CGRID_DEF = '*';
                    break;
                case 2:
                    CGRID_DEF = '@';
                    break;
            }
        }
    }

    return cgrid;
}

void display_cgrid(Grid cgrid)
{
    for(int i=0; i<GRID_MAX; i++){
        for(int j=0; j<GRID_MAX; j++){
            printf("%c  ", cgrid.cells_grid[i][j].ctype);
        }
        printf("\n");
    }
}

int main(void)
{
    Grid grid = create_cgrid();
    display_cgrid(grid);
    
    return 0;
}



