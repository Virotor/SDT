#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

const size_t sizeOfArray = 10000000;


bool sumAB(int* result, int a, int b);
int* sumAB(bool* isSum, int* a, int* b);

int main() {

	int a = 10;
	int b = 20;

	int result=0;

	bool isSum = false;
	int* dynamicArray = new int[a];

	for (int i = 0; i < a; i++) {
		dynamicArray[i] = rand() % 10;
	}

	sort(dynamicArray, dynamicArray + a);

	for (int i = 0; i < a; i++) {
		cout << dynamicArray[i] << " ";
	}
	cout << dynamicArray[a / 2] << endl;
	/*for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << dynamicArray[i][j] << " ";
		}
		cout << endl << " ";
	}*/



	result = *sumAB(&isSum, &a, &b);
	if(isSum)
		cout << result << " " << a << " " << b << endl;

	system("pause");
	return 0;
}


int* sumAB(bool* isSum, int* a, int* b) {

	int result = *a + *b;
	(*a)++;
	(*b)++;
	*isSum = true;
	return &result;
}