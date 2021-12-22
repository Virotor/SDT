#include <iostream>
#include <ctime>
using namespace std;

int FindSymbol(int arr[],int sym,int size) {
	int ans = 0;
	for (int i = 0; i < size; i++) if (arr[i] == sym) ans++;
	return ans;
}

int FindSymbol(string s, char sym) {
	int ans = 0;
	for (int i = 0; i < s.length(); i++) if (s[i] == sym) ans++;
	return ans;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int sym;
	cin >> sym;
	cout << "Int : " << FindSymbol(arr, sym, n) << endl;
	string s;
	cin >> s;
	char symc;
	cin >> symc;
	cout << "Char : " << FindSymbol(s, symc);
	return 0;
}