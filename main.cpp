#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int crm(int**& z, int& a, int& b, int argc, char* argv[])
{
    int i, j, k;
    k = 2;
    string x, y;
    for (i = 0; argv[1][i] != 'x' && argv[1][i] != 'X'; i++)
        x = x + argv[1][i];
    for (i + 1; argv[1][i] != '\0'; i++)
        y = y + argv[1][i];
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
        for (j = 0; j < b; j++, k++)
        {
            if (k < argc)
                z[i][j] = atoi(argv[k]);
        }
}

void menu()
{
    cout << endl;
    cout << "Выберете одну из операций" << endl << endl;
    cout << "1. Вывести матрицу" << endl;
    cout << "2. Сложить матрицу" << endl;
    cout << "3. Умножить матрицу" << endl;
    cout << "4. Транспонировать матрицу" << endl;
    cout << "5. Сохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << "7. Сортировать матрицу " << endl;
    cout << "8. Завершить работу программы" << endl;
}

void shm(int** z, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cout << setw(4) << z[i][j];
        cout << endl;
    }
}

void add()
{
}

void umn()
{
}

void trm()
{
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
    while (true)
    {
        menu();
        cin >> choise;
        switch (choise)
        {
            case 1:
                shm(z, a, b);
                break;
            case 2:
                add();
                break;
            case 3:
                umn;
                break;
            case 4:
                trm();
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
                return 0;
            default:
                cout << "Неверная команда" << endl;
        }
    }
}

