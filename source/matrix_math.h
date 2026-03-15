#include <stddef.h>

typedef struct Matrix {
    size_t rows;
    size_t cols;
    float* data; // Flattened 2D array
} Matrix;

Matrix generateMatrix(size_t rows, size_t cols);

void deleteMatrix(Matrix *m);

void printMatrix(Matrix m);

// Math Functions
void scaleMatrix(Matrix m, float s);

// Multiply
// Divide
// Add
// Subtract
