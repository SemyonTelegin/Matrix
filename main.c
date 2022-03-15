#include <stdio.h>
#include "matrix/matrix.h"
#include "malloc.h"

int main(int argc, char* argv[])
{
    int height, width;
    fprintf(stdout,"Enter height and width:\n");
    fscanf(stdin, "%i %i", &height, &width);
    fprintf(stdout, "Enter matrix:\n");
    Matrix* matrix = newMatrix(height, width);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            fscanf(stdin, "%d", &(matrix->values[i][j]));

    fprintf(stdout, "Enter size of vector:");
    int n;
    fscanf(stdin, "%i", &n);
    int* vector = (int*) malloc(n * sizeof (int));
    fprintf(stdout, "Enter vector:");

    for (int i = 0; i < n; i++)
        fscanf(stdin,"%d", &(vector[i]));

    Matrix *newMatrix = addVector(matrix, vector, n);
    printMatrix(newMatrix, stdout);

    free(vector);
    deleteMatrix(matrix);
    deleteMatrix(newMatrix);

    return 0;
}