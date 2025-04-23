#include <cstdio>
#include <stdexcept>

template <typename T>
void addMatrices(T** matrix1, T** matrix2, T** result, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

template <typename T>
void printMatrix(T** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            printf("%6.2f ", static_cast<double>(matrix[i][j])); 
        }
        printf("\n");
    }
}

int main() {
    const size_t rows = 2;
    const size_t cols = 2;

    int** mat1 = new int*[rows];
    int** mat2 = new int*[rows];
    int** result = new int*[rows];

    for (size_t i = 0; i < rows; ++i) {
        mat1[i] = new int[cols];
        mat2[i] = new int[cols];
        result[i] = new int[cols];
    }

    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    addMatrices(mat1, mat2, result, rows, cols);

    printf("Матрица 1:\n");
    printMatrix(mat1, rows, cols);

    printf("\nМатрица 2:\n");
    printMatrix(mat2, rows, cols);

    printf("\nРезультат сложения:\n");
    printMatrix(result, rows, cols);

    for (size_t i = 0; i < rows; ++i) {
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] result[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] result;

    return 0;
}
