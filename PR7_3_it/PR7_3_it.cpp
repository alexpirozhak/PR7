#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Task1(int** a, int rowCount, int colCount)
{
	int Q = 0;
	for (int i = 0; i < rowCount; i++)
	{
		bool IsTrue = true;
		for (int j = 0; j < colCount; j++)
			if (a[i][j] == 0)
			{
				IsTrue = false;
				break;
			}
		if (IsTrue)
			Q++;
	}
	return Q;
}

void Add(int*& a, int& size, int element)
{
	int* newA = new int[size + 1];
	for (int i = 0; i < size; i++)
		newA[i] = a[i];
	newA[size] = element;

	size++;
	delete[] a;
	a = newA;
}

void Max(int* a, const int size, int& max)
{
	max = a[0];

	for (int i = 0; i < size; i++)
		if (a[i] > max)
			max = a[i];
}

void Contains(int* a, const int size, int element, bool& contains)
{
	for (int i = 0; i < size; i++)
		if (a[i] == element)
		{
			contains = true;
			return;
		}

	contains = false;
}

void FindRepeatitiveElements(int** a, const int rowCount, const int colCount, int*& repeatitiveElements, int& size)
{
	int registrySize = 0;
	int* elementsRegistry = new int[registrySize];
	bool containsElement = false;

	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
		{
			Contains(elementsRegistry, registrySize, a[i][j], containsElement);
			if (containsElement)
				Add(repeatitiveElements, size, a[i][j]);
			else
				Add(elementsRegistry, registrySize, a[i][j]);
		}
}

void Task2(int** a, const int rowCount, const int colCount, int& max)
{
	int size = 0;
	int* repeatitiveElements = new int[size];

	FindRepeatitiveElements(a, rowCount, colCount, repeatitiveElements, size);

	if (size > 0)
		Max(repeatitiveElements, size, max);
	else
		max = -1;
}

int main()
{
	srand((unsigned)time(NULL));
	int k, n;
	cout << "rowCount = "; cin >> k; cout << endl;
	cout << "colCount = "; cin >> n; cout << endl;

	int Low = 0;
	int High = 10;
	int rowCount = k;
	int colCount = n;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	//Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int Q = Task1(a, rowCount, colCount);
	cout << "Q = " << Q << endl;

	int max;
	Task2(a, rowCount, colCount, max);
	cout << "max = " << max << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
