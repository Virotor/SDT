#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	
	int n, secondNumberFibonacci = 0, firstNumberFibonacci = 1;
	cout << "Введите n (n > 0)" << endl;
	cin >> n;
	double factorial = n;
	n--;
	cout << "0 ";
	while (n > 0)
	{
		factorial *= n;
		secondNumberFibonacci += firstNumberFibonacci;
		firstNumberFibonacci = secondNumberFibonacci - firstNumberFibonacci;
		n--;
		cout << secondNumberFibonacci << " ";
	}
	cout << endl << factorial;
	return 0;
}