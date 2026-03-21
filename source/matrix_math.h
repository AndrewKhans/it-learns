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

// Single-Matrix Operations
Matrix scaleMatrix(Matrix m, float s);
Matrix transposeMatrix(Matrix m);

// Two-Matrix Operations
Matrix multiplyMatrices(Matrix a, Matrix b);
Matrix elementwiseMultiplyMatrices(Matrix a, Matrix b);
Matrix addMatrices(Matrix a, Matrix b);
Matrix subtractMatrices(Matrix a, Matrix b);

// TODO: Divide
// TODO: Subtract
// TODO: Add Bias (add vector?)
