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

string DigToS(double n,int radix) {
	string s1 = DigToS((int)n), s2 = "";
	s1 += ',';
	double r = n - (int)n;
	for (int i = 0; i < radix; i++) {
		r *= 10;
		s2 += (char)(((int)r % 10) + 48);
	}
	return s1 + s2;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n;
	double d;
	cin >> n >> d;
	cout << DigToS(n) << endl;
	cout << DigToS(d, 2);
	return 0;
}