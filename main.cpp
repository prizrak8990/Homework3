#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

void Create_matrix(int**& matrix, int& a, int& b, int argc, char* argv[])
{
    int k = 2;
    int i;
    string x, y;
    for (i = 0; (argv[1][i] != 'x') && (argv[1][i] != 'X'); i++)
        x += argv[1][i];
    for (i += 1; i < strlen(argv[1]); i++)
        y += argv[1][i];
    a = atoi(x.c_str());
    b = atoi(y.c_str());
    if (a == 0 || b == 0)
        cout << "Неверный размер матрицы, повторите ввод" << endl;
    matrix = new int*[a];
    for (i = 0; i < a; i++)
        matrix[i] = new int[b];
    for (i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            matrix[i][j] = 0;
    for (i = 0; i < a; i++)
        for (int j = 0; j < b; j++, k++) {
            if (k < argc)
                matrix[i][j] = atoi(argv[k]);
        }
}

void Menu()
{
    cout << endl;
    cout << "Выберете одну из операций:" << endl
         << endl;
    cout << "1. Вывести матрицу" << endl;
    cout << "2. Сложить матрицу" << endl;
    cout << "3. Умножить матрицу" << endl;
    cout << "4. Транспонировать матрицу" << endl;
    cout << "5. Сохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << "7. Сортировать матрицу " << endl;
    cout << "8. Завершить работу программы" << endl;
}

void Show_matrix(int** matrix, int a, int b)
{
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
}

void Add_matrix(int**& matrix, int& a, int& b, int argc, char* argv[])
{
    int count;
    cout << "Введите матрицу " << a << "x" << b << endl;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            cin >> count;
            matrix[i][j] = matrix[i][j] + count;
        }
    cout << endl
         << "Результат:" << endl
         << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
}

void Multiplication_matrix(int**& matrix, int& a, int& b)
{
    int i, n, m;
    char* x;
    string str1, str2;
    cout << "Введите размер матрицы:" << endl
         << endl;
    cin >> x;
    for (i = 0; (x[i] != 'x') && (x[i] != 'X'); i++)
        str1 += x[i];
    for (i += 1; i < strlen(x); i++)
        str2 += x[i];
    n = atoi(str1.c_str());
    m = atoi(str2.c_str());
    if (b == n) {
        cout << "Введите элементы матрицы" << endl
             << endl;
        int** subsidiary_matrix;
        subsidiary_matrix = new int*[a];
        for (i = 0; i < n; i++)
            subsidiary_matrix[i] = new int[m];
        for (i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> subsidiary_matrix[i][j];
        int** final_matrix;
        final_matrix = new int*[a];
        for (i = 0; i < a; i++)
            final_matrix[i] = new int[m];
        for (i = 0; i < a; i++)
            for (int j = 0; j < m; j++)
                final_matrix[i][j] = 0;
        for (i = 0; i < a; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < n; k++)
                    final_matrix[i][j] += matrix[i][k] * subsidiary_matrix[k][j];
        cout << "Результат:" << endl
             << endl;
        b = m;
        for (int i = 0; i < n; i++)
            delete[] subsidiary_matrix[i];
        delete[] subsidiary_matrix;
        for (int i = 0; i < a; i++)
            delete[] matrix[i];
        delete[] matrix;
        matrix = final_matrix;
        for (i = 0; i < a; i++) {
            for (int j = 0; j < b; j++)
                cout << setw(4) << matrix[i][j];
            cout << endl;
        }
    }
    else
        cout << "Неверный размер";
}

void Transpose_matrix(int**& matrix, int& a, int& b)
{
    int** subsidiary_matrix = nullptr;
    subsidiary_matrix = new int*[b];
    for (int i = 0; i < b; i++)
        subsidiary_matrix[i] = new int[a];
    for (int i = 0; i < b; i++)
        for (int j = 0; j < a; j++)
            subsidiary_matrix[i][j] = matrix[j][i];
    for (int i = 0; i < a; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = subsidiary_matrix;
    swap(a, b);
}

void Save_in_file(int** matrix, int a, int b)
{
    ofstream fout("file.txt");
    fout << setw(4) << a << " " << setw(4) << b << "\r\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            fout << setw(4) << matrix[i][j];
        fout << "\r\n";
    }
    fout.close();
}

void Load_from_file(int**& matrix, int& a, int& b)
{
    ifstream fin("file.txt");
    if (fin.is_open()) {
        fin >> a >> b;
        matrix = new int*[a];
        for (int i = 0; i < a; i++)
            matrix[i] = new int[b];
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                fin >> matrix[i][j];
        fin.close();
    }
    else
        cout << "Файл не найден";
}

void Sorting_matrix()
{
}

int main(int argc, char* argv[])
{
    int** matrix = nullptr;
    int a, b;
    Create_matrix(matrix, a, b, argc, argv);
    setlocale(LC_ALL, "RUS");
    int choise;
    while (true) {
        Menu();
        cin >> choise;
        switch (choise) {
        case 1:
            Show_matrix(matrix, a, b);
            break;
        case 2:
            Add_matrix(matrix, a, b, argc, argv);
            break;
        case 3:
            Multiplication_matrix(matrix, a, b);
            break;
        case 4:
            Transpose_matrix(matrix, a, b);
            break;
        case 5:
            Save_in_file(matrix, a, b);
            break;
        case 6:
            Load_from_file(matrix, a, b);
            break;
        case 7:
            Sorting_matrix();
            break;
        case 8:
            delete[] matrix;
            return 0;
        default:
            cout << "Неверная команда" << endl;
        }
    }
}
