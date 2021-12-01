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


	for (int i = 1 ; i <= length; i++ )
	{

		for (int j= 1; j <= width; j++)
		{
			cout << symbol;
		}
		cout << endl;
	}
	cout << endl << endl;

	return 0;
}