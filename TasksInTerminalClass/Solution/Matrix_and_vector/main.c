// Copyright 2021 Marina Usova

/*
Постановка задачи.

Реализована некоторая программа, работающая с матричными операциями.

Программист начал работать над ней и понял, что в ней много дублирования кода.
Он посмотрел свой код и не увидел проблем в самом коде. Чтобы исправить
проблему дублирования он решил вынести часть кода в функции.
Помогите ему в этом, а также допишите функционал, который он не успел.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 3
#define K 2
#define O 1

/// <summary>
/// генерация рандомного числа из указанного диапозона
/// </summary>
/// <param name="maximum">максимальное допустимое значение рандома</param>
/// <param name="minimun">минимальное допустимое значение рандома</param>
/// <returns>сгенерированное случайное значение</returns>
int generateRandNumber(int max, int min) {
    int value = (max - min) * ((float)rand() / RAND_MAX) + min;
    return value;
}

/// <summary>
/// выделение указаного размера памяти
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
int** setMemory(int** matrix, int n, int m) {
    matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(m * sizeof(int));
    return matrix;
}

/// <summary>
/// вывод матрицы на экран
/// </summary>
/// <param name="matrix">матрица</param>
/// <param name="n">количество строк</param>
/// <param name="m">количество столбцов</param>
void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/// <summary>
/// работает неправильно, пример с передачей по адресу обычноый переменной
/// чтобы она поменяла и сохранила своё значение вне этой функции
/// </summary>
/// <param name="matrix"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="value"></param>
/// <returns></returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* value) {
    int** res = NULL;                       // nullptr
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix[i][j] * (*value);
        }
    }
    (*value) = 3;
    return res;
}

void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = generateRandNumber(max, min);
        }
    }
}

void freeMemory(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
    matrix = setMemory(matrix, n, m);
    fillArrayRandValues(matrix, n, m, max, min);
    if (n == 1 && m == 1)
        printf("Scalar %c = ", name);
    else if (n == 1 || m == 1)
        printf("Vector %c = ", name);
    else
        printf("Matrix %c =\n", name);
    printMatrix(matrix, n, m);
    return matrix;
}

void inputData(int* n, int* m, int* max, int* min) {
    // только printf scanf_s
}

int** transposeMatrix(int** matrix, int n, int m) {
    int** res = NULL;
    res = setMemory(res, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}


int** productMatrix(int** matrix_A, int** matrix_B, int n, int m, int k) {
    int** res = NULL;
    res = setMemory(res, n, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    return res;
}

int** sumMatrix(int** matrix_1, int** matrix_2, int n, int m) {
    int** res = NULL;
    res = setMemory(res, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
    return res;
}

int main() {
    int** matrix_A = NULL, ** matrix_B = NULL, ** matrix_C = NULL, ** vector_D = NULL, ** vector_E = NULL, ** result = NULL;
    int max = 4, min = 0, value = 0;

    srand(time(0));

    //inputData(&n, &m, &max, &min);

    matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
    matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
    matrix_C = createMatrix(matrix_C, N, M, max, min, 'C');
    value = generateRandNumber(max, min);

    //Умножение матрицы А на чмсло
    result = setMemory(result, N, M);
    result = multMatrixOnNumber(matrix_A, N, M, &value);
    printf("Matrix A x %d =\n", value);
    printMatrix(result, N, M);
    // was error
    freeMemory(result, N, M);

    //Транспонирование матицы А
    result = setMemory(result, M, N);
    result = transposeMatrix(matrix_A, N, M);
    printf("Matrix A^T =\n");
    printMatrix(result, M, N);
    freeMemory(result, M, N);

    // Умножение МАТРИЦ
    result = setMemory(result, N, K);
    result = productMatrix(matrix_A, matrix_B, N, M, K);
    printf("Matrix A x B =\n");
    printMatrix(result, N, K);
    freeMemory(result, N, K);

    // Сложение МАТРИЦ
    result = setMemory(result, N, M);
    result = sumMatrix(matrix_A, matrix_C, N, M);
    printf("Matrix A + C =\n");
    printMatrix(result, N, M);
    freeMemory(result, N, M);

    //создание векторов
    vector_D = createMatrix(vector_D, O, N, max, min, 'D');
    vector_E = createMatrix(vector_E, O, N, max, min, 'E');

    // умножение вектора на число
    result = setMemory(result, O, N);
    result = multMatrixOnNumber(vector_D, O, N, &value);
    printf("vector D x %d = ", value);
    printMatrix(result, O, N);
    freeMemory(result, O, N);

    // сложение двух векторов
    result = setMemory(result, O, N);
    result = sumMatrix(vector_D, vector_E, O, N);
    printf("vector D + E = ");
    printMatrix(result, O, N);
    freeMemory(result, O, N);

    // умножение двух векторов
    result = setMemory(result, O, O);
    result = productMatrix(vector_D, transposeMatrix(vector_E, O, N), O, N, O);
    printf("scalar D x E = ");
    printMatrix(result, O, O);
    freeMemory(result, O, O);

    freeMemory(matrix_A, N, M);
    freeMemory(matrix_B, M, K);
    freeMemory(matrix_C, N, M);
    freeMemory(vector_D, O, N);
    freeMemory(vector_E, O, N);

    return 0;
}