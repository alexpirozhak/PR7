#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_2_it/PR7_2_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** t = new int*[9];
			t[0] = new int[9] { -2, -5, -10, -9, 4, 1, 9, -9, 0 };
			t[1] = new int[9] { -6, 9, -2, 1, -4, 10, 7, -10, 10 };
			t[2] = new int[9] { 0, -6, -7, 1, -5, 8, -6, 10, 10 };
			t[3] = new int[9] { -8, -4, 4, 6, 6, 1, -7, -2, -6 };
			t[4] = new int[9] { 10, 2, -1, -9, -7, -4, -5, -10, 8 };
			t[5] = new int[9] { 2, -6, -6, 0, -9, 10, -9, -2, 8 };
			t[6] = new int[9] { 5, 0, 7, -2, 4, -2, -2, 2, 9 };
			t[7] = new int[9] { -4, 2, -2, -3, 3, -7, 0, 4, -9 };
			t[8] = new int[9] { 4, -3, -2, -3, -2, -5, -9, 6, 0 };

			Change(t, 9, 9);

			int** res = new int* [9];
			res[0] = new int[9] { 9, -5, -10, -9, 4, 1, -2, -9, 0 };
			res[1] = new int[9] { -6, 9, -2, 1, -4, 10, 7, -10, 10 };
			res[2] = new int[9] { 0, -6, 10, 1, -5, 8, -6, -7, 10 };
			res[3] = new int[9] { -8, -4, 4, 6, 6, 1, -7, -2, -6 };
			res[4] = new int[9] { -7, 2, -1, -9, 10, -4, -5, -10, 8 };
			res[5] = new int[9] { 2, -6, -6, 0, -9, 10, -9, -2, 8 };
			res[6] = new int[9] { 5, 0, 7, -2, 4, -2, 9, 2, -2 };
			res[7] = new int[9] { -4, 2, -2, -3, 3, -7, 0, 4, -9 };
			res[8] = new int[9] { 4, -3, -2, -3, -2, -5, -9, 0, 6 };

			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(t[i][j], res[i][j]);

			for (int i = 0; i < 9; i++)
			{
				delete[] t[i];
				delete[] res[i];
			}
			delete[] t;
			delete[] res;
		}
	};
}
