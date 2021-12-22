#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	long long n, k;// тип данных(намного больше int )
 cout << "Введите n " << endl;
 cin >> n;
 cout << "Введите k" << endl;
 cin >> k;
	long long temp = n, count = 0;
	while (temp > 0) {
		temp /= 10;
		count++;
	}
	if (k > count)
		cout << "Необходимо выбрать другое k" << endl;
	long long deg = pow(10, count - k);
	cout << n / deg;
	return 0;
}