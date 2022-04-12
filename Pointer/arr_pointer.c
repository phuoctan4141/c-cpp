#include <stdio.h>
#include <cstdlib>

int main(void)
{
    int n = 5;
    int *arr;
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    printf("Cac phan tu trong arr ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    arr = (int *)calloc(n, sizeof(int));

    printf("Cac phan tu trong arr ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}