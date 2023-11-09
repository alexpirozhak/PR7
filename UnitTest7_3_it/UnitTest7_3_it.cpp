#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7_3_it/PR7_3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73it
{
	TEST_CLASS(UnitTest73it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** t = new int*[4];

			t[0] = new int[5] { 5, 2, 1, 7, 4 };
			t[1] = new int[5] { 10, 3, 5, 9, 2 };
			t[2] = new int[5] { 5, 3, 7, 6, 0 };
			t[3] = new int[5] { 4, 5, 6, 9, 4 };

			int Q = Task1(t, 4, 5);
			int max;
			Task2(t, 4, 5, max);

			Assert::AreEqual(Q, 3);
			Assert::AreEqual(max, 9);

			for (int i = 0; i < 4; i++)
				delete[] t[i];
			delete[] t;
		}
	};
}
