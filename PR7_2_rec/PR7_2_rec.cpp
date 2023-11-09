#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else
        if (i < rowCount - 1)
            Create(a, rowCount, colCount, Low, High, i + 1, 0);
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

void Change(int** a, const int rowCount, const int colCount, int i, int j, int& imax)
{
    if (j < colCount)
    {
        if (a[i][imax] < a[i][j])
            imax = j;
        Change(a, rowCount, colCount, i, j + 1, imax);
    }
    else
    {
        int tmp = a[i][imax];
        a[i][imax] = a[i][i];
        a[i][i] = tmp;

        if (i < rowCount - 2)
            Change(a, rowCount, colCount, i + 2, 0, imax);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int n = 9;
    int Low = -10;
    int High = 10;
    int rowCount = n;
    int colCount = n;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High, 0, 0);
    Print(a, rowCount, colCount, 0, 0);

    int imax = 0;
    Change(a, rowCount, colCount, 0, 0, imax);
    Print(a, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
