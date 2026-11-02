/**
 * @file matrix.h
 * @brief Библиотека для работы с матрицами.
 */

#ifndef MATRIX_H
#define MATRIX_H

/**
 * @brief Структура для хранения матрицы.
 *
 * Содержит двумерный массив и размеры матрицы.
 */
struct Matrix {
    double** data; ///< Данные матрицы
    int rows;      ///< Количество строк
    int cols;      ///< Количество столбцов
};

/**
 * @brief Создаёт матрицу, заполненную нулями.
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Созданная матрица
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Освобождает память матрицы.
 * @param m Указатель на матрицу
 */
void free_matrix(Matrix* m);

/**
 * @brief Складывает две матрицы одинакового размера.
 * @param a Первая матрица
 * @param b Вторая матрица
 * @return Матрица-сумма
 */
Matrix matrix_add(Matrix a, Matrix b);

/**
 * @brief Умножает две совместимые матрицы.
 * @param a Первая матрица
 * @param b Вторая матрица
 * @return Матрица-произведение
 */
Matrix matrix_multiply(Matrix a, Matrix b);

/**
 * @brief Выводит матрицу в консоль.
 * @param m Матрица для вывода
 */
void print_matrix(Matrix m);

/**
 * @brief Создаёт матрицу из одномерного массива.
 * @param arr Массив значений
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Созданная матрица
 */
Matrix matrix_from_array(const double* arr, int rows, int cols);

/**
 * @brief Выделяет подматрицу из исходной матрицы.
 * @param m Исходная матрица
 * @param start_row Индекс первой строки
 * @param start_col Индекс первого столбца
 * @param rows Количество строк подматрицы
 * @param cols Количество столбцов подматрицы
 * @return Выделенная подматрица
 */
Matrix matrix_submatrix(Matrix m, int start_row, int start_col,
                        int rows, int cols);

#endif