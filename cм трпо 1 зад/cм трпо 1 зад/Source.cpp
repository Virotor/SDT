#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double dlina, shirina, visota, dlinaOterstia,shirinaOtverstia;
	cout << "Введите длинну = ";
	cin >> dlina;
	cout << "Введите ширину = ";
	cin >> shirina;
	cout << "Введите высоту = ";
	cin >> visota;
	cout << "Введите длинну отверстрия = ";
	cin >> dlinaOterstia;
	cout << "Введите ширину отверстия = ";
	cin >> shirinaOtverstia;
	if ((dlina < dlinaOterstia) && (shirina < shirinaOtverstia)) {
		cout << "Пройдет через отверстие  " << endl;
	}
	else {
		if ((dlina < shirinaOtverstia) && (shirina < dlinaOterstia)) {
			cout << "Пройдет через отверстие  " << endl;
		}
		else {
			if (((visota < shirinaOtverstia)||(visota < dlinaOterstia)) && ((dlina < shirinaOtverstia) || (dlina < dlinaOterstia))) {
				cout << "Пройдет через отверстие "<<endl;
			}
			else {
				if ((visota < shirinaOtverstia) || (visota < dlinaOterstia) && ((shirina < shirinaOtverstia) || (shirina < dlinaOterstia))) {
					cout << "Пройдет в отверстие " << endl;
				}
				else {
					cout << "Не пройдет в отверстие " << endl;
				}
			}
		}
	}
	
}