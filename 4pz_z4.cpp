#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n, k, sum = 0, choice;
	cout << "Введите размер массива n: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Маccив \n1. Клавиатура\n2. Рандом (default)" << endl;
	cin >> choice;
	if (choice != 1) {
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 100 - 50;
			sum += arr[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
	}
	cout << "Полученный массив : ";
	for (int i = 0; i < n; i++) cout << arr[i] << " ";

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) swap(arr[j], arr[i]);
		}
	}

	if(n % 2 == 0) cout << "\nМедиана массива : " << (arr[(n / 2) - 1] + arr[(n / 2)]) / 2. << endl;
	else cout << "Медиана массива : " << arr[n / 2] << endl;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == arr[i]) {
				for (int k = j; k < n; k++) arr[k] = arr[k + 1];
				n--; i--;
			}
		}
	}

	cout << "\nПолученный массив : ";
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}