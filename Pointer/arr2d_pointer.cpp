#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int **arr2d{new int *[n]};

    for (int count = 0; count < n; count++)
    {
        arr2d[count] = new int[n];
    }

    // int (*arr2d_1)[5] = new int[n][5];

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            arr2d[row][col] = row + col;
        }
    }

    cout << "Cac phan tu trong arr2d " << endl;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << arr2d[row][col];
        }

        cout << endl;
    }

    cout << "Cac phan tu trong arr2d " << endl;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << *(*(arr2d + row) + col);
        }

        cout << endl;
    }

    cout << "Giai phong bo nho " << endl;

    for (int count = 0; count < n; count++)
    {
        delete[] arr2d[count];
    }

    delete[] arr2d;

    cout << "okela" << endl;

    return 0;
}