#include "matrix.h"

using namespace std;

int main() {

	int row = 4, column = 4;


	Matrix<int> matA(row,column);
	Matrix<int> matB(row,column);

	matA.initMatrix([]() {return rand() % 5 ; });
	matB.initMatrix([]() {return rand() % 5; });

	cout << "First matrix" << endl;
	matA.print();
	cout << "\nSecond matrix" << endl;
	matB.print();
	Matrix<int> matC = matA * matB;
	cout << "\nResult matrix" << endl;
	matC.print();
	return 0;
}

