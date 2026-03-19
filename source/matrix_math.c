#include "matrix_math.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Todo: Make a macro for addressing the matrix easier with x, y
// Todo: Can we cache some values or do a partial sums during matrix multiplication?

float mget(Matrix m, size_t row, size_t col) {
    return m.data[col + row*m.cols];
}

void mset(Matrix m, size_t row, size_t col, float val) {
    m.data[col + row*m.cols] = val;
}

Matrix generateMatrix(size_t rows, size_t cols) {
    Matrix m;

    m.rows = rows;
    m.cols = cols;
    // TODO: Check for overflow on size
    m.size = rows*cols;
    m.data = malloc(m.size*sizeof(float));

    if (!m.data) {
        perror("Could not allocate matrix");
        exit(1);
    }

    return m;
}

Matrix generateMatrixFilled(size_t rows, size_t cols, float fillValue) {
    Matrix m;

    m = generateMatrix(rows, cols);
    // Todo: use memset instead of loop
    for (size_t i = 0; i < m.size; i++) {
        m.data[i] = fillValue;
    }

    return m;
}

void deleteMatrix(Matrix *m) {
    free(m->data);

    m->data = NULL;
    m->rows = 0;
    m->cols = 0;
    m->size = 0;
}

void printMatrix(Matrix m) {

    // TODO: Add padding to account for some numbers being longer
    // uint8_t digits = 0;
    // uint8_t mostDigits = 0;
    // for (size_t i = 0; i < m.size; i++) {
    //     //
    //     digits =
    //     if abs()
    // }

    for (size_t i = 0; i < m.rows; i++) {
        printf("[ ");
        for (size_t j = 0; j < m.cols; j++) {
            printf("%.2f ", mget(m, i, j));
        }
        printf("]\n");
    }
    printf("\n");
}

void scaleMatrix(Matrix m, float s) {
    for (size_t i = 0; i < m.size; i++)
        m.data[i] *= s;
}

// Multiply elements of Row i from Matrix a by Col J from Matrix b
float rowColProdSum(Matrix a, Matrix b, size_t a_row_index, size_t b_col_index) {
    float sum = 0;

    for (size_t i = 0; i < a.cols; i++) {
        sum += mget(a, a_row_index, i) * mget(b, i, b_col_index);
    }

    return sum;
}

Matrix multiplyMatrices(Matrix a, Matrix b) {
    assert(a.cols == b.rows); // Required property of matrix multiplication

    Matrix c;
    float prodSum;

    c = generateMatrix(a.rows, b.cols);

    for (size_t a_row_index = 0; a_row_index < a.rows; a_row_index++) {
        for (size_t b_col_index = 0; b_col_index < b.cols; b_col_index++) {
            prodSum = rowColProdSum(a, b, a_row_index, b_col_index);
            mset(c, a_row_index, b_col_index, prodSum);
        }
    }

    return c;
}

Matrix elementwiseMultiplyMatrices(Matrix a, Matrix b) {
    assert(a.rows == b.rows && a.cols == b.cols);

    Matrix c;

    c = generateMatrix(a.rows, a.cols);

    for (size_t i = 0; i < a.size; i++) {
        c.data[i] = a.data[i] * b.data[i];
    }

    return c;
}
