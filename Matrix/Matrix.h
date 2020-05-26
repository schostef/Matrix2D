#pragma once
#include <vector>
#include <map>
namespace Matrix
{
	template <class T>
	struct mRow
	{
		std::map<int, T> cols;
	};	

	template <class T>
	class Matrix
	{
	private:
		int rowSize;
		int colSize;
	protected:		
		std::map<int,mRow<T>> rows;
	public:
		Matrix()
		{
			rowSize = 0;
			colSize = 0;
		}

		Matrix(int rows, int cols)
		{			
			rowSize = rows;
			colSize = cols;
			for (int i = 0; i < rowSize; i++)
			{
				mRow<T> r;
								
				for (int j = 0; j < colSize; j++)
					r.cols.insert(std::make_pair(j, T{}));
				this->rows.insert(std::make_pair(i, r));				
			}
		}

		//locked generics
		bool isTautologic() { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		bool isContradictive() { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		Matrix and(Matrix m) { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		Matrix or(Matrix m) { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		Matrix not() { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		Matrix implies(Matrix m) { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		Matrix equivalent(Matrix m) { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }
		Matrix antivalent(Matrix m) { static_assert(sizeof(T) == 0, "Only boolean specializations allowed"); }		

		void setValue(int row, int col, T value)
		{
			rows.at(row).cols.at(col) = value;
		}

		T getValue(int row, int col)
		{
			return rows.at(row).cols.at(col);
		}

		Matrix getRow(int rowID)
		{
			Matrix m = Matrix(1, colSize);
			for (int i = 0; i < colSize; i++)
				m.setValue(0, i, getValue(rowID, i));
			return m;
		}

		Matrix getCol(int colID)
		{
			Matrix m = Matrix(rowSize, 1);
			for (int i = 0; i < rowSize; i++)
				m.setValue(i,0, getValue(i, colID));
			return m;
		}

		void resize(int rowSize, int colSize)
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
					mRow<T> r;
					
					for (int j = 0; j < this->colSize; j++)
						r.cols.insert(std::make_pair(j, T{}));
					rows.insert(std::make_pair(i, r));
				}
			}
			this->rowSize = rowSize;

			if (colSize < this->colSize)
			{	for (int i = 0; i < rowSize; i ++)
					for (int j = colSize; j < this->colSize; j++)
						rows.at(i).cols.erase(j);
				
			}
			else if (colSize > this->colSize)
			{
				for (int i = 0; i < this->rowSize; i++)
					for (int j = this->colSize; j < colSize; j++)
						rows.at(i).cols.insert(std::make_pair(j, T{}));				
			}			
			this->colSize = colSize;
		}

		bool isDimensionEqual(Matrix m)
		{
			return (m.rowSize == rowSize && m.colSize == colSize);
		}

		bool isEqual(Matrix m)
		{
			if (!isDimensionEqual(m))
				return false;

			for (int i = 0; i < rowSize; i++)
			{
				for (int j = 0; j < colSize; j++)
				{
					if (m.rows.at(i).cols.at(j) != rows.at(i).cols.at(j))
						return false;
				}
			}

			return true;
		}		

		bool isSymmetric()
		{
			return isEqual(this->transpose());
		}

		Matrix rowSum()
		{
			Matrix sumVector = Matrix(rowSize, 1);

			for (int i = 0; i < rowSize; i++)
			{
				T sum{};
				for (int j = 0; j < colSize; j++)
					sum += getValue(i, j);
				sumVector.setValue(i, 0, sum);
			}

			return sumVector;
		}

		Matrix colSum()
		{
			Matrix sumVector = Matrix(1, colSize);

			for (int i = 0; i < colSize; i++)
			{
				T sum{};
				for (int j = 0; j < rowSize; j++)
					sum += getValue(j, i);
				sumVector.setValue(0, i, sum);
			}

			return sumVector;
		}

		//Basic Calculations
		Matrix add(Matrix m)
		{
			if (!isDimensionEqual(m))
				throw std::invalid_argument("Matrizes must be of equal Type!");

			Matrix res = Matrix(rowSize, colSize);

			for (int i = 0; i < rowSize; i++)
				for (int j = 0; j < colSize; j++)
					res.setValue(i, j, getValue(i, j) + m.getValue(i, j));
				
			return res;
		}		

		Matrix subtract(Matrix m)
		{
			if (!isDimensionEqual(m))
				throw std::invalid_argument("Matrizes must be of equal Type!");

			Matrix res = Matrix(rowSize, colSize);

			for (int i = 0; i < rowSize; i++)
				for (int j = 0; j < colSize; j++)
					res.setValue(i, j, getValue(i, j) - m.getValue(i, j));

			return res;
		}

		Matrix multiplySkalar(T r)
		{
			Matrix res = Matrix(rowSize, colSize);

			for (int i = 0; i < rowSize; i++)
				for (int j = 0; j < colSize; j++)
					res.setValue(i, j, getValue(i, j) * r);

			return res;
		}

		Matrix multiplyVector(Matrix v)
		{
			if (colSize != v.rowSize)
				throw std::invalid_argument("Vector component-size must match the Matrix's column-size!");
			if (v.colSize > 1)
				throw std::invalid_argument("Parameter is not a Vector!");

			Matrix res = Matrix(rowSize, 1);

			for (int i = 0; i < rowSize; i++)
			{
				T sum{};
				for (int j = 0; j < colSize; j++)
					sum += getValue(i, j)*v.getValue(j, 0);
				res.setValue(i, 0, sum);
			}

			return res;				
		}

		Matrix multiplyMatrix(Matrix m)
		{
			if (colSize != m.rowSize)
				throw std::invalid_argument("Matrix A's columsize is not equal to Matrix B's rowsize!");

			Matrix res = Matrix(rowSize, m.colSize);

			for (int i = 0; i < rowSize; i++)
				for (int j = 0; j < m.colSize; j++)
					res.setValue(i, j, getRow(i).multiplyVector(m.getCol(j)).getValue(0,0));				

			return res;
		}	

		Matrix transpose()
		{
			Matrix m = Matrix(rowSize, colSize);
			for(int i = 0; i < rowSize; i++)
				for (int j = 0; j < colSize; j++)
					if (i != j)
						m.setValue(i, j, getValue(j, i));

			return m;
		}
	};

	bool Matrix<double>:: isEqual(Matrix<double> m)
	{
		if (!isDimensionEqual(m))
			return false;

		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < colSize; j++)
			{
				std::string a = std::to_string(m.getValue(i,j));
				std::string b = std::to_string(getValue(i,j));
				if (a.compare(b) != 0)
					return false;
			}
		}

		return true;
	}

	bool Matrix<float>:: isEqual(Matrix<float> m)
	{
		if (!isDimensionEqual(m))
			return false;

		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < colSize; j++)
			{
				std::string a = std::to_string(m.getValue(i, j));
				std::string b = std::to_string(getValue(i, j));
				if (a.compare(b) != 0)
					return false;
			}
		}

		return true;
	}

	template<>
	bool Matrix<bool>:: isTautologic()
	{
		bool isTautologic{ true };
		for (int i = 0; i < rowSize && isTautologic; i++)
			for (int j = 0; j < colSize && isTautologic; j++)
				isTautologic = getValue(i, j);
		return isTautologic;
	}

	template<>
	bool Matrix<bool>:: isContradictive()
	{
		bool isContradictive{ true };
		for (int i = 0; i < rowSize && isContradictive; i++)
			for (int j = 0; j < colSize && isContradictive; j++)
				isContradictive = !getValue(i, j);
		return isContradictive;
	}

	//Boolean Operations
	template<>
	Matrix<bool> Matrix<bool>:: not ()
	{
		Matrix<bool> res = Matrix<bool>(rowSize, colSize);

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				res.setValue(i, j, !getValue(i, j));

		return res;
	}

	template<>
	Matrix<bool> Matrix<bool>:: and (Matrix m)
	{
		if (!isDimensionEqual(m))
			throw std::invalid_argument("Matrizes must be of equal Type!");
		Matrix<bool> res = Matrix<bool>(rowSize, colSize);

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				res.setValue(i, j, (getValue(i, j) && m.getValue(i, j)));

		return res;
	}		

	template<>
	Matrix<bool> Matrix<bool>:: or (Matrix m)
	{
		if (!isDimensionEqual(m))
			throw std::invalid_argument("Matrizes must be of equal Type!");
		Matrix<bool> res = Matrix<bool>(rowSize, colSize);

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				res.setValue(i, j, (getValue(i, j) || m.getValue(i, j)));

		return res;
	}	

	template<>
	Matrix<bool> Matrix<bool>:: implies (Matrix m)
	{
		if (!isDimensionEqual(m))
			throw std::invalid_argument("Matrizes must be of equal Type!");
		Matrix<bool> res = Matrix<bool>(rowSize, colSize);

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				res.setValue(i, j, (!getValue(i, j) || m.getValue(i, j)));

		return res;
	}

	template<>
	Matrix<bool> Matrix<bool>:: equivalent (Matrix m)
	{
		if (!isDimensionEqual(m))
			throw std::invalid_argument("Matrizes must be of equal Type!");
		Matrix<bool> res = Matrix<bool>(rowSize, colSize);

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				res.setValue(i, j, ( getValue(i,j) && m.getValue(i,j) ) || ( !getValue(i,j) && !m.getValue(i,j) ) );

		return res;
	}

	template<>
	Matrix<bool> Matrix<bool>:: antivalent (Matrix m)
	{
		if (!isDimensionEqual(m))
			throw std::invalid_argument("Matrizes must be of equal Type!");
		Matrix<bool> res = Matrix<bool>(rowSize, colSize);

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				res.setValue(i, j, (!getValue(i, j) && m.getValue(i, j)) || (getValue(i, j) && !m.getValue(i, j)));

		return res;
	}
}
