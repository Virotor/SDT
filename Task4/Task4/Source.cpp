#include <iostream>

using namespace std;


namespace task4
{

	const int SIZE_OF_ARRAY = 100;



	void printMatrix(int** matrix, int row, int column);

	int** initMatrix(int row, int column);
	double** initMatrix(double row, double column);

	int main() {

		int row = 4, column = 4;

		int** matrix = initMatrix(row, column);


		printMatrix(matrix, 4, 4);

		return 0;
	}



	void printMatrix(int** matrix, int row, int column) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	int** initMatrix(int row, int column) {
		int** matrix = new int* [row];

		for (int i = 0; i < row; i++) {
			matrix[i] = new int[column];
			for (int j = 0; j < column; j++) {
				matrix[i][j] = rand() % 20 - 10;
			}
		}
		return matrix;
	}

}