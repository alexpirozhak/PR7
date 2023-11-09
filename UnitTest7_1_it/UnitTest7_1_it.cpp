#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_1_it/PR7_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11it
{
	TEST_CLASS(UnitTest11it)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int** t = new int* [8];

			t[0] = new int[7] { 10, 16, -6, -12, 15, 15, -19 };
			t[1] = new int[7] { 6, 1, 2, 18, -19, -6, -3 };
			t[2] = new int[7] { 5, 9, -3, 8, -6, -16, -13 };
			t[3] = new int[7] { 2, 4, 1, -6, -17, -14, -15 };
			t[4] = new int[7] { -7, -21, -3, 5, -2, 4, -19 };
			t[5] = new int[7] { -10, -2, 0, -18, 6, -7, -6 };
			t[6] = new int[7] { -20, -3, 13, -8, -19, -8, 14 };
			t[7] = new int[7] { -21, 3, 18, 12, -11, 15, -14 };

			int S = 0;
			int k = 0;
			Calc(t, 8, 7, S, k);

			Assert::AreEqual(S, -234);
			Assert::AreEqual(k, 46);

			for (int i = 0; i < 8; i++)
				delete[] t[i];
			delete[] t;
		}
	};
}
