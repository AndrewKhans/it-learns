#include <stdio.h>
#include "matrix_math.h"
#include <stdlib.h>

void testMatrixMath() {
    printf("Creating two matricies\n");
    Matrix m1 = generateMatrix(4, 2);
    m1.data[3] = 2; m1.data[5] = 1;

    Matrix m2 = generateMatrix(2, 5);

    printf("A:\n");
    printMatrix(m1);
    printf("B:\n");
    printMatrix(m2);

    printf("Scaling matrix A by 5\n");
    scaleMatrix(m1, 5);

    printf("A:\n");
    printMatrix(m1);
    printf("B:\n");
    printMatrix(m2);

    deleteMatrix(&m1);
    deleteMatrix(&m2);

    // try printing the deleted matrix now and see what happens
}

int main() {

    testMatrixMath();

    return 0;
}