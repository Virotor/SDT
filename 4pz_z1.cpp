#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n, k, sum = 0, choice;
	cout << "Введите размеры матрицы n*k : ";
	cin >> n >> k;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) arr[i] = new int[k];
	cout << "Матрица 1\n1. Клавиатура\n2. Рандом (default)" << endl;
	cin >> choice;
	if (choice != 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				arr[i][j] = rand() % 100 - 50;
				sum += arr[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				cin >> arr[i][j];
				sum += arr[i][j];
			}
		}
	}
	cout << "Полученная Матрица : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}