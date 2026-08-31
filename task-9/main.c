#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 5
#define COLS 3

int main()
{
        int x, y, max = 0;
        srand(time(NULL));
       int **matrix = malloc(ROWS * sizeof(int *));

    if (matrix == NULL)
    {
        printf("No memory...");
        return 0;
    }

    for (int i = 0; i < ROWS; i++)
    {
        matrix[i] = malloc(COLS * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("No memory for sub element...");
            for (int b = 0; b < i; b++)
            {
                free(matrix[b]);
            }
            free(matrix);

            return 0;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf(" %3d ", matrix[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                    if(matrix[i][j] > max){
                            max = matrix[i][j];
                            x = i;
                            y = j;
                    }
            }
    }
    printf("Max element is: %d\n", max);
    printf("Row: %d\n",x + 1);
    printf("Col: %d\n", y + 1);

    return 0;
}
