#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

void testMatrixMath() {
    Matrix a, b, c;

    a = generateMatrixFilled(4, 2, 1.0f);
    a.data[0] = 2; a.data[3] = 2; a.data[5] = 3; a.data[7] = 2;
    printf("A:\n");
    printMatrix(a);

    b = scaleMatrix(a, 5);
    printf("A, scaled by 5:\n");
    printMatrix(b);
    deleteMatrix(&b);

    b = generateMatrixFilled(2, 5, 1.0f);
    b.data[0] = 2; b.data[3] = 2; b.data[5] = 3; b.data[7] = 2;
    printf("B:\n");
    printMatrix(b);

    printf("A*B = C:\n");
    c = multiplyMatrices(a, b);
    printMatrix(c);

    printf("New B:\n");
    deleteMatrix(&b);
    b = generateMatrixFilled(4, 2, 1.0f);
    b.data[0] = 2; b.data[3] = 2; b.data[5] = 3; b.data[7] = 2;
    printMatrix(b);

    printf("Elementwise A*B = C:\n");
    deleteMatrix(&c);
    c = elementwiseMultiplyMatrices(a, b);
    printMatrix(c);

    printf("A transposed:\n");
    deleteMatrix(&b);
    b = transposeMatrix(a);
    printMatrix(b);


    deleteMatrix(&a);
    deleteMatrix(&b);
    deleteMatrix(&c);
}

// y = XW + b
void linearRegression() {
    printf("Unimplemented\n");
}

int main() {

    printf("1: Test matrix math\n");
    printf("Enter your desired operation: ");
    int c = getc(stdin);

    switch (c) {
        case '1':
            testMatrixMath();
            break;
        case '2':
            linearRegression();
        default:
            printf("Invalid operation\n");
    }

    // printf("c as a char: \"%c\" and c as an int: \"%d\"\n", c, c);

    return 0;
}