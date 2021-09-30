#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	int W, H, w, h, l;
	cout << "Введите ширина отверстия" << endl;
	cin >> W;
	cout << "Введите высота отверстия" << endl;
	cin >> H;
	cout << "Введите ширина параллелепипеда" << endl;
	cin >> w;
	cout << "Введите длина параллелепипеда" << endl;
	cin >> l;
	cout << "Введите высоту параллелепипеда" << endl;
	cin >> h;
	if (W >= w && H >= h ||
		W >= w && H >= l ||
		W >= h && H >= w ||
		W >= h && H >= l ||
		W >= l && H >= w ||
		W >= l && H >= h) cout << "Пройдёт";
	else cout << "Не пройдёт";
	return 0;
}