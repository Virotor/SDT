#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	
	int a;
	cin >> a;
	string s = "";
	while (a > 0) {
		s = (char)(a % 2 + 48) + s;
		a /= 2;
	}
	cout << s;
	return 0;
}