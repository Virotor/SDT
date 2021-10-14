#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <stdexcept>
template<class  Type>
class Matrix
{
private: 
	Type** value;
	size_t countOfRow;
	size_t countOfColumn;

public:
	

	Matrix<Type>(size_t countOfRow, size_t countOfColumn) {
		this->countOfRow = countOfRow;
		this->countOfColumn = countOfColumn;
		value = nullptr;
	}

	Matrix(const Matrix<Type>& copy) :
		countOfRow(copy.countOfRow),
		countOfColumn(copy.countOfColumn)
	{
		value = new Type*[countOfRow];
		for (size_t i = 0; i < this->countOfRow; ++i) {
			value[i] = new Type[countOfColumn];
			for (size_t j = 0; j < this->countOfColumn; ++j) {
				value[i][j] = copy.value[i][j];
			}
		}
	}



	~Matrix<Type>() {
		for (int i = 0; i < countOfRow; i++) {
			delete[] value[i];
		}

		delete[] value;
	}


	Type getValue(size_t numberOfRow, size_t numberOfColumn);
	friend Matrix<Type> operator*(Matrix<Type>& leftOperand, Matrix<Type>& rightOperand) {
		if (leftOperand.countOfColumn != rightOperand.countOfRow) {
			throw std::invalid_argument("Cant mult matrix");
		}
		Matrix<Type> result(leftOperand.countOfRow, rightOperand.countOfColumn);
		result.initMatrix([]() {return 0; });
		for (int i = 0; i < leftOperand.countOfRow; i++) {
			for (int k = 0; k < rightOperand.countOfRow; k++) {
				for (int j = 0; j < rightOperand.countOfColumn; j++) {
					result.value[i][j] += leftOperand.value[i][k] * rightOperand.value[k][j];
				}
			}
		}
		return result;
	}
	void sortMatrix();
	Matrix<Type>& operator=(const Matrix<Type>& rightOperand);
	Type minValue();
	Type maxValue();
	void initMatrix(const std::function<Type()>& generator);
	void print();
private:
	Type* convertToArray();
	void convertToMatrixFromArray(Type* array);
};

template<class Type>
Type Matrix<Type>::getValue(size_t numberOfRow, size_t numberOfColumn)
{
	if (numberOfRow >= countOfRow || numberOfColumn >= countOfColumn) {
		throw std:: invalid_argument("received invalid value");
	}
	if (numberOfRow < 0 || numberOfColumn < 0) {
		throw std::invalid_argument("received negative  value");
	}
	return value[numberOfRow][numberOfColumn];
}

template<class Type>
void Matrix<Type>::sortMatrix()
{
	Type* temp = convertToArray();
	std:: sort(temp, temp + countOfRow * countOfColumn);
	convertToMatrixFromArray(temp);
}

template<class Type>
Type Matrix<Type>::minValue()
{
	Type minValue = value[0][0];
	for (size_t i = 0; i < countOfRow; i++) {
		for (size_t j = 0; j < countOfColumn; j++) {
			if (minValue > value[i][j]) {
				minValue = value[i][j];
			}
		}
	}
	return minValue;
}

template<class Type>
Type Matrix<Type>::maxValue()
{
	Type maxValue = value[0][0];
	for (size_t i = 0; i < countOfRow; i++) {
		for (size_t j = 0; j < countOfColumn; j++) {
			if (maxValue < value[i][j]) {
				maxValue = value[i][j];
			}
		}
	}
	return maxValue;
}

template<class Type>
void Matrix<Type>::initMatrix(const std::function<Type()>& generator)
{
	value = new Type*[countOfRow];

	for (size_t i = 0; i < countOfRow; i++) {
		value[i] = new Type[countOfColumn];
		for (size_t j = 0; j < countOfColumn; j++) {
			value[i][j] = generator();
		}
	}
}


template<class Type>
Type* Matrix<Type>::convertToArray() {
	Type* arrayResult = new Type[countOfColumn * countOfRow];
	for (size_t i = 0; i < countOfRow; i++) {
		for (size_t j = 0; j < countOfColumn; j++) {
			arrayResult[i * countOfColumn + j] = value[i][j];
		}
	}
	return arrayResult;
}


template<class Type>
void Matrix<Type>::convertToMatrixFromArray(Type* array) {
	for (size_t i = 0; i < countOfRow; i++) {
		for (size_t j=0; j < countOfColumn; j++) {
			value[i][j] = array[i * countOfColumn + j];
		}
	}
}


template<class Type>
void Matrix<Type>::print() {
	for (size_t i = 0; i < countOfRow; i++) {
		for (size_t j = 0; j < countOfColumn; j++) {
			std::cout << value[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


template<class Type>
Matrix<Type>& Matrix<Type>:: operator=(const Matrix<Type>& rightOperand) {
	if (this == &rightOperand) {
		return *this;
	}
	if (value != nullptr) {
		for (int i = 0; i < countOfRow; i++) {
			delete[] value[i];
		}

		delete[] value;
	}
	countOfColumn = rightOperand.countOfColumn;
	countOfRow = rightOperand.countOfRow;
	value = new Type * [countOfRow];
	for (size_t i = 0; i < this->countOfRow; ++i) {
		value[i] = new Type[countOfColumn];
		for (size_t j = 0; j < this->countOfColumn; ++j) {
			value[i][j] = rightOperand.value[i][j];
		}
	}
	return *this;
}