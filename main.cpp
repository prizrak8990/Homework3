#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

void crm(int**& z, int& a, int& b, int argc, char* argv[])
{
    int i, j, k;
    k = 2;
    string x, y;
    for (i = 0; (argv[1][i] != 'x') && (argv[1][i] != 'X'); i++)
        x += argv[1][i];
    for (i += 1; i < strlen(argv[1]); i++)
        y += argv[1][i];
    a = atoi(x.c_str());
    b = atoi(y.c_str());
    if (a == 0 || b == 0)
        cout << "Неверный размер матрицы, повторите ввод" << endl;
    z = new int*[a];
    for (i = 0; i < a; i++)
        z[i] = new int[b];
    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
            z[i][j] = 0;
    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++, k++) {
            if (k < argc)
                z[i][j] = atoi(argv[k]);
        }
}

void menu()
{
    cout << endl;
    cout << "Выберете одну из операций" << endl
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

void shm(int**& z, int a, int b)
{
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << setw(4) << z[i][j];
        cout << endl;
    }
}

void add(int**& z, int& a, int& b, int argc, char* argv[])
{
    int** q;
    q = new int*[a];
    for (int i = 0; i < a; i++)
        q[i] = new int[b];
    int c;
    cout << "Введите матрицу " << a << "x" << b << endl;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            cin >> c;
            q[i][j] = z[i][j] + c;
        }
    cout << endl
         << "Результат:" << endl
         << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            cout << setw(4) << q[i][j];
        cout << endl;
    }
}

void umn(int**& z, int& a, int& b)
{
    int i, j, n, m, k, h;
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
    cout << "ВВедите элементы матрицы" << endl
         << endl;
    int** dob;
    dob = new int*[a];
    for (i = 0; i < n; i++)
        dob[i] = new int[m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> dob[i][j];
    if (b == n) {
        int** q;
        q = new int*[a];
        for (i = 0; i < a; i++)
            q[i] = new int[m];
        for (i = 0; i < a; i++)
            for (j = 0; j < m; j++)
                q[i][j] = 0;
        for (i = 0; i < a; i++)
            for (j = 0; j < m; j++)
                for (k = 0; k < n; k++)
                    q[i][j] += z[i][k] * dob[k][j];
        cout << "Результат:" << endl
             << endl;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++)
                cout << setw(4) << z[i][j];
            cout << endl;
        }
        delete[] dob;
        delete[] q;
    }
    else
        cout << "Неверный размер";
}

void trm(int**& z, int& a, int& b)
{
    int** q = nullptr;
    int i, j;
    q = new int*[b];
    for (i = 0; i < b; i++)
        q[i] = new int[a];
    for (i = 0; i < b; i++)
        for (j = 0; j < a; j++)
            q[i][j] = z[j][i];
    delete[] z;
    z = new int*[b];
    for (i = 0; i < b; i++)
        z[i] = new int[a];
    for (i = 0; i < b; i++)
        for (j = 0; j < a; j++)
            z[i][j] = q[i][j];
    a = i;
    b = j;
    delete[] q;
}

void savef()
{
}

void loadf()
{
}

void sort()
{
}

int main(int argc, char* argv[])
{
    int** z = nullptr;
    int a, b;
    crm(z, a, b, argc, argv);
    setlocale(LC_ALL, "RUS");
    int choise;
    while (true) {
        menu();
        cin >> choise;
        switch (choise) {
        case 1:
            shm(z, a, b);
            break;
        case 2:
            add(z, a, b, argc, argv);
            break;
        case 3:
            umn(z, a, b);
            break;
        case 4:
            trm(z, a, b);
            break;
        case 5:
            savef();
            break;
        case 6:
            loadf();
            break;
        case 7:
            sort();
            break;
        case 8:
            delete[] z;
            return 0;
        default:
            cout << "Неверная команда" << endl;
        }
    }
}

