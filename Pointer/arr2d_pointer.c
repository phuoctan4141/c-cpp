#include <stdio.h>
#include <cstdlib>

int main(void)
{
    int row_1 = 3;
    int col_1 = 5;

    int **arr2d_1;

    arr2d_1 = (int **)malloc(sizeof(int *) * col_1);

    for (int i = 0; i < col_1; i++)
    {
        arr2d_1[i] = (int *)malloc(sizeof(int) * row_1);
    }

    for (int row = 0; row < row_1; row++)
    {
        for (int col = 0; col < col_1; col++)
        {
            arr2d_1[row][col] = row + col;
        }
    }

    printf("Cac phan tu trong arr2d_1 \n");

    for (int row = 0; row < row_1; row++)
    {
        for (int col = 0; col < col_1; col++)
        {
            printf("%d ", arr2d_1[row][col]);
        }

        printf("\n");
    }

    // Giai phong bo nho
    for (int i = 0; i < col_1; i++)
    {
        free(arr2d_1[i]);
    }

    free(arr2d_1);

    // Khai bao 2d tren 1d

    int row_2 = 3;
    int col_2 = 5;

    int *arr2d_2;

    arr2d_2 = (int *)malloc(sizeof(int) * row_2 * col_2);

    for (int col = 0; col < col_2; col++)
    {
        for (int row = 0; row < row_2; row++)
        {
            arr2d_2[col * row_2 + row] = col + row;
        }
    }

    printf("Cac phan tu trong arr2d_2 \n");

    for (int row = 0; row < row_2; row++)
    {
        for (int col = 0; col < col_2; col++)
        {

            printf("%d ", arr2d_2[col * row_2 + row]);
        }

        printf("\n");
    }

    free(arr2d_2);

    return 0;
}
