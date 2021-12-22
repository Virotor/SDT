#include <iostream>
#include <ctime>
using namespace std;

string DigToS(int n) {
	string s = "";
	while (n > 0) {
		s = (char)((n % 10) + 48) + s;
		n /= 10;
	}
	return s;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	cout << DigToS(n);
	return 0;
}