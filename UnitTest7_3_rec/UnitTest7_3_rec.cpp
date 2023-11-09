#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_3_rec/PR7_3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** t = new int*[4];

			t[0] = new int[5] { 10, 1, 8, 1, 8 };
			t[1] = new int[5] { 6, 1, 7, 4, 0 };
			t[2] = new int[5] { 0, 8, 7, 4, 0 };
			t[3] = new int[5] { 5, 7, 9, 5, 8 };

			int Q = Task1(t, 4, 5, 0, 0, 0);
			int max;
			Task2(t, 4, 5, max);

			Assert::AreEqual(Q, 2);
			Assert::AreEqual(max, 8);

			for (int i = 0; i < 4; i++)
				delete[] t[i];
			delete[] t;
		}
	};
}
