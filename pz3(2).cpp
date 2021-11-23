#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	
	int n, a = 0, b = 1;
	cout << "Введите n (n > 0)" << endl;
	cin >> n;
	double fact = n;
	n--;
	cout << "0 ";
	while (n > 0)
	{
		fact *= n;
		a += b;
		b = a - b;
		n--;
		cout << a << " ";
	}
	cout << endl << fact;
	return 0;
}
