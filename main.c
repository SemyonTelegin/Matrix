#include <stdio.h>
#include "matrix/matrix.h"
#include "malloc.h"

int main(int argc, char* argv[])
{
    int height, width;
    printf("Enter height and width:\n");
    scanf("%i %i", &height, &width);
    printf("Enter matrix:\n");
    Matrix* matrix = newMatrix(height, width);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            printf("Elem %d %d:", i, j);
            scanf("%d", &(matrix->values[i][j]));

        }

    printf("Enter size of vector:");
    int n;
    scanf("%i", &n);
    int* vector = (int*) malloc(n * sizeof (int));
    printf("Enter vector:");

    for (int i = 0; i < n; i++)
        scanf("%d", &(vector[i]));

    Matrix *newMatrix = addVector(matrix, vector, n);
    printMatrix(newMatrix);

    free(vector);
    deleteMatrix(matrix);
    deleteMatrix(newMatrix);

    return 0;
}