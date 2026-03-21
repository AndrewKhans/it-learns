#include "matrix_math.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Function for user to get an element. Slow, do not use internally
float mget(Matrix m, size_t row, size_t col) {
    size_t idx = row*m.cols + col;
    assert(idx < m.size);
    return m.data[idx];
}

// Function for user to set an element. Slow, do not use internally
void mset(Matrix m, size_t row, size_t col, float val) {
    size_t idx = row*m.cols + col;
    assert(idx < m.size);
    m.data[idx] = val;
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
    Matrix m = generateMatrix(rows, cols);

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
    // This does not have to be efficient, as printing is only used during testing/debugging
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
            printf("%.2f ", m.data[i*m.cols + j]);
        }
        printf("]\n");
    }
    printf("\n");
}

Matrix scaleMatrix(Matrix m, float s) {
    Matrix ret = generateMatrix(m.rows, m.cols);

    for (size_t i = 0; i < m.size; i++) {
        ret.data[i] = m.data[i]*s;
    }

    return ret;
}

Matrix transposeMatrix(Matrix m) {
    Matrix ret = generateMatrix(m.cols, m.rows);
    size_t mIdx = 0;
    size_t mRow1Idx = 0;

    for (size_t i = 0; i < ret.size; i++) {
        ret.data[i] = m.data[mIdx];

        mIdx += m.cols;
        if (mIdx >= m.size) mIdx = ++mRow1Idx;
    }

    return ret;
}

Matrix multiplyMatrices(Matrix a, Matrix b) {
    assert(a.cols == b.rows);

    Matrix c = generateMatrix(a.rows, b.cols);
    float tempSum;
    size_t a_row_offset, c_row_offset;

    for (size_t a_row_index = 0; a_row_index < a.rows; a_row_index++) {
        // Cache values to avoid recomputing in inner loops
        a_row_offset = a_row_index*a.cols;
        c_row_offset = a_row_index*c.cols;
        for (size_t b_col_index = 0; b_col_index < b.cols; b_col_index++) {
            tempSum = 0;

            // Multiply elements of our row from Matrix a by our col from Matrix b
            for (size_t i = 0; i < a.cols; i++) {
                tempSum += a.data[a_row_offset + i] * b.data[i*b.cols + b_col_index];
            }

            c.data[c_row_offset + b_col_index] = tempSum;
        }
    }
    return c;
}

Matrix elementwiseMultiplyMatrices(Matrix a, Matrix b) {
    assert(a.rows == b.rows && a.cols == b.cols);

    Matrix c = generateMatrix(a.rows, a.cols);

    for (size_t i = 0; i < a.size; i++) {
        c.data[i] = a.data[i] * b.data[i];
    }

    return c;
}

Matrix addMatricies(Matrix a, Matrix b) {
    assert(a.rows == b.rows && a.cols == b.cols);

    Matrix c = generateMatrix(a.rows, a.cols);

    for (size_t i = 0; i < a.size; i++) {
        c.data[i] = a.data[i] + b.data[i];
    }

    return c;
}

Matrix subtractMatricies(Matrix a, Matrix b) {
    assert(a.rows == b.rows && a.cols == b.cols);

    Matrix c = generateMatrix(a.rows, a.cols);

    for (size_t i = 0; i < a.size; i++) {
        c.data[i] = a.data[i] - b.data[i];
    }

    return c;
}
