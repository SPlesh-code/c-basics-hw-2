#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findIsland(int **matrix, int rows, int cols, int i, int j)
{
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;
        if (matrix[i][j] == 0)
            return;
        matrix[i][j] = 0;
        findIsland(matrix, rows, cols, i - 1, j); 
        findIsland(matrix, rows, cols, i + 1, j); 
        findIsland(matrix, rows, cols, i, j - 1); 
        findIsland(matrix, rows, cols, i, j + 1); 
}

int main()
{	
        srand(time(NULL));
        int rows, cols;
        int islands = 0;

        printf("Enter rows: ");
        scanf("%d", &rows);

        printf("Enter cols: ");
        scanf("%d", &cols);

        int **matrix = malloc(rows * sizeof(int *));

        if (matrix == NULL)
        {
            printf("NO memory\n");
            return 1;
        }

        for (int i = 0; i < rows; i++)
        {
                matrix[i] = malloc(cols * sizeof(int));

                if (matrix[i] == NULL)
                {
                       printf("Memory error!\n");
                       return 0;
                }
        }
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] = rand()%2;
	            printf("%d", matrix[i][j]);

                }
    	        printf("\n");
        }
        for (int i = 0; i < rows; i++)
        {

                for (int j = 0; j < cols; j++)
                {
                        if (matrix[i][j] == 1)
                        {

                                islands++;

                                findIsland(matrix, rows, cols, i, j);
                        }
                }
        }

        printf("Number of islands: %d\n", islands);
        for (int i = 0; i < rows; i++)
        {
              free(matrix[i]);
        }

        free(matrix);

        return 0;
}
