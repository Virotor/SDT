#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "Умножение невозможно!";
        return 0;
    }
    int** a = new int* [r1];
    int** b = new int* [r2];
    int** c = new int* [r1];
    
    cout << "Введите элементы первой матрицы :" << endl;
    for (int i = 0; i < r1; i++) {
        a[i] = new int[c1];
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "Введите элементы второй матрицы :" << endl;
    for (int i = 0; i < r2; i++) {
        b[i] = new int[c2];
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }

    cout << "M1 : " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "M2" << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    
    for (int i = 0; i < r1; i++)
    {
        c[i] = new int[c2];
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    
    cout << "Итоговая матрица" << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}