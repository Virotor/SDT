#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	
	int firstNumber, secondNumber;
	cin >> firstNumber >> secondNumber;
	bool isSimple = true; //isSample
	for (int i = 2; i <= sqrt(firstNumber); i++) {
		if (firstNumber % i == 0) {
			cout << "Первое число не является простым!" << endl;
			isSimple = false;
			break;
		}
	}
	if (isSimple == true){
		cout << "Первое число простое!" << endl;
	}

	isSimple = true;
	for (int i = 2; i <= sqrt(secondNumber); i++) {
		if (secondNumber % i == 0) {
			cout << "Второе число не является простым!" << endl;
			isSimple = false;
			break;
		}
	}
	if (isSimple == true) cout << "Второе число простое!" << endl;

	if(firstNumber>secondNumber){
		swap(firstNumber,secondNumber);
	} 
	for (int i = firstNumber; i >= 1; i--) {
		if (secondNumber % i == 0 && firstNumber % i == 0) {
			cout << "НОД - " << i << endl;
			break;
		}
	}
	return 0;
}
