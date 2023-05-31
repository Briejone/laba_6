#include <bits/stdc++.h>

using namespace std;

typedef struct matrix_struct {
    int** matrix;
    int rows;
    int columns;
} matrix_t;

typedef struct squars_struct {
    int sq1[3][3];
    int sq2[3][3];
    int sq3[3][3];
    int sq4[3][3];
    int sq5[3][3];
    int sq6[3][3];
    int sq7[3][3];
    int sq8[3][3];
    int sq9[3][3];
} squars;

typedef struct system_struct {
    int n = 4;
    double a[4][4] = {{-1.14, -0.04, 0.21, -18}, 
                      {0.25, -1.23, -0.17, -0.09}, 
                      {-0.21, -0.17, 0.8, -0.13}, 
                      {0.15, -1.31, 0.06, 0.95}};
    double x[4];
    double b[4] = {-1.24, 0.95, 2.56, -1.14};
} system_equation;

matrix_t create_matrix(int rows, int columns);
void remove_matrix(matrix_t *matrix);
// void print_matrix(matrix_t matrix);
// void inicilization_matrix(matrix_t *matrix);
// void inicilization_matrix_task1(matrix_t matrix1, matrix_t *matrix2);
// int delta_max_twomin(matrix_t matrix);
// void replace_diagonal(matrix_t *matrix, int ch);
// void inicilization_matrix_task3(matrix_t *matrix);
// void print_sudoku(int matrix[][9]);
// bool isCheck(int matrix[][9]);
// bool isCheck_rows_and_columns(int matrix[][9]);
// bool isCheck_squars(int matrix[][9]);
// bool isCheck_blocks(int mas[][3]);
// void task1();
// void task2();
// void task3();
// void task4();

void viziner();
map <char, int> create_slovar();
string encode_mes(string mes, string key);
string decode_mes(string mes, string key);
char convert_from_int_to_char(int ch, map <char, int> slovar);
void print_table_viziner();
void print_char_matrix(matrix_t matrix);

// void sys_eq();
// void print_system(system_equation sq);
// int to_tringle_matrix(system_equation *sq);
// void reverse_way(system_equation *sq);