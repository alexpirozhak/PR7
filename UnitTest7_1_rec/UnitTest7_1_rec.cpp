#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_1_rec/PR7_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11it
{
	TEST_CLASS(UnitTest11it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** t = new int* [8];

			t[0] = new int[7] { 17, -12, 15, -11, 8, -5, 16 };
			t[1] = new int[7] { -17, -10, 11, 13, -14, -16, -6 };
			t[2] = new int[7] { 13, 8, -16, -20, 13, 13, -17 };
			t[3] = new int[7] { -8, 18, -1, 8, 1, 7, -20 };
			t[4] = new int[7] { 7, -18, 9, -15, 2, 4, -15 };
			t[5] = new int[7] { 0, 15, 11, 2, -7, -2, 6 };
			t[6] = new int[7] { 13, -20, 8, 7, -7, 5, 8 };
			t[7] = new int[7] { 2, 6, 9, 16, 16, 4, 1 };

			int S = 0;
			int k = 0;
			Calc(t, 8, 7, 0, 0, S, k);

			Assert::AreEqual(S, -125);
			Assert::AreEqual(k, 38);

			for (int i = 0; i < 8; i++)
				delete[] t[i];
			delete[] t;
		}
	};
}
