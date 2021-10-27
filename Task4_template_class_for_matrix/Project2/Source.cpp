/**
      ---------------------------------------------------
      |         Made by Shamal Viktor (@j3uktop)        |
      |           2019-2021 - Lyceum BSU - IM           |
      |             2021 - BSUIR - FCP - PMS            |
      |          *** All rights reserved ***            |
      ---------------------------------------------------
                                                        **/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <ctime>

    using std::cout;
using std::cin;
using std::setw;
using std::sort;

const int SPACE = 5;

class matrix {
private:
    double** values;
    int row;
    int col;
public:
    matrix() {
        row = 0;
        col = 0;
    }
    ~matrix();
    void init(int _row, int _col);
    void init();
    void print();
    void sort_elements();
    double getMaximumElement();
    double getMinimumElement();
    double getMediumValue();
    matrix operator*(matrix& matr2);
};

void deleteDuplicateItems(double* array, int& array_size);

double getMediumValue(double* array, int& array_size);

void taskPrint();

double* getArray(int& array_size);

void taskSum();

void taskMultiply();

void taskDelete();

void taskMatrixMedian();

template<typename T>
T max(T first, T second) {
    if (first < second)
        first = second;
    return first;
}

int main() {
    srand(time(NULL));
    taskPrint();
    taskSum();
    taskMultiply();
    taskDelete();
    taskMatrixMedian();
    system("pause");
    return 0;
}

void taskPrint() {
    cout << "Task 1: Print N*K Matrix\n\n";
    matrix matr1;
    matr1.init();
    cout << "Matrix:\n";
    matr1.print();
    cout << "\n\n";
}

double* getArray(int& array_size) {
    cout << "Enter array size\n";
    cout << "size = ";
    cin >> array_size;
    while (array_size < 1) {
        cout << "Input error. Size must be > 0\n";
        cout << "size = ";
        cin >> array_size;
    }
    double* array = new double[array_size];
    cout << "Generate random elements? [Y/N]: ";
    char user_answer = _getche();
    cout << "\n";
    if (user_answer == 'Y' || user_answer == 'y') {
        double interval_start;
        double interval_finish;
        cout << "Enter the number generation interval\n";
        cout << "Min value = ";
        cin >> interval_start;
        cout << "Max value = ";
        cin >> interval_finish;

        int mod = std::abs(interval_start - interval_finish) + 1;
        mod = max(2, mod);
        cout << "Interval: " << interval_start << ".."
            << int(interval_start) + mod - 1 << '\n';

        for (int ind = 0; ind < array_size; ind++) {
            ind[array] = rand() % mod + interval_start;
        }
        cout << "Array:\n";
        for (int ind = 0; ind < array_size; ind++) {
            cout << ind[array] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "Enter " << array_size << " elements\n";
        for (int ind = 0; ind < array_size; ind++) {
            cin >> ind[array];
        }
    }
    return array;
}

void taskSum() {
    cout
        << "Task2: Get the sum and average value of the elements in the array\n\n";
    int size;
    double* value;
    value = getArray(size);
    double sum = 0;
    for (int ind = 0; ind < size; ind++) {
        sum += value[ind];
    }
    cout << "Sum = " << sum << '\n';
    double average = double(sum) / size;
    cout << "Average = " << average << '\n';

    cout << "\n\n";
    delete[] value;
}

void taskMultiply() {
    cout << "Task3: Matrix multiply\n\n";
    matrix matr1;
    matrix matr2;
    cout << "First Matrix\n\n";
    matr1.init();
    cout << "\n";
    matr1.print();

    cout << "Second Matrix\n\n";
    matr2.init();
    cout << "\n";
    matr2.print();

    cout << "\nResult:\n";
    matrix matr3 = matr1 * matr2;
    matr3.print();

    cout << "\n\n";
}

double getMediumValue(double* array, int& array_size) {
    sort(array, array + array_size);
    double medium;
    if (array_size % 2 == 0) {
        return (array[array_size / 2] + array[array_size / 2 - 1]) / 2;
    }
    else {
        return array[array_size / 2];
    }
}

void deleteDuplicateItems(double* array, int& array_size) {
    sort(array, array + array_size);
    int left = 0;
    int right = 0;
    while (true) {
        while (array[left] == array[right] && right < array_size) {
            right++;
        }
        left++;
        if (right == array_size) {
            break;
        }
        array[left] = array[right];
    }
    array_size = left;
}

void taskDelete() {
    cout << "Task4: Find array medium value and delete duplicate values.\n\n";
    double* value;
    int size;
    value = getArray(size);
    cout << "Medium value = " << getMediumValue(value, size) << '\n';
    cout << "Array after deleting duplicate values:\n";
    deleteDuplicateItems(value, size);
    for (int ind = 0; ind < size; ind++) {
        cout << value[ind] << ' ';
    }
    cout << "\n\n\n";
    delete[] value;
}

void taskMatrixMedian() {
    cout << "Task 5: Find matrix maximum, minimum elements and medium value\n\n";
    matrix matr;
    matr.init();
    cout << "Matrix:\n";
    matr.print();
    matr.sort_elements();
    cout << "\n\n";
    cout << "Minimal element = " << matr.getMinimumElement() << '\n';
    cout << "Medium value = " << matr.getMediumValue() << '\n';
    cout << "Maximal element = " << matr.getMaximumElement() << '\n';

    cout << "\n\n";
}

void matrix::init() {
    cout << "Enter matrix size:\n";
    cout << "row count = ";
    cin >> row;
    cout << "col count = ";
    cin >> col;
    while (row < 1 || col < 1) {
        cout << "Input error. Row and col count must be >= 1\n";
        cout << "row count = ";
        cin >> row;
        cout << "col count = ";
        cin >> col;
    }
    int mod;
    double interval_start;
    double interval_finish;
    cout << "Enter the number generation interval\n";
    cout << "Min value = ";
    cin >> interval_start;
    cout << "Max value = ";
    cin >> interval_finish;

    while (interval_start >= interval_finish) {
        cout << "Interval input error\n";
        cout << "Min value = ";
        cin >> interval_start;
        cout << "Max value = ";
        cin >> interval_finish;
    }
    mod = (interval_finish - interval_start + 1);

    values = new double* [row];
    for (int i = 0; i < row; i++) {
        values[i] = new double[col];
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            values[r][c] = rand() % mod + interval_start;
        }
    }
}

void matrix::init(int _row, int _col) {
    if (_row < 1) {
        _row = 0;
    }
    if (_col < 1) {
        _col = 0;
    }
    row = _row;
    col = _col;
    values = new double* [row];
    for (int i = 0; i < row; i++) {
        values[i] = new double[col];
    }
}

matrix::~matrix() {
    for (int i = 0; i < row; i++) {
        delete[] values[i];
    }
    delete[] values;
}

void matrix::print() {
    if (row < 1 || col < 1) {
        cout << "Error. Invalid matrix to print\n";
        return;
    }
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << setw(SPACE) << values[r][c] << ' ';
        }
        cout << '\n';
    }
}

matrix matrix::operator*(matrix& matr2) {
    matrix result;
    if (row < 1 || col < 1 || matr2.row < 1 || matr2.col < 1
        || col != matr2.row) {
        cout << "Error. Invalid matrix to multiply\n";
        result.init(0, 0);
        return result;
    }
    result.init(row, matr2.col);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < matr2.col; c++) {
            double buf_result = 0;
            for (int check = 0; check < col; check++) {
                buf_result += values[r][check] * matr2.values[check][c];
            }
            result.values[r][c] = buf_result;
        }
    }
    return result;
}

void matrix::sort_elements() {
    int size = col * row;
    double* buf_array = new double[size];
    for (int ind = 0; ind < size; ind++) {
        buf_array[ind] = values[ind / col][ind % col];
    }
    sort(buf_array, buf_array + size);
    for (int ind = 0; ind < size; ind++) {
        values[ind / col][ind % col] = buf_array[ind];
    }
    delete[] buf_array;
}

double matrix::getMaximumElement() {
    return values[row - 1][col - 1];
}

double matrix::getMinimumElement() {
    return values[0][0];
}

double matrix::getMediumValue() {
    double medium_value;
    if (col * row % 2 == 0) {
        int first_col = (row * col / 2 - 1) / col;
        int first_row = (row * col / 2 - 1) % col;
        int second_col = (row * col / 2) / col;
        int second_row = (row * col / 2) % col;
        medium_value = (values[first_row][first_col] + values[second_row][second_col]) / 2;
    }
    else {
        medium_value = values[row / 2][col / 2];
    }
    return medium_value;
}
