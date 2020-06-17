#ifndef MATRIX_H
#define MATRIX_H
#include "includes.h"
#include "Fraction.cpp"

template<class T>
class Matrix
{	
private:
	int rowSize;
	int colSize;
	std::map<int, std::map<int, T>> rows;
public:
	Matrix() {};
	Matrix(int, int);
	Matrix(std::vector<T>);
	void swapRow(int rowID1, int rowID2);
	void swapCol(int colID1, int colID2);
	std::vector<T> getRow(int key);
	std::vector<T> getCol(int key);
	T getValue(int row, int col);
	T* getObj(int rowID, int colID);
	void setValue(int row, int col, T val);
	T multiplyVector(std::vector<T> &v1, std::vector<T> &v2);
	Matrix operator*(Matrix<T> &m );
};

template <>
class Matrix<int>
{
private:
	int rowSize;
	int colSize;
	std::map<int, std::map<int,int>> rows;
public:		
	Matrix() {};
	Matrix(int, int);
	Matrix(std::vector<int>);
	void swapRow(int rowID1, int rowID2);
	void swapCol(int colID1, int colID2);	
	static Matrix<int> copy(Matrix<int> &m);
	std::vector<int> getRow(int key);
	std::vector<int> getCol(int key);	
	int getValue(int row, int col) const;
	void setValue(int row, int col, int val);
	void resize(int rowSize, int colSize);
	bool isRegular();
	bool isDimensionEqual(const Matrix &m);
	bool isSymmetric();
	Matrix<int> transpose();	
	std::vector<int> rowSum();
	std::vector<int> colSum();
	static int multiplyVector(std::vector<int> &v1, std::vector<int> &v2);
	bool operator==(const Matrix<int> &m);
	Matrix operator+(const Matrix<int> &m);
	Matrix operator-(const Matrix<int> &m);
	Matrix operator*(const int v);
	std::vector<int> operator*(const std::vector<int> &v);
	Matrix operator*(Matrix<int> &m);
	int determinant();	
};

//template<>
//class Matrix<bool>
//{
//private:
//	int rowSize;
//	int colSize;
//protected:
//	std::map<int, mRow<bool>> rows;
//public:		
//	bool getValue(int row, int col);
//	void setValue(int row, int col, bool val);
//	void resize(int rowSize, int colSize);
//	bool isDimensionEqual(Matrix &m);
//	bool isSymmetric();
//	Matrix<bool> transpose();
//	bool operator==(const Matrix<bool> &m);
//	Matrix operator!();	
//	Matrix operator&&(const Matrix &m);
//	Matrix operator||(const Matrix &m);	
//	bool isTautologic();		
//};

//template<>
//class Matrix<double>
//{
//private:
//	int rowSize;
//	int colSize;
//protected:
//	std::map<int, mRow<double>> rows;
//public:					
//	double getValue(int row, int col);
//	void setValue(int row, int col, double val);
//	void resize(int rowSize, int colSize);
//	bool isRegular();
//	bool isDimensionEqual(Matrix &m);
//	bool isSymmetric();
//	Matrix<double> transpose();	
//	std::vector<double> rowSum();
//	std::vector<double> colSum();
//	bool operator==(const Matrix<double> &m);
//	Matrix operator+(const Matrix<double> &m);
//	Matrix operator-(const Matrix<double> &m);
//	Matrix operator*(const double v);
//	std::vector<double> operator*(const std::vector<double> &v);
//	Matrix operator*(const Matrix<double> &m);
//	double determinant();	
//};

#endif

