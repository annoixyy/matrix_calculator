#include <gtest/gtest.h>
#include "matrix.h"

TEST(MatrixTest, CreateMatrix) {
    Matrix m = create_matrix(2, 3);

    EXPECT_EQ(m.rows, 2);
    EXPECT_EQ(m.cols, 3);
    EXPECT_DOUBLE_EQ(m.data[0][0], 0.0);

    free_matrix(&m);
}

TEST(MatrixTest, Addition) {
    double a_values[] = {1, 2, 3, 4};
    double b_values[] = {5, 6, 7, 8};

    Matrix a = matrix_from_array(a_values, 2, 2);
    Matrix b = matrix_from_array(b_values, 2, 2);
    Matrix result = matrix_add(a, b);

    EXPECT_DOUBLE_EQ(result.data[0][0], 6);
    EXPECT_DOUBLE_EQ(result.data[1][1], 12);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

TEST(MatrixTest, Multiplication) {
    double a_values[] = {1, 2, 3, 4};
    double b_values[] = {5, 6, 7, 8};

    Matrix a = matrix_from_array(a_values, 2, 2);
    Matrix b = matrix_from_array(b_values, 2, 2);
    Matrix result = matrix_multiply(a, b);

    EXPECT_DOUBLE_EQ(result.data[0][0], 19);
    EXPECT_DOUBLE_EQ(result.data[0][1], 22);
    EXPECT_DOUBLE_EQ(result.data[1][0], 43);
    EXPECT_DOUBLE_EQ(result.data[1][1], 50);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&result);
}

TEST(MatrixTest, SubmatrixVariant13) {
    double values[] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    Matrix a = matrix_from_array(values, 3, 3);
    Matrix sub = matrix_submatrix(a, 1, 1, 2, 2);

    EXPECT_EQ(sub.rows, 2);
    EXPECT_EQ(sub.cols, 2);
    EXPECT_DOUBLE_EQ(sub.data[0][0], 5);
    EXPECT_DOUBLE_EQ(sub.data[0][1], 6);
    EXPECT_DOUBLE_EQ(sub.data[1][0], 8);
    EXPECT_DOUBLE_EQ(sub.data[1][1], 9);

    free_matrix(&a);
    free_matrix(&sub);
}