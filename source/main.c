#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

void testMatrixMath() {
    Matrix a, b, c;

    a = matAllocFilled(4, 2, 1.0f);
    a.data[0] = 2; a.data[3] = 2; a.data[5] = 3; a.data[7] = 2;
    printf("A:\n");
    matPrint(a);

    b = matScale(a, 5);
    printf("A, scaled by 5:\n");
    matPrint(b);
    matDelete(&b);

    b = matAllocFilled(2, 5, 1.0f);
    b.data[0] = 2; b.data[3] = 2; b.data[5] = 3; b.data[7] = 2;
    printf("B:\n");
    matPrint(b);

    printf("A*B = C:\n");
    c = matMultiply(a, b);
    matPrint(c);

    printf("New B:\n");
    matDelete(&b);
    b = matAllocFilled(4, 2, 1.0f);
    b.data[0] = 2; b.data[3] = 2; b.data[5] = 3; b.data[7] = 2;
    matPrint(b);

    printf("Elementwise A*B = C:\n");
    matDelete(&c);
    c = matElementwiseMultiply(a, b);
    matPrint(c);

    printf("A transposed:\n");
    matDelete(&b);
    b = matTranspose(a);
    matPrint(b);


    matDelete(&a);
    matDelete(&b);
    matDelete(&c);
}

// y = XW + b
void linearRegression() {
    Matrix x_input, weights, y_pred;

    Matrix y_pred = matmul(X, W);
    add_scalar(y_pred, b);

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