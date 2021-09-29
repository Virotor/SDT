#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int num;
	cout << "Номер";
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "Понедельник" << endl;
		break;
	case 2:
		cout << "Вторник" << endl;
		break;
	case 3:
		cout << "Среда " << endl;
		break;
	case 4:
		cout << "четверг " << endl;
		break;
	case 5:
		cout << "Пятница " << endl;
		break;
	case 6:
		cout << "суббота " << endl;
		break;
	case 7:
		cout << "воскресение " << endl;
		break;
	}
	return 0;
}