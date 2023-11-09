#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void AllocateMatrix(int** a, int rowCount, int colCount, int i)
{
	a[i] = new int[colCount];
	
	if (i < rowCount - 1)
		AllocateMatrix(a, rowCount, colCount, i + 1);
}

void FreeMatrix(int** a, int rowCount, int i)
{
	delete[] a[i];

	if (i < rowCount - 1)
		FreeMatrix(a, rowCount, i + 1);
	else
		delete[] a;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Input(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];
	if (j < colCount - 1)
		Input(a, rowCount, colCount, i, j + 1);
	else
	{
		cout << endl;

		if (i < rowCount - 1)
			Input(a, rowCount, colCount, i + 1, 0);
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int Task1(int** a, int rowCount, int colCount, int i, int j, int Q)
{
	bool IsTrue = true;
	if (j < colCount)
	{
		if (a[i][j] == 0)
			IsTrue = false;
		else
		{
			return Task1(a, rowCount, colCount, i, j + 1, Q);
		}
	}
	if (i < rowCount)
	{
		if (IsTrue == true)
			Q++;
	}
	if (i < rowCount - 1)
	{
		return Task1(a, rowCount, colCount, i + 1, 0, Q);
	}
	return Q;
}

void Add(int*& a, int& size, int element, int* temp, int i)
{
	temp[i] = a[i];

	if (i < size - 1)
		Add(a, size, element, temp, i + 1);
	else
	{
		temp[size] = element;
		size++;
		delete[] a;
		a = temp;
	}
}

void Max(int* a, const int size, int& max, int i)
{
	if (a[i] > max)
		max = a[i];

	if (i < size - 1)
		Max(a, size, max, i + 1);
}

void Contains(int* a, const int size, int element, bool& contains, int i)
{
	if (a[i] == element)
	{
		contains = true;
		return;
	}

	if (i < size - 1)
		Contains(a, size, element, contains, i + 1);
}

void FindRepeatitiveElements(int** a, const int rowCount, const int colCount, int*& repeatitiveElements, int& size,
	int*& elementsRegistry, int& registrySize, int i, int j)
{
	bool contains = false;
	Contains(elementsRegistry, registrySize, a[i][j], contains, 0);
	if (contains)
	{
		int* temp = new int[size + 1];
		Add(repeatitiveElements, size, a[i][j], temp, 0);
	}
	else
	{
		int* temp = new int[registrySize + 1];
		Add(elementsRegistry, registrySize, a[i][j], temp, 0);
	}

	if (j < colCount - 1)
		FindRepeatitiveElements(a, rowCount, colCount, repeatitiveElements, size, elementsRegistry, registrySize, i, j + 1);
	else if (i < rowCount - 1)
		FindRepeatitiveElements(a, rowCount, colCount, repeatitiveElements, size, elementsRegistry, registrySize, i + 1, 0);
}

void Task2(int** a, const int rowCount, const int colCount, int& max)
{
	int size = 0;
	int* repeatitiveElements = new int[size];

	int registrySize = 0;
	int* elementsRegistry = new int[registrySize];
	FindRepeatitiveElements(a, rowCount, colCount, repeatitiveElements, size, elementsRegistry, registrySize, 0, 0);
	
	if (size > 0)
	{
		max = repeatitiveElements[0];
		Max(repeatitiveElements, size, max, 0);
	}
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
	int** a = new int*[rowCount];
	AllocateMatrix(a, rowCount, colCount, 0);

	Create(a, rowCount, colCount, Low, High, 0, 0);
	//Input(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	int Q = Task1(a, rowCount, colCount, 0, 0, 0);
	cout << "Q = " << Q << endl;

	int max;
	Task2(a, rowCount, colCount, max);
	cout << "max = " << max << endl;

	FreeMatrix(a, rowCount, 0);

	return 0;
}
