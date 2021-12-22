#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");//Позволяет юзать русский
	string s;//Объявление строки s
	cout << "Введите целое число" << endl;
	cin >> s;
	for (int i = 0; i < s.length(); i++) cout << s[i] << endl; /*for - цикл,
	 .length() - функция для нахождения длины строки,
	 выводим элементы массива с шагом 1 пока не наступит конец строки(выводим их с новой строки)*/
	return 0;
}