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

void Change(int** a, const int rowCount, const int colCount)
{
    int tmp;

    for (int i = 0; i < rowCount; i += 2)
    {
        int imax = 0;
        for (int j = 0; j < colCount; j++)
            if (a[i][imax] < a[i][j])
                imax = j;

        tmp = a[i][imax];
        a[i][imax] = a[i][i];
        a[i][i] = tmp;
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
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    Change(a, rowCount, colCount);
    Print(a, rowCount, colCount);
}
