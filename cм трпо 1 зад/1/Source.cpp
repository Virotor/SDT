#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int ch;
	cout << "¬ведите число = ";
	cin >> ch;
	int del = 1;
	while ((ch / del) >= 1)
	{
		del *= 10;
	}
	del = del / 10;
	while (del >= 1);
	{
		cout << (ch / del) % 10 << endl;
		del /= 10;
	}
}