#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 5
#define COLS 3

int main()
{
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

    return 0;
}
