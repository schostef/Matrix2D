#include "Matrix.h"

using namespace std;
//Type Gen
template<class T>
Matrix<T>::Matrix(int rows, int cols)
{
	rowSize = rows;
	colSize = cols;
	for (int i = 0; i < rowSize; i++)
	{
		std::map<int,T> r{};

		for (int j = 0; j < colSize; j++)
			r.insert(std::make_pair(j, T{}));
		this->rows.insert(std::make_pair(i, r));
	}
}

template<class T>
Matrix<T>::Matrix(std::vector<T> diagonal)
{
	rowSize = colSize = (int)diagonal.size();

	for (int i = 0; i < rowSize; i++)
	{
		std::map<int,T> r{};

		for (int j = 0; j < colSize; j++)
			(i == j) ? r.insert(std::make_pair(j, diagonal[i])) : r.insert(std::make_pair(j, T{}));
		this->rows.insert(std::make_pair(i, r));
	}
}

template<class T>
void Matrix<T>::swapRow(int rowID1, int rowID2)
{
	std::map<int,T> row1 = rows.at(rowID1);
	std::map<int,T> row2 = rows.at(rowID2);
	rows.erase(rowID1);
	rows.erase(rowID2);
	rows.insert(std::make_pair(rowID1, row2));
	rows.insert(std::make_pair(rowID2, row1));
}

template<class T>
void Matrix<T>::swapCol(int colID1, int colID2)
{
	for (typename std::map<int, std::map<int,T>>::iterator it = rows.begin(); it != rows.end(); ++it)
	{
		T col1 = it->second.at(colID1);
		T col2 = it->second.at(colID2);
		it->second.erase(colID1);
		it->second.erase(colID2);
		it->second.insert(std::make_pair(colID1, col2));
		it->second.insert(std::make_pair(colID2, col1));
	}
}

template<class T>
std::vector<T> Matrix<T>::getRow(int key)
{
	vector<T> v{};
	for (typename std::map<int, T>::iterator it = rows.at(key).begin(); it != rows.at(key).end(); ++it)
		v.push_back(it->second);
	return v;
}

template<class T>
std::vector<T> Matrix<T>::getCol(int key)
{
	std::vector<T> v{};
	for (int i = 0; i < rowSize; i++)
		v.push_back(getRow(i).at(key));	
	return v;
}

template<class T>
T Matrix<T>::getValue(int rowID, int colID)
{
	return rows.at(rowID).at(colID);
}

template<class T>
T* Matrix<T>::getObj(int rowID, int colID)
{
	return &rows.at(rowID).at(colID);
}

template<class T>
void Matrix<T>::setValue(int row, int col, T val)
{
	rows.at(row).at(col) = val;
}

template<class T>
T Matrix<T>::multiplyVector(std::vector<T> &v1, std::vector<T> &v2)
{
	if (v1.size() != v2.size())
	{
		throw std::invalid_argument("Vectors are not the same size!");
	}
	else
	{
		T res{};
		for (unsigned int i = 0; i < v1.size(); i++)
			res += v1[i] * v2[i];
		return res;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &m )
{
	if (rowSize != m.colSize)
		throw std::invalid_argument("Matrix A's rowsize is not equal to Matrix B's columnsize!");

	Matrix<T> res = Matrix<T>(m.rowSize, m.colSize);

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < m.colSize; j++)
		{
			vector<T> v1 = getRow(i);
			vector<T> v2 = m.getCol(j);
			
			res.setValue(i, j, Matrix<T>::multiplyVector(v1, v2));
		}
	return res;
}


//Type INT
Matrix<int>::Matrix(int rows, int cols)
{
	rowSize = rows;
	colSize = cols;
	for (int i = 0; i < rowSize; i++)
	{
		std::map<int,int> r;

		for (int j = 0; j < colSize; j++)
			r.insert(std::make_pair(j, int{}));
		this->rows.insert(std::make_pair(i, r));
	}
}

Matrix<int>::Matrix(std::vector<int> diagonal)
{
	rowSize = colSize = (int) diagonal.size();

	for (int i = 0; i < rowSize; i++)
	{
		std::map<int,int> r;

		for (int j = 0; j < colSize; j++)
			(i == j) ? r.insert(std::make_pair(j, diagonal[i])) : r.insert(std::make_pair(j, int{}));
		this->rows.insert(std::make_pair(i, r));
	}
}

std::vector<int> Matrix<int>::getRow(int key)
{
	vector<int> v{};
	for (std::map<int, int>::iterator it = rows.at(key).begin(); it != rows.at(key).end(); ++it)
		v.push_back(it->second);
	return v;
}

std::vector<int> Matrix<int>::getCol(int key)
{
	std::vector<int> v{};
	for (std::map<int, std::map<int,int>>::iterator it = rows.begin(); it != rows.end(); ++it)
		v.push_back(it->second.at(key));
	return v;
}

void Matrix<int>::swapRow(int rowID1, int rowID2)
{
	std::map<int,int> row1 = rows.at(rowID1);
	std::map<int,int> row2 = rows.at(rowID2);
	rows.erase(rowID1);
	rows.erase(rowID2);
	rows.insert(std::make_pair(rowID1, row2));
	rows.insert(std::make_pair(rowID2, row1));
}

void Matrix<int>::swapCol(int colID1, int colID2)
{
	for (std::map<int, std::map<int,int>>::iterator it = rows.begin(); it != rows.end(); ++it)
	{
		int col1 = it->second.at(colID1);
		int col2 = it->second.at(colID2);
		it->second.erase(colID1);
		it->second.erase(colID2);
		it->second.insert(std::make_pair(colID1, col2));
		it->second.insert(std::make_pair(colID2, col1));
	}	
}

Matrix<int> Matrix<int>::copy(Matrix<int> &m)
{
	Matrix t{ Matrix(m.rowSize, m.colSize) };
	for (int i = 0; i < m.rowSize; i++)
		for (int j = 0; j < m.colSize; j++)
			t.setValue(i, j, m.getValue(i, j));
	return t;
}

int Matrix<int>::multiplyVector(std::vector<int> &v1, std::vector<int> &v2)
{
	if (v1.size() != v2.size())
	{
		throw std::invalid_argument("Vectors are not the same size!");
	}
	else
	{
		int res{};
		for (unsigned int i = 0; i < v1.size(); i++)
			res += v1[i] * v2[i];
		return res;
	}
}

int Matrix<int>::getValue(int rowID, int colID) const
{
	return rows.at(rowID).at(colID);
}

void Matrix<int>::setValue(int row, int col, int val)
{
	rows.at(row).at(col) = val;
}

void Matrix<int>::resize(int rowSize, int colSize)
{
	if (rowSize < this->rowSize)
	{
		for (int i = rowSize; i < this->rowSize; i++)
			rows.erase(i);
	}
	else if (rowSize > this->rowSize)
	{
		for (int i = this->rowSize; i < rowSize; i++)
		{
			std::map<int,int> r;

			for (int j = 0; j < this->colSize; j++)
				r.insert(std::make_pair(j, int{}));
			rows.insert(std::make_pair(i, r));
		}
	}
	this->rowSize = rowSize;

	if (colSize < this->colSize)
	{
		for (int i = 0; i < rowSize; i++)
			for (int j = colSize; j < this->colSize; j++)
				rows.at(i).erase(j);
	}
	else if (colSize > this->colSize)
	{
		for (int i = 0; i < this->rowSize; i++)
			for (int j = this->colSize; j < colSize; j++)
				rows.at(i).insert(std::make_pair(j, int{}));
	}
	this->colSize = colSize;
}

bool Matrix<int>::isRegular()
{
	return determinant() != 0;
}

bool Matrix<int>::isDimensionEqual(const Matrix<int> &m)
{
	return (m.rowSize == rowSize && m.colSize == colSize);;
}

bool Matrix<int>::isSymmetric()
{
	return *this == transpose();
}

Matrix<int> Matrix<int>::transpose()
{
	Matrix<int> m = copy(*this);
	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			if (i != j)
				m.setValue(i, j, getValue(j, i));
	return m;
}

std::vector<int> Matrix<int>::rowSum()
{
	vector<int> sumVector{};

	for (int i = 0; i < this->rowSize; i++)
	{
		int sum{};
		for (int j = 0; j < this->colSize; j++)
			sum += getValue(i, j);
		sumVector.push_back(sum);
	}

	return sumVector;
}
std::vector<int> Matrix<int>::colSum()
{
	vector<int> sumVector{};

	for (int i = 0; i < colSize; i++)
	{
		int sum{};
		for (int j = 0; j < rowSize; j++)
			sum += getValue(j, i);
		sumVector.push_back(sum);
	}

	return sumVector;
}

bool Matrix<int>::operator==(const Matrix<int>& m)
{
	if (!isDimensionEqual(m))
		return false;

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			if (m.rows.at(i).at(j) != rows.at(i).at(j))
				return false;

	return true;
}

Matrix<int> Matrix<int>::operator+(const Matrix<int>& m)
{
	if (!isDimensionEqual(m))
		throw std::invalid_argument("Matrizes must be of equal Type!");

	Matrix res = Matrix(rowSize, colSize);

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			res.setValue(i, j, getValue(i, j) + m.getValue(i, j));

	return res;
}

Matrix<int> Matrix<int>::operator-(const Matrix<int> &m)
{
	if (!isDimensionEqual(m))
		throw std::invalid_argument("Matrizes must be of equal Type!");

	Matrix res = Matrix(rowSize, colSize);

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			res.setValue(i, j, getValue(i, j) - m.getValue(i, j));

	return res;
}

Matrix<int> Matrix<int>::operator*(const int v)
{
	Matrix res = Matrix(rowSize, colSize);

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			res.setValue(i, j, getValue(i, j) * v);

	return res;
}

std::vector<int> Matrix<int>::operator*(const std::vector<int> &v)
{
	if (this->colSize != v.size())
		throw std::invalid_argument("Vector component-size must match the Matrix's column-size!");

	std::vector<int> res{};

	for (int i = 0; i < this->rowSize; i++)
	{
		int sum{};
		for (int j = 0; j < this->colSize; j++)
			sum += getValue(i, j)*v[j];
		res.push_back(sum);
	}
	return res;
}

Matrix<int> Matrix<int>::operator*(Matrix<int> &m)
{
	if (colSize != m.rowSize)
		throw std::invalid_argument("Matrix A's columsize is not equal to Matrix B's rowsize!");

	Matrix res = Matrix(rowSize, m.colSize);

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < m.colSize; j++)
		{
			vector<int> v1 = getRow(i);
			vector<int> v2 = m.getCol(j);
			res.setValue(i, j, Matrix::multiplyVector(v1,v2));
		}			
	return res;
}
int Matrix<int>::determinant()
{
	if (rowSize == 1 && colSize == 1)
		return getValue(0, 0);
	else if (rowSize == 2 && colSize == 2)
		return getValue(0, 0)*getValue(1, 1) - getValue(0, 1)*getValue(1, 0);
	else if (rowSize == 3 && colSize == 3)
	{
		//Sarrus Rule
		return getValue(0, 0)*getValue(1, 1)*getValue(2, 2) + getValue(0, 1)*getValue(1, 2)*getValue(2, 0) + getValue(0, 2)*getValue(1, 0)*getValue(2, 1) -
			getValue(2, 0)*getValue(1, 1)*getValue(0, 2) - getValue(2, 1)*getValue(1, 2)*getValue(0, 0) - getValue(2, 2)*getValue(1, 0)*getValue(0, 1);
		
	}
	else if (rowSize == colSize)
	{
		//Gauﬂ Algorithm
		
		Matrix<Fraction> A = Matrix<Fraction>(rowSize,rowSize); 
		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < rowSize; j++)
				A.getObj(i, j)->setNumerator(getValue(i, j));						
		
		int pivot[2]{};
		int multiplier{ 1 };
		
		for (int pivotRow = 0; pivotRow < rowSize; pivotRow++)
		{
			//Init multiplication Matrix Z as Unit Matrix
			std::vector<Fraction> a{};
			for (int i = 0; i < rowSize; i++)
				a.push_back(Fraction(1,1));
			Matrix<Fraction> Z = Matrix<Fraction>(a);

			// find highest |Value(i,j)|
			std::vector<Fraction> pivotCol = A.getCol(pivotRow);
			Fraction highestValue = pivotCol[pivotRow];
			int highestIndex{ pivotRow };
		
			for (unsigned int i = pivotRow; i < pivotCol.size(); i++)
				if (pivotCol[i].abs() > highestValue)
				{
					highestValue = pivotCol[i];
					highestIndex = i;
				}
			// swap pivot row with high row
			if (highestIndex != pivotRow)
			{
				A.swapRow(pivotRow, highestIndex);
				pivotCol = A.getCol(pivotRow);
				multiplier *= -1;
			}
		
			// Create multiplication Matrix Z
			for (unsigned int i = pivotRow + 1; i < pivotCol.size(); i++)
			{				
				if (pivotCol[i].getNumerator() != 0)
				{
					Fraction temp = A.getValue(i, pivotRow) / A.getValue(pivotRow, pivotRow) * -1;
					Z.setValue(i, pivotRow, temp);
				}				
			}
		
			A = Z * A;
		}
		//multiply diagonal, divide by multiplier
		Fraction determinant = Fraction(1,1);
		for (int i = 0; i < rowSize; i++)
			determinant *= A.getValue(i, i);		
		
		return determinant.to_int()/multiplier;
	}
	else
	{
		throw std::invalid_argument("Matrix must be nxn!");
	}
}



