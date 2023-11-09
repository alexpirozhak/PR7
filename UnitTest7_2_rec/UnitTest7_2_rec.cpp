#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_2_rec/PR7_2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** t = new int* [9];
			t[0] = new int[9] { 6, 3, 0, -7, 8, 6, 10, -7, 1 };
			t[1] = new int[9] { -4, 10, 10, 6, 7, 8, -7, 10, -3 };
			t[2] = new int[9] { 4, 1, -4, 8, 6, -3, -7, -1, 9 };
			t[3] = new int[9] { 10, 10, -1, -9, -9, 8, -2, 2, -1 };
			t[4] = new int[9] { -3, 1, -7, -3, 10, -10, 10, 8, -5 };
			t[5] = new int[9] { 3, 10, -8, -10, -8, -8, 4, 8, -1 };
			t[6] = new int[9] { -9, 9, -2, 9, 0, 8, -6, 7, 9 };
			t[7] = new int[9] { 9, -4, 6, 1, -7, 3, 5, -2, 2 };
			t[8] = new int[9] { 4, 7, 4, 6, 7, -9, -5, -1, -1 };

			int imax = 0;
			Change(t, 9, 9, 0, 0, imax);

			int** res = new int* [9];
			res[0] = new int[9] { 10, 3, 0, -7, 8, 6, 6, -7, 1 };
			res[1] = new int[9] { -4, 10, 10, 6, 7, 8, -7, 10, -3 };
			res[2] = new int[9] { 4, 1, 9, 8, 6, -3, -7, -1, -4 };
			res[3] = new int[9] { 10, 10, -1, -9, -9, 8, -2, 2, -1 };
			res[4] = new int[9] { -3, 1, -7, -3, 10, -10, 10, 8, -5 };
			res[5] = new int[9] { 3, 10, -8, -10, -8, -8, 4, 8, -1 };
			res[6] = new int[9] { -9, -6, -2, 9, 0, 8, 9, 7, 9 };
			res[7] = new int[9] { 9, -4, 6, 1, -7, 3, 5, -2, 2 };
			res[8] = new int[9] { 4, -1, 4, 6, 7, -9, -5, -1, 7 };

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
