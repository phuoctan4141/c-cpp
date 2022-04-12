#include <iostream>
using namespace std;

int *arr;

int main()
{
    int n = 5;
    arr = new int[n];

    cout << "Dia chi arr " << &arr << endl;
    cout << "Dia chi arr[0] " << arr << endl;
    cout << "Dia chi arr[0] " << &arr[0] << endl;

    cout << "Cac phan tu trong mang arr ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Cac phan tu trong mang arr ";

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }

    cout << endl;

    int *ptr = arr;
    cout << "Con tro den con tro " << endl;
    cout << "Size of arr: " << sizeof(arr) << endl;
    cout << "Size of ptr: " << sizeof(ptr) << endl;

    int b_arr[5];
    int *b_ptr = b_arr;

    cout <<"Con tro den mot mang " << endl;
    cout << "Size of arr: " << sizeof(b_arr) << endl;
    cout << "Size of ptr: " << sizeof(b_ptr) << endl;

    cout << "Cac phan tu trong mang arr ma ptr tro toi ";

    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " ";
    }

    cout << endl;

    cout << "Cac phan tu trong mang arr ma ptr tro toi ";

    for (ptr = arr; ptr <= arr + 4; ptr++)
    {
        cout << *ptr << " ";
    }

    cout << endl;

    ptr = &arr[2];

    cout << "Phan tu arr[2] ma ptr tro toi " << *ptr << endl;
    cout << "Phan tu arr[2 - 1] ma ptr tro toi " << *(ptr - 1) << endl;
    cout << "Phan tu arr[2 + 1] ma ptr tro toi " << *(ptr + 1) << endl;

    char *p_str = "Chao tat ca moi nguoi, ahihi";

    cout << "Gia tri chuoi p_str: " << p_str << endl;

    delete[] arr;

    return 0;
}