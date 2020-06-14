#include "CppUnitTest.h"
#include "../Matrix/Matrix.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{	
		TEST_METHOD(SimpleTests)
		{
			Matrix<int> m1 = Matrix<int>::Matrix(3, 3);
			Matrix<int> m2 = Matrix<int>::Matrix(4, 4);
			Matrix<int> m3 = Matrix<int>::Matrix(5, 5);
			Matrix<int> m4 = Matrix<int>::Matrix(3, 3);
			Matrix<int> m5 = Matrix<int>::Matrix(2, 3);
			Matrix<int> m6 = Matrix<int>::Matrix(3, 2);
			Matrix<int> res = Matrix<int>::Matrix(3, 3);

			

			m1.setValue(0, 0, 0); m1.setValue(0, 1, 2); m1.setValue(0, 2, -3);
			m1.setValue(1, 0, 1); m1.setValue(1, 1, 2);	m1.setValue(1, 2, 3); 
			m1.setValue(2, 0, 3); m1.setValue(2, 1, 2); m1.setValue(2, 2, 1);

			m2.setValue(0, 0, 1); m2.setValue(0, 1, -2); m2.setValue(0, 2, -3); m2.setValue(0, 3, 4);
			m2.setValue(1, 0, 6); m2.setValue(1, 1, 2); m2.setValue(1, 2, -3); m2.setValue(1, 3, 6);
			m2.setValue(2, 0, 5); m2.setValue(2, 1, 4); m2.setValue(2, 2, 2); m2.setValue(2, 3, 1);
			m2.setValue(3, 0, 9); m2.setValue(3, 1, -7); m2.setValue(3, 2, 8); m2.setValue(3, 3, 0);

			m3.setValue(0, 0, 0); m3.setValue(0, 1, 4); m3.setValue(0, 2, -3); m3.setValue(0, 3, 4); m3.setValue(0, 4, 9);
			m3.setValue(1, 0, 8); m3.setValue(1, 1, 1); m3.setValue(1, 2, 2); m3.setValue(1, 3, 5); m3.setValue(1, 4, 1);
			m3.setValue(2, 0, 4); m3.setValue(2, 1, -1); m3.setValue(2, 2, 0); m3.setValue(2, 3, 3); m3.setValue(2, 4, -5);
			m3.setValue(3, 0, 2); m3.setValue(3, 1, 4); m3.setValue(3, 2, -7); m3.setValue(3, 3, 6); m3.setValue(3, 4, -1);
			m3.setValue(4, 0, 3); m3.setValue(4, 1, 4); m3.setValue(4, 2, 1); m3.setValue(4, 3, 0); m3.setValue(4, 4, 3);

			m4.setValue(0, 0, 7); m4.setValue(0, 1, -6); m4.setValue(0, 2, 1);
			m4.setValue(1, 0, -8); m4.setValue(1, 1, 5); m4.setValue(1, 2, -2);
			m4.setValue(2, 0, 9); m4.setValue(2, 1, -4); m4.setValue(2, 2, 3);
						
			m5.setValue(0, 0, 0); m5.setValue(0, 1, 1); m5.setValue(0, 2, -1);
			m5.setValue(1, 0, 3); m5.setValue(1, 1, 4);	m5.setValue(1, 2, 2);

			m6.setValue(0, 0, 2); m6.setValue(0, 1, 3); 
			m6.setValue(1, 0, 4); m6.setValue(1, 1, 9);	
			m6.setValue(2, 0, 6); m6.setValue(2, 1, 7); 
						
			res.setValue(0, 0, 1); res.setValue(0, 1, 1); res.setValue(0, 2, 1);
			res.setValue(1, 0, 1); res.setValue(1, 1, 1); res.setValue(1, 2, 1);
			res.setValue(2, 0, 1); res.setValue(2, 1, 1); res.setValue(2, 2, 1);
			
			/*void swapRow(int rowID1, int rowID2);
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
			Matrix operator*(const Matrix<int> &m);
			int determinant();*/

			res.resize(4, 4);
			res.setValue(0, 0, 1); res.setValue(0, 1, -2); res.setValue(0, 2, -3); res.setValue(0, 3, 4);
			res.setValue(2, 0, 6); res.setValue(2, 1, 2);  res.setValue(2, 2, -3); res.setValue(2, 3, 6);
			res.setValue(1, 0, 5); res.setValue(1, 1, 4);  res.setValue(1, 2, 2);  res.setValue(1, 3, 1);
			res.setValue(3, 0, 9); res.setValue(3, 1, -7); res.setValue(3, 2, 8);  res.setValue(3, 3, 0);

			m2.swapRow(1, 2);
			Assert::IsTrue(m2 == res);

			res.setValue(0, 0, 1); res.setValue(0, 1, -2); res.setValue(0, 3, -3); res.setValue(0, 2, 4);
			res.setValue(2, 0, 6); res.setValue(2, 1, 2);  res.setValue(2, 3, -3); res.setValue(2, 2, 6);
			res.setValue(1, 0, 5); res.setValue(1, 1, 4);  res.setValue(1, 3, 2);  res.setValue(1, 2, 1);
			res.setValue(3, 0, 9); res.setValue(3, 1, -7); res.setValue(3, 3, 8);  res.setValue(3, 2, 0);

			m2.swapCol(2, 3);
			Assert::IsTrue(m2 == res);

			Matrix<int> m1Copy = Matrix<int>::copy(m1);
			Assert::IsTrue(m1Copy == m1);

			std::vector<int> v1{ 6,2,-3,6 };  
			std::vector<int> v2{ -3,-3,2,8 };
			//Assert::IsTrue(v1 == m2.getRow(2));
			//Assert::IsTrue(v2 == m2.getCol(3));
			Assert::IsTrue(m1.isDimensionEqual(m4));

			res.setValue(0, 0, 1);  res.setValue(0, 1, -2); res.setValue(0, 2, -3); res.setValue(0, 3, 4);
			res.setValue(1, 0, -2); res.setValue(1, 1, -3); res.setValue(1, 2, 1); res.setValue(1, 3, 2);
			res.setValue(2, 0, -3); res.setValue(2, 1, 1);  res.setValue(2, 2, 6); res.setValue(2, 3, -3);
			res.setValue(3, 0, 4);  res.setValue(3, 1, 2);  res.setValue(3, 2, -3); res.setValue(3, 3, 6);
			Assert::IsTrue(res.isSymmetric());
			Assert::IsTrue(res.rowSum() == std::vector<int>{0, -2, 1, 9});
			Assert::IsTrue(res.colSum() == std::vector<int>{0, -2, 1, 9});
			Assert::IsTrue(Matrix<int>::multiplyVector(v1, v2) == 18);
			try
			{
				m5 + m6;
				Assert::Fail();
			}
			catch (exception x) {}

			try
			{
				m5 - m6;
				Assert::Fail();
			}
			catch (exception x) {}

			try
			{
				m1 * m2;
				Assert::Fail();
			}
			catch (exception x) {}

			try
			{
				m3 * v1;
				Assert::Fail();
			}
			catch (exception x) {}

			res.resize(3, 3);
			res.setValue(0, 0, 7); res.setValue(0, 1, -4);  res.setValue(0, 2, -2); 
			res.setValue(1, 0, -7); res.setValue(1, 1, 7); res.setValue(1, 2, 1);
			res.setValue(2, 0, 12); res.setValue(2, 1, -2);  res.setValue(2, 2, 4);
			Assert::IsTrue(res == (m1 + m4));

			res.setValue(0, 0, -7); res.setValue(0, 1, 8);  res.setValue(0, 2, -4);
			res.setValue(1, 0, 9);  res.setValue(1, 1, -3); res.setValue(1, 2, 5);
			res.setValue(2, 0, -6); res.setValue(2, 1, 6);  res.setValue(2, 2, -2);
			Assert::IsTrue(res == (m1 - m4));

			res.resize(2, 2);
			res.setValue(0, 0, -2); res.setValue(0, 1, 2);
			res.setValue(1, 0, 34);  res.setValue(1, 1, 59);
			Assert::IsTrue(res == (m5 * m6));

			Matrix<Fraction> x = Matrix<Fraction>(1, 1);
			
			Assert::IsTrue(x.getValue(0,0).getNumerator() == 11);

			/*Assert::IsTrue(28 == m1.determinant());
			Assert::IsTrue(-287 == m2.determinant());
			Assert::IsTrue(1052 == m3.determinant());*/

			
		}
	};
}																					
