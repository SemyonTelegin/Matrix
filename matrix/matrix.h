//
// Created by PC on 14.03.2022.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include "stdio.h"

typedef struct Matrix
{
    size_t height;
    size_t width;

    int **values;
} Matrix;

Matrix* newMatrix(size_t height, size_t width);
void deleteMatrix(Matrix *matrix);
Matrix* addVector(Matrix *matrix, int *vector, int len);
void printMatrix(Matrix *matrix, FILE *stream);

#endif //MATRIX_MATRIX_H
