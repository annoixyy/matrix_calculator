#include "matrix.h"
#include <iostream>

int main() {
    double values[] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix a = matrix_from_array(values, 3, 3);

    std::cout << "Исходная матрица:\n";
    print_matrix(a);

    Matrix sub = matrix_submatrix(a, 1, 1, 2, 2);

    std::cout << "\nПодматрица 2x2:\n";
    print_matrix(sub);

    free_matrix(&sub);
    free_matrix(&a);

    return 0;
}