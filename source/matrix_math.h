#include <stddef.h>

typedef struct Matrix {
    size_t rows;
    size_t cols;
    size_t size;

    float* data; // Flattened 2D array
} Matrix;

// Basic functions
float mget(Matrix m, size_t row, size_t col);
void mset(Matrix m, size_t row, size_t col, float val);
Matrix generateMatrix(size_t rows, size_t cols);
Matrix generateMatrixFilled(size_t rows, size_t cols, float fillValue);
void deleteMatrix(Matrix *m);
void printMatrix(Matrix m);

// Math Functions
void scaleMatrix(Matrix m, float s);
Matrix multiplyMatrices(Matrix a, Matrix b);
Matrix elementwiseMultiplyMatrices(Matrix a, Matrix b);
// TODO: elementwiseMultiplyMatrices
// TODO: transpose
// TODO: Divide
// TODO: Add
// TODO: Subtract
// TODO: Add Bias (add vector?)
