#include "matrix.h"

void viziner() {
    cout << "--------------------PART 2--------------------" << endl;
    string mes = "HeLlO wOrLD", key = "key";
    string enc_mes = encode_mes(mes, key);
    string dec_mes = decode_mes(enc_mes, key);
    cout << "Mes: " << mes << endl << "Encode mes: " << enc_mes << endl << "Decode mes: " << dec_mes << endl;
    print_table_viziner();
}

map <char, int> create_slovar() {
    map<char, int> sl;
    for (int sym = 'a', i = 0; sym < 'z' + 1; ++sym, ++i) {
        sl[sym] = i;
    }
    sl[' '] = 26;
    return sl;
}

string encode_mes(string mes, string key) {
    map <char, int> slovar = create_slovar();
    string e_mes = "";
    int d = key.size(), n = slovar.size();
    for (int i = 0; i < mes.size(); ++i) {
        e_mes += convert_from_int_to_char((slovar[tolower(mes[i])] + slovar[tolower(key[i % d])]) % n, slovar);
    }
    return e_mes;
}

string decode_mes(string mes, string key) {
    map <char, int> slovar = create_slovar();
    string d_mes = "";
    int d = key.size(), n = slovar.size();
    for (int i = 0; i < mes.size(); ++i) {
        d_mes += convert_from_int_to_char((slovar[mes[i]] - slovar[key[i % d]] + n) % n, slovar);
    }
    return d_mes;
}

char convert_from_int_to_char(int ch, map <char, int> slovar) {
    for (auto it: slovar) {
        if (it.second == ch) {
            return it.first;
        }
    }
    return '0';
}

void print_table_viziner() {
    cout << "----------------------------------------" << endl << "Table Viziner" << endl << "----------------------------------------" << endl;
    int m = 26, n = 26;
    matrix_t matrix = create_matrix(m, n);
    int k = 'a', i = 0, j = 0, j_rows = 0, i_rows = 1;
    while (k < matrix.rows * matrix.columns) {
        if (j_rows != matrix.columns) {
            j = j_rows;
            i = 0;
        } else {
            j = matrix.columns - 1;
            i = i_rows;
        }
        if (j_rows == 26 && i_rows == 1) {
            k = 'a';
        }
        for (; j >= 0 && i < matrix.rows; j--, i++) {
            matrix.matrix[i][j] = k;
        }
        if (j_rows != matrix.columns) {
            ++j_rows;
        } else {
            ++i_rows;
        }
        k++;
    }
    print_char_matrix(matrix);
    remove_matrix(&matrix);
}

void print_char_matrix(matrix_t matrix) {
    for(int x = 0; x < matrix.rows; ++x) {
        for(int y = 0; y < matrix.columns; ++y) {
            cout << setw(4) << setprecision(2) << (char)matrix.matrix[x][y] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

matrix_t create_matrix(int rows, int columns) {
    matrix_t matrix;
    if (rows < 1 || columns < 1) {
        matrix.matrix = NULL;
    } else {
        matrix.rows = rows;
        matrix.columns = columns;
        matrix.matrix = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            matrix.matrix[i] = new int [columns];
        }
    }
    return matrix;
}

void remove_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; ++i) {
      delete []matrix->matrix[i];
  }
  delete matrix->matrix;
}