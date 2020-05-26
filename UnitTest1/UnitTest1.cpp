#include "pch.h"
#include "CppUnitTest.h"
#include "../Matrix/Matrix.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TryIntType)
		{
			Matrix::Matrix<int> m = Matrix::Matrix<int>(5, 5);
			m.setValue(1, 1, 5);
			Assert::AreEqual(5, m.getValue(1, 1));
		};

		TEST_METHOD(TryDoubleType)
		{
			Matrix::Matrix<double> m = Matrix::Matrix<double>(5, 5);
			m.setValue(1, 1, 5.5);
			Assert::AreEqual(5.5, m.getValue(1, 1));
		}

		TEST_METHOD(TryBoolType)
		{
			Matrix::Matrix<bool> m = Matrix::Matrix<bool>(5, 5);
			m.setValue(1, 1, true);
			Assert::AreEqual(true, m.getValue(1, 1));
		}

		TEST_METHOD(CompareMatrix1)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(5, 5);
			Matrix::Matrix<int> m2 = Matrix::Matrix<int>(5, 5);
			m1.setValue(0, 0, 10);
			m1.setValue(1, 2, 20);
			m1.setValue(2, 4, 30);
			m1.setValue(4, 0, 40);
			m1.setValue(0, 4, 50);
			m1.setValue(3, 3, 60);
			m1.setValue(4, 4, 70);
			m1.setValue(1, 4, 80);
			m1.setValue(4, 2, 90);
			m1.setValue(2, 0, 100);
			m1.setValue(3, 1, 110);

			m2.setValue(0, 0, 10);
			m2.setValue(1, 2, 20);
			m2.setValue(2, 4, 30);
			m2.setValue(4, 0, 40);
			m2.setValue(0, 4, 50);
			m2.setValue(3, 3, 60);
			m2.setValue(4, 4, 70);
			m2.setValue(1, 4, 80);
			m2.setValue(4, 2, 90);
			m2.setValue(2, 0, 100);
			m2.setValue(3, 1, 110);
			Assert::IsTrue(m1.isEqual(m2));
		}

		TEST_METHOD(CompareMatrix2)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(5, 5);
			Matrix::Matrix<int> m2 = Matrix::Matrix<int>(3, 10);
			m1.setValue(0, 0, 10);
			m1.setValue(1, 2, 20);
			m1.setValue(2, 4, 30);
			m1.setValue(4, 0, 40);
			m1.setValue(0, 4, 50);
			m1.setValue(3, 3, 60);
			m1.setValue(4, 4, 70);
			m1.setValue(1, 4, 80);
			m1.setValue(4, 2, 90);
			m1.setValue(2, 0, 100);
			m1.setValue(3, 1, 110);					
			Assert::IsFalse(m1.isEqual(m2));
		}

		TEST_METHOD(CompareMatrix3)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(5, 5);
			Matrix::Matrix<int> m2 = Matrix::Matrix<int>(5, 5);
			m1.setValue(0, 0, 10);
			m1.setValue(1, 2, 20);
			m1.setValue(2, 4, 30);
			m1.setValue(4, 0, 40);
			m1.setValue(0, 4, 50);
			m1.setValue(3, 3, 33);
			m1.setValue(4, 4, 70);
			m1.setValue(1, 4, 80);
			m1.setValue(4, 2, 90);
			m1.setValue(2, 0, 100);
			m1.setValue(3, 1, 110);

			m2.setValue(0, 0, 10);
			m2.setValue(1, 2, 20);
			m2.setValue(2, 4, 30);
			m2.setValue(4, 0, 40);
			m2.setValue(0, 4, 50);
			m2.setValue(3, 3, 60);
			m2.setValue(4, 4, 70);
			m2.setValue(1, 4, 80);
			m2.setValue(4, 2, 90);
			m2.setValue(2, 0, 100);
			m2.setValue(3, 1, 110);
			Assert::IsFalse(m1.isEqual(m2));
		}

		TEST_METHOD(tRowSum)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(5, 5);
			m1.setValue(0, 0, 12);
			m1.setValue(0, 1, 4);
			m1.setValue(0, 2, 2);
			m1.setValue(0, 3, 6);
			m1.setValue(0, 4, 55);
			m1.setValue(1, 0, 35);
			m1.setValue(1, 1, 77);
			m1.setValue(1, 2, 64);
			m1.setValue(1, 3, 21);
			m1.setValue(1, 4, 11);
			m1.setValue(2, 0, 51);
			m1.setValue(2, 1, 68);
			m1.setValue(2, 2, 47);
			m1.setValue(2, 3, 97);
			m1.setValue(2, 4, 14);
			m1.setValue(3, 0, 56);
			m1.setValue(3, 1, 41);
			m1.setValue(3, 2, 48);
			m1.setValue(3, 3, 12);
			m1.setValue(3, 4, 24);
			m1.setValue(4, 0, 35);
			m1.setValue(4, 1, 41);
			m1.setValue(4, 2, 65);
			m1.setValue(4, 3, 47);
			m1.setValue(4, 4, 39);

			Matrix::Matrix<int> res = Matrix::Matrix<int>(5, 1);
			res.setValue(0, 0, 79);
			res.setValue(1, 0, 208);
			res.setValue(2, 0, 277);
			res.setValue(3, 0, 181);
			res.setValue(4, 0, 227);

			Assert::IsTrue(res.isEqual(m1.rowSum()));
		}

		TEST_METHOD(colSum)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(5, 5);
			m1.setValue(0, 0, 12);
			m1.setValue(0, 1, 4);
			m1.setValue(0, 2, 2);
			m1.setValue(0, 3, 6);
			m1.setValue(0, 4, 55);
			m1.setValue(1, 0, 35);
			m1.setValue(1, 1, 77);
			m1.setValue(1, 2, 64);
			m1.setValue(1, 3, 21);
			m1.setValue(1, 4, 11);
			m1.setValue(2, 0, 51);
			m1.setValue(2, 1, 68);
			m1.setValue(2, 2, 47);
			m1.setValue(2, 3, 97);
			m1.setValue(2, 4, 14);
			m1.setValue(3, 0, 56);
			m1.setValue(3, 1, 41);
			m1.setValue(3, 2, 48);
			m1.setValue(3, 3, 12);
			m1.setValue(3, 4, 24);
			m1.setValue(4, 0, 35);
			m1.setValue(4, 1, 41);
			m1.setValue(4, 2, 65);
			m1.setValue(4, 3, 47);
			m1.setValue(4, 4, 39);

			Matrix::Matrix<int> res = Matrix::Matrix<int>(1, 5);
			res.setValue(0, 0, 189);
			res.setValue(0, 1, 231);
			res.setValue(0, 2, 226);
			res.setValue(0, 3, 183);
			res.setValue(0, 4, 143);

			Assert::IsTrue(res.isEqual(m1.colSum()));
		}

		TEST_METHOD(addExpectException)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m2 = Matrix::Matrix<double>(4, 5);
			
			try 
			{
				m1.add(m2);
				Assert::Fail();
			}
			catch (std::invalid_argument) {}
		}

		TEST_METHOD(subtractExpectException)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m2 = Matrix::Matrix<double>(4, 5);

			try
			{
				m1.subtract(m2);
				Assert::Fail();
			}
			catch (std::invalid_argument) {}
		}

		TEST_METHOD(multiplyVectorExpectException)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m2 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m3 = Matrix::Matrix<double>(4, 1);
			Matrix::Matrix<double> m4 = Matrix::Matrix<double>(2, 1);

			try
			{
				m1.multiplyVector(m2);				
				Assert::Fail();
			}
			catch (std::invalid_argument) {}

			try
			{
				m1.multiplyVector(m3);
				Assert::Fail();
			}
			catch (std::invalid_argument) {}

			try
			{
				m1.multiplyVector(m4);
				Assert::Fail();
			}
			catch (std::invalid_argument) {}
		}

		TEST_METHOD(add)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m2 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> expectedResult = Matrix::Matrix<double>(3, 3);

			m1.setValue(0, 0, -1.5);
			m1.setValue(0, 1, 6.0);
			m1.setValue(0, 2, 0.0);
			m1.setValue(1, 0, 5.3);
			m1.setValue(1, 1, -5.7);
			m1.setValue(1, 2, 4.4);
			m1.setValue(2, 0, 17.8);
			m1.setValue(2, 1, 3.3);
			m1.setValue(2, 2, 7.8);

			m2.setValue(0, 0, 14.9);
			m2.setValue(0, 1, 9.4);
			m2.setValue(0, 2, -3.1);
			m2.setValue(1, 0, 4.9);
			m2.setValue(1, 1, 5.0);
			m2.setValue(1, 2, 2.4);
			m2.setValue(2, 0, -5.1);
			m2.setValue(2, 1, 2.1);
			m2.setValue(2, 2, 8.4);

			expectedResult.setValue(0, 0, 13.4);
			expectedResult.setValue(0, 1, 15.4);
			expectedResult.setValue(0, 2, -3.1);
			expectedResult.setValue(1, 0, 10.2);
			expectedResult.setValue(1, 1, -0.7);
			expectedResult.setValue(1, 2, 6.8);
			expectedResult.setValue(2, 0, 12.7);
			expectedResult.setValue(2, 1, 5.4);
			expectedResult.setValue(2, 2, 16.2);
			

			try
			{
				Assert::IsTrue(expectedResult.isEqual(m1.add(m2)));
				
			}
			catch (std::invalid_argument) { Assert::Fail(); }
		}

		TEST_METHOD(subtract)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m2 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> expectedResult = Matrix::Matrix<double>(3, 3);

			m1.setValue(0, 0, -1.5);
			m1.setValue(0, 1, 6.0);
			m1.setValue(0, 2, 0.0);
			m1.setValue(1, 0, 5.3);
			m1.setValue(1, 1, -5.7);
			m1.setValue(1, 2, 4.4);
			m1.setValue(2, 0, 17.8);
			m1.setValue(2, 1, 3.3);
			m1.setValue(2, 2, 7.8);

			m2.setValue(0, 0, 14.9);
			m2.setValue(0, 1, 9.4);
			m2.setValue(0, 2, -3.1);
			m2.setValue(1, 0, 4.9);
			m2.setValue(1, 1, 5.0);
			m2.setValue(1, 2, 2.4);
			m2.setValue(2, 0, -5.1);
			m2.setValue(2, 1, 2.1);
			m2.setValue(2, 2, 8.4);

			expectedResult.setValue(0, 0, -16.4);
			expectedResult.setValue(0, 1, -3.4);
			expectedResult.setValue(0, 2, 3.1);
			expectedResult.setValue(1, 0, 0.4);
			expectedResult.setValue(1, 1, -10.7);
			expectedResult.setValue(1, 2, 2.0);
			expectedResult.setValue(2, 0, 22.9);
			expectedResult.setValue(2, 1, 1.2);
			expectedResult.setValue(2, 2, -0.6);


			try
			{
				Assert::IsTrue(expectedResult.isEqual(m1.subtract(m2)));

			}
			catch (std::invalid_argument) { Assert::Fail(); }
		}

		TEST_METHOD(multiplySkalar)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			float pi = 3.14159f;
			Matrix::Matrix<double> expectedResult = Matrix::Matrix<double>(3, 3);

			m1.setValue(0, 0, -1.5);
			m1.setValue(0, 1, 6.0);
			m1.setValue(0, 2, 0.0);
			m1.setValue(1, 0, 5.3);
			m1.setValue(1, 1, -5.7);
			m1.setValue(1, 2, 4.4);
			m1.setValue(2, 0, 17.8);
			m1.setValue(2, 1, 3.3);
			m1.setValue(2, 2, 7.8);
			
			expectedResult.setValue(0, 0, (-1.5*2.0*pi));
			expectedResult.setValue(0, 1, (6.0*2.0*pi));
			expectedResult.setValue(0, 2, (0.0*2.0*pi));
			expectedResult.setValue(1, 0, (5.3*2.0*pi));
			expectedResult.setValue(1, 1, (-5.7*2.0*pi));
			expectedResult.setValue(1, 2, (4.4*2.0*pi));
			expectedResult.setValue(2, 0, (17.8*2.0*pi));
			expectedResult.setValue(2, 1, (3.3*2.0*pi));
			expectedResult.setValue(2, 2, (7.8*2.0*pi));


			try
			{
				Assert::IsTrue(expectedResult.isEqual(m1.multiplySkalar(2.0).multiplySkalar(3.14159f)));

			}
			catch (std::invalid_argument) { Assert::Fail(); }
		}

		TEST_METHOD(multiplyVector)
		{
			Matrix::Matrix<double> m1 = Matrix::Matrix<double>(3, 3);
			Matrix::Matrix<double> m2 = Matrix::Matrix<double>(3, 1);
			Matrix::Matrix<double> expectedResult = Matrix::Matrix<double>(3, 1);

			m1.setValue(0, 0, -1.5);
			m1.setValue(0, 1, 6.0);
			m1.setValue(0, 2, 0.0);
			m1.setValue(1, 0, 5.3);
			m1.setValue(1, 1, -5.7);
			m1.setValue(1, 2, 4.4);
			m1.setValue(2, 0, 17.8);
			m1.setValue(2, 1, 3.3);
			m1.setValue(2, 2, 7.8);

			m2.setValue(0, 0, 14.9);			
			m2.setValue(1, 0, 4.9);			
			m2.setValue(2, 0, -5.1);
			

			expectedResult.setValue(0, 0, (-1.5*14.9+6.0*4.9+0.0*-5.1));			
			expectedResult.setValue(1, 0, (5.3*14.9-5.7*4.9+4.4*-5.1));			
			expectedResult.setValue(2, 0, (17.8*14.9+3.3*4.9+7.8*-5.1));
			


			try
			{
				Assert::IsTrue(expectedResult.isEqual(m1.multiplyVector(m2)));

			}
			catch (std::invalid_argument) { Assert::Fail(); }
		}

		TEST_METHOD(multiplyMatrix)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(2, 3);
			Matrix::Matrix<int> m2 = Matrix::Matrix<int>(3, 2);
			Matrix::Matrix<int> expectedResult = Matrix::Matrix<int>(2, 2);

			m1.setValue(0, 0, 3);
			m1.setValue(0, 1, 2);
			m1.setValue(0, 2, 1);
			m1.setValue(1, 0, 1);
			m1.setValue(1, 1, 0);			
			m1.setValue(1, 2, 2);
			

			m2.setValue(0, 0, 1);
			m2.setValue(0, 1, 2);
			m2.setValue(1, 0, 0);
			m2.setValue(1, 1, 1);			
			m2.setValue(2, 0, 4);
			m2.setValue(2, 1, 0);


			expectedResult.setValue(0, 0, 7);
			expectedResult.setValue(0, 1, 8);
			expectedResult.setValue(1, 0, 9);
			expectedResult.setValue(1, 1, 2);
			
			


			try
			{
				Assert::IsTrue(expectedResult.isEqual(m1.multiplyMatrix(m2)));

			}
			catch (std::invalid_argument) { Assert::Fail(); }
		}

		TEST_METHOD(resizing)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(2, 3);
			Matrix::Matrix<int> m2 = Matrix::Matrix<int>(2, 1);
			Matrix::Matrix<int> m3 = Matrix::Matrix<int>(4, 1);
			Matrix::Matrix<int> m4 = Matrix::Matrix<int>(4, 5);
			Matrix::Matrix<int> m5 = Matrix::Matrix<int>(2, 5);
			Matrix::Matrix<int> m6 = Matrix::Matrix<int>(3, 4);
			Matrix::Matrix<int> m7 = Matrix::Matrix<int>(2, 5);
			Matrix::Matrix<int> m8 = Matrix::Matrix<int>(2, 5);

			m1.resize(2, 1);
			Assert::IsTrue(m1.isEqual(m2));
			m1.resize(4, 1);
			Assert::IsTrue(m1.isEqual(m3));
			m1.resize(4, 5);
			Assert::IsTrue(m1.isEqual(m4));
			m1.resize(2, 5);
			Assert::IsTrue(m1.isEqual(m5));
			m1.resize(3, 4);
			Assert::IsTrue(m1.isEqual(m6));
			m1.resize(2, 5);
			Assert::IsTrue(m1.isEqual(m7));
			m1.resize(2, 5);
			Assert::IsTrue(m1.isEqual(m8));
		}

		TEST_METHOD(resizingWithValues)
		{
			Matrix::Matrix<int> m1 = Matrix::Matrix<int>(3, 3);
			Matrix::Matrix<int> m2 = Matrix::Matrix<int>(2, 2);
			Matrix::Matrix<int> m3 = Matrix::Matrix<int>(4, 4);
			
			m1.setValue(0, 0, 1);
			m1.setValue(0, 1, 2);
			m1.setValue(0, 2, 3);
			m1.setValue(1, 0, 1);
			m1.setValue(1, 1, 2);
			m1.setValue(1, 2, 3);
			m1.setValue(2, 0, 1);
			m1.setValue(2, 1, 2);
			m1.setValue(2, 2, 3);

			m2.setValue(0, 0, 1);
			m2.setValue(0, 1, 2);
			m2.setValue(1, 0, 1);
			m2.setValue(1, 1, 2);

			m3.setValue(0, 0, 1);
			m3.setValue(0, 1, 2);
			m3.setValue(0, 2, 0);
			m3.setValue(0, 3, 0);
			m3.setValue(1, 0, 1);
			m3.setValue(1, 1, 2);
			m3.setValue(1, 2, 0);
			m3.setValue(1, 3, 0);
			m3.setValue(2, 0, 0);
			m3.setValue(2, 1, 0);
			m3.setValue(2, 2, 0);
			m3.setValue(2, 3, 0);
			m3.setValue(3, 0, 0);
			m3.setValue(3, 1, 0);
			m3.setValue(3, 2, 0);
			m3.setValue(3, 3, 0);

			m1.resize(2, 2);
			Assert::IsTrue(m1.isEqual(m2));
			m1.resize(4, 4);
			Assert::IsTrue(m1.isEqual(m3));			
		}

		TEST_METHOD(tautologicContradictive)
		{
			Matrix::Matrix<bool> m1 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> m2 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> m3 = Matrix::Matrix<bool>(2, 2);

			m1.setValue(0, 0, true);
			m1.setValue(0, 1, false);
			m1.setValue(1, 0, false);
			m1.setValue(1, 1, true);

			m2.setValue(0, 0, true);
			m2.setValue(0, 1, true);
			m2.setValue(1, 0, true);
			m2.setValue(1, 1, true);

			m3.setValue(0, 0, false);
			m3.setValue(0, 1, false);
			m3.setValue(1, 0, false);
			m3.setValue(1, 1, false);

			Assert::IsFalse(m1.isContradictive());
			Assert::IsFalse(m2.isContradictive());
			Assert::IsFalse(m1.isTautologic());
			Assert::IsTrue(m2.isTautologic());
			Assert::IsTrue(m3.isContradictive());
		}

		TEST_METHOD(booleanAlgebra)
		{
			Matrix::Matrix<bool> m1 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> m2 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> m3 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> m4 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> m5 = Matrix::Matrix<bool>(2, 2);
			Matrix::Matrix<bool> res = Matrix::Matrix<bool>(2, 2);

			m1.setValue(0, 0, true);
			m1.setValue(0, 1, true);
			m1.setValue(1, 0, true);
			m1.setValue(1, 1, true);

			m2.setValue(0, 0, false);
			m2.setValue(0, 1, false);
			m2.setValue(1, 0, false);
			m2.setValue(1, 1, false);

			m3.setValue(0, 0, true);
			m3.setValue(0, 1, false);
			m3.setValue(1, 0, true);
			m3.setValue(1, 1, false);

			m4.setValue(0, 0, false);
			m4.setValue(0, 1, true);
			m4.setValue(1, 0, false);
			m4.setValue(1, 1, true);

			m5.setValue(0, 0, true);
			m5.setValue(0, 1, true);
			m5.setValue(1, 0, false);
			m5.setValue(1, 1, false);

			Assert::IsTrue(m3.isEqual(m4.not())); //NOT
			
			res.setValue(0, 0, true);
			res.setValue(0, 1, false);
			res.setValue(1, 0, true);
			res.setValue(1, 1, false);

			Assert::IsTrue(res.isEqual(m1. and (m3))); //AND
			
			res.setValue(0, 0, true);
			res.setValue(0, 1, false);
			res.setValue(1, 0, true);
			res.setValue(1, 1, false);

			Assert::IsTrue(res.isEqual(m2. or (m3))); //OR

			res.setValue(0, 0, true);
			res.setValue(0, 1, false);
			res.setValue(1, 0, true);
			res.setValue(1, 1, true);

			Assert::IsTrue(res.isEqual(m5. implies (m3))); //Imply

			res.setValue(0, 0, true);
			res.setValue(0, 1, false);
			res.setValue(1, 0, false);
			res.setValue(1, 1, true);

			Assert::IsTrue(res.isEqual(m5.equivalent(m3))); //Equivalent

			res.setValue(0, 0, false);
			res.setValue(0, 1, true);
			res.setValue(1, 0, true);
			res.setValue(1, 1, false);

			Assert::IsTrue(res.isEqual(m5.antivalent(m3))); //Antivalent
			
		}
	};
}
