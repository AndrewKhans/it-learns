#include <stdio.h>
#include "matrix_math.h"
#include <stdlib.h>

void testMatrixMath() {
    Matrix a, b, c;

    a = generateMatrixFilled(4, 2, 1.0f);
    a.data[0] = 2; a.data[3] = 2; a.data[5] = 3; a.data[7] = 2;
    printf("A:\n");
    printMatrix(a);


    printf("A, scaled by 5:\n");
    scaleMatrix(a, 5);
    printMatrix(a);

    b = generateMatrixFilled(2, 5, 1.0f);
    b.data[0] = 2; b.data[3] = 2; b.data[5] = 3; b.data[7] = 2;
    printf("B:\n");
    printMatrix(b);

    printf("A*B = C:\n");
    c = multiplyMatrices(a, b);
    printMatrix(c);

    deleteMatrix(&a);
    deleteMatrix(&b);
    deleteMatrix(&c);

    // try printing the deleted matrix now and see what happens
}

int main() {

    testMatrixMath();

    return 0;
}