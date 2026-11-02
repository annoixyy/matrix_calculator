#include "matrix.h"
#include <iostream>

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = new double*[rows];

    for (int i = 0; i < rows; i++) {
        m.data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = 0;
        }
    }

    return m;
}

void free_matrix(Matrix* m) {
    if (m == nullptr || m->data == nullptr) {
        return;
    }

    for (int i = 0; i < m->rows; i++) {
        delete[] m->data[i];
    }

    delete[] m->data;
    m->data = nullptr;
    m->rows = 0;
    m->cols = 0;
}

Matrix matrix_add(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        return create_matrix(0, 0);
    }

    Matrix result = create_matrix(a.rows, a.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return result;
}

Matrix matrix_multiply(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        return create_matrix(0, 0);
    }

    Matrix result = create_matrix(a.rows, b.cols);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            std::cout << m.data[i][j] << " ";
        }
        std::cout << '\n';
    }
}

Matrix matrix_from_array(const double* arr, int rows, int cols) {
    Matrix m = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = arr[i * cols + j];
        }
    }

    return m;
}

// Вариант 13: выделение подматрицы
Matrix matrix_submatrix(Matrix m, int start_row, int start_col,
                        int rows, int cols) {
    if (start_row < 0 || start_col < 0 ||
        rows <= 0 || cols <= 0 ||
        start_row + rows > m.rows ||
        start_col + cols > m.cols) {
        return create_matrix(0, 0);
    }

    Matrix result = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] =
                m.data[start_row + i][start_col + j];
        }
    }

    return result;
}