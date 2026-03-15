#include "matrix_math.h"
#include <stdlib.h>
#include <stdio.h>

// Todo: Make a macro for addressing the matrix easier with x, y

Matrix generateMatrix(size_t rows, size_t cols) {
    Matrix m;

    m.rows = rows;
    m.cols = cols;
    m.data = calloc(rows*cols, sizeof(float));

    if (!m.data) {
        perror("Could not allocate matrix");
        exit(1);
    }

    return m;
}

void deleteMatrix(Matrix *m) {
    free(m->data);
    m->data = NULL;
}

void printMatrix(Matrix m) {
    for (size_t i = 0; i < m.rows; i++) {
        printf("[ ");
        for (size_t j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[j + i*m.cols]);
        }
        printf("]\n");
    }
    printf("\n");
}

void scaleMatrix(Matrix m, float s) {
    for (size_t i = 0; i < m.rows*m.cols; i++) {
        m.data[i] *= s;
    }
}


// float rowColProd(Matrix a, Matrix b, size_t i, size_t j) {

// }

// Matrix multiplyMatricies(Matrix a, Matrix b) {
//     assert(a.cols == b.rows); //

//     Matrix c;

//     c = generateMatrix(a.rows, b.cols);

//     for (size_t i = 0; i < m.rows; i++) {
//         for (size_t j = 0; j < m.cols; j++) {
//             c.data[j + i*m.cols] = rowColProd(a, b, i, j);
//         }
//     }

//     return c;
// }

