#include<iostream>
#include<string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	
	int number;
	cin >> number;
	string convertedNumberToBinary  = "";
	while (number > 0) {
		convertedNumberToBinary = char(number % 2 + 48) + convertedNumberToBinary;
		number /= 2;
	}
	cout << convertedNumberToBinary;
	return 0;
}