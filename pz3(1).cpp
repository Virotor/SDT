#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int length, width;

	cout << "Введите длину прямоугольника" << endl;
	cin >> length;

	cout << "Введите ширину прямоугольника" << endl;
	cin >> width;

	cout << "Площадь заданного прямоугольника = " << length * width << endl
		<< "Периметр заданного прямоугольника =" << 2 * (length + width) << endl;

	char symbol;

	cout << "Введите символ которым будет нарисован прямоугольник " << endl;
	cin >> symbol;


	for (int index1 = 1 ; index1 <= length; index1++ )
	{

		for (int index2 = 1; index2 <= width; index2++)
		{
			cout << symbol;
		}
		cout << endl;
	}
	cout << endl << endl;

	return 0;
}
