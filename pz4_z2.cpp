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
	cout << "\nСумма : " << sum << " avg : " << (double)sum / n;
	return 0;
}