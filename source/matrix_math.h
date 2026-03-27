#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define COMPARE_THRESHOLD 0.0001

typedef struct Matrix {
    size_t rows;
    size_t cols;
    size_t size;

    float* data; // Flattened 2D array
} Matrix;

// Basic functions
Matrix matAlloc(size_t rows, size_t cols);
Matrix matAllocFilled(size_t rows, size_t cols, float fillValue);
Matrix matLoad(string fileName);
void matSave(Matrix m, string fileName);
float matGet(Matrix m, size_t row, size_t col);
void matSet(Matrix m, size_t row, size_t col, float val);
void matDelete(Matrix *m);
void matPrint(Matrix m);

// Single-Matrix Operations
Matrix matScale(Matrix m, float s);
Matrix matAddScalar(Matrix m, float s);
Matrix matTranspose(Matrix m);

// Two-Matrix Operations
Matrix matMultiply(Matrix a, Matrix b);
Matrix matElementwiseMultiply(Matrix a, Matrix b);
Matrix matAdd(Matrix a, Matrix b);
Matrix matSubtract(Matrix a, Matrix b);
bool matEqual(Matrix a, Matrix b);
