//
// Created by PC on 14.03.2022.
//

#include "matrix.h"
#include "malloc.h"

Matrix* newMatrix(size_t height, size_t width)
{
    int **values = (int**)malloc(height * sizeof(int));

    for (int i = 0; i < height; i++)
    {
        values[i] = (int*)malloc(width * sizeof(int));

        for (int j = 0; j < width; j++)
            values[i][j] = 0;
    }

    Matrix *matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->height = height;
    matrix->width = width;
    matrix->values = values;
    return matrix;
}

void deleteMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->height; i++)
        free(matrix->values[i]);

    free(matrix->values);
    free(matrix);
}

Matrix* addVector(Matrix *matrix, int *vector, int len)
{
    Matrix *resultMatrix = newMatrix(matrix->height, matrix->width + 1);

    for (int i = 0; i < resultMatrix->height; i++)
        for (int j = 0; j < resultMatrix->width; j++)
        {
            if (j < matrix->width)
                resultMatrix->values[i][j] = matrix->values[i][j];
            else
            if (i < len)
                resultMatrix->values[i][j] = vector[i];
            else
                resultMatrix->values[i][j] = 0;
        }

    deleteMatrix(matrix);
    return resultMatrix;
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++)
            printf("%d ", matrix->values[i][j]);

        printf("\n");
    }
}