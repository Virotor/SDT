#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	
	int a, b;
	cin >> a >> b;
	bool ok = true;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			cout << "Первое число не является простым!" << endl;
			ok = false;
			break;
		}
	}
	if (ok == true) cout << "Первое число простое!" << endl;

	ok = true;
	for (int i = 2; i <= sqrt(b); i++) {
		if (b % i == 0) {
			cout << "Второе число не является простым!" << endl;
			ok = false;
			break;
		}
	}
	if (ok == true) cout << "Второе число простое!" << endl;

	if (a > b) swap(a,b);
	for (int i = a; i >= 1; i--) {
		if (b % i == 0 && a % i == 0) {
			cout << "НОД - " << i << endl;
			break;
		}
	}
	return 0;
}