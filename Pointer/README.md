# Con trỏ trong C/C++

## Cách khai báo con trỏ

Cú pháp khai báo:

```c
<kiểu dữ liệu> * <tên biến>

Ví dụ:

int *p_i; // khai báo con trỏ để trỏ tới biến kiểu nguyên
int *p, val; // khai báo con trỏ p kiểu int, biến val (không phải con trỏ) kiểu int
float *p_f; // khai báo con trỏ để trỏ tới biến kiểu thực
char *p_char; // khai báo con trỏ để trỏ tới biến kiểu ký tự
void *p_v; // con trỏ kiểu void (không kiểu)
```

## Gán giá trị cho con trỏ

```c
int *p, value;
value = 5;
p = &value; // khởi tạo giá trị cho con trỏ p là địa chỉ của value
```

Hoặc

```c
int value = 5;
int *p = &value; // khai báo con trỏ p và khởi tạo giá trị cho con trỏ là địa chỉ của value
 ```
 
**Lưu ý:**

* Con trỏ khi khai báo nên được khởi tạo giá trị ngay.
* Con trỏ kiểu void là loại biến con trỏ tổng quát, nó có thể nhận địa chỉ của biến bất kỳ ở bất cứ kiểu dữ liệu nào.

```c
#include <stdio.h>
int main()
{
  int number = 5;
  float *p_int = &number;
}
 
// Ouput:
PS G:\c_cources\day_63> g++ .\Pointer.cpp
.\Pointer.cpp: In function 'int main()':
.\Pointer.cpp:5:19: error: cannot convert 'int*' to 'float*' in initialization
   float *p_int = &number;
                   ^
```

* Khởi tạo con trỏ bằng địa chỉ NULL nếu chưa cần dùng theo cách sau: int *p = NULL. Khi đó con trỏ NULL luôn có giá trị 0.

```c
#include <stdio.h>
int main()
{
  void *p_int = NULL;
  printf("Gia tri cua con tro la %d", p_int);
}
// Output
// Gia tri cua con tro la 0
```

## Bản chất của con trỏ

```cpp
#include <iostream>
using namespace std;

void sum_x(int &x, int i);
void sum_p(int *p, int i);

int main()
{
    int x = 5;
    int *p = &x;

    cout << "Dia chi cua x " << &x << endl;
    cout << "Gia tri cua x " << x << endl;

    cout << "Gia tri cua p " << p << endl;
    cout << "Dia chi cua p " << &p << endl;
    cout << "Gia tri cua x ma p tro toi " << *p << endl;

    *p = x + 1;

    cout << "Gia tri cua x ma p tro toi " << *p << endl;
    cout << "Gia tri cua x " << x << endl;

    sum_x(x, 10);

    cout << "Gia tri cua x " << x << endl;

    sum_p(p, 20);

    cout << "Gia tri cua x ma p tro toi " << *p << endl;
    cout << "Gia tri cua x " << x << endl;

    return 0;
}

void sum_x(int &x, int i)
{
    x = x + i;
}

void sum_p(int *p, int i)
{
    *p = *p + i;
}
```

Chạy tệp tin sau: [pointer.cpp](https://github.com/phuoctan4141/c-cpp/blob/main/Pointer/pointer.cpp)

## Con trỏ và mảng

### Mảng một chiều

#### Khai báo mảng một chiều với con trỏ bằng C

1. Dùng malloc:

```c
int n = 5;
int *arr;

arr = (int *)malloc(n * sizeof(int));
```

2. Dùng callloc:

```c
int n = 5;
int *arr;

arr = (int *)calloc(n, sizeof(int));
```

3. Giải phóng bộ nhớ:

```c
free(arr);
```

4. So Sánh giữa malloc và calloc:

| Tiêu chuẩn | Malloc | Calloc |
| --- | --- | --- |
| Cú pháp | void* malloc (size_t size) | void* calloc (size_t num, size_t size) |
| Mục đích | cấp phát vùng nhớ kích thước là **size** | cấp phát vùng nhớ đủ chứa **num**, mỗi phần tử có kích thước là **size** |
| Số tham số | 1 | 2 |
| Kết quả trả về | --> | Con trỏ được cấp phát nếu thành công, con trỏ Null nếu không thành công |
| Giá trị khởi tạo | giá trị rác | được gán bằng 0 |
| --- | --- | --- |


#### Khai báo mảng một chiều với con trỏ bằng C++

1. Cú pháp khai báo:

```cpp
int n = 5;
int *arr;

arr = new int[n];
```

2. Giải phóng bộ nhớ:

```cpp
delete[] arr;
```

3. So sánh giữa malloc và new:

| | malloc | new |
| --- | --- | --- |
| Ngôn ngữ | C | C++ |
| Kích thước cấp phát | phải tính toán kích thước vùng nhớ cần cấp phát trước khi gọi | tự động tính toán kích thước vùng nhớ cần cấp phát dựa vào kiểu dữ liệu truyền vào |
| Cấp phát thất bại | trả về con trỏ NULL | throw exception |
| Cấp phát thành công | trả về con trỏ void* và muốn sử dụng phải ép kiểu về kiểu cần dùng | gọi hàm khởi tạo của đối tượng được cấp phát nếu đó là, kiểu con trỏ là kiểu của đối tượng được cấp phát |
| Loại đối tượng | hàm | toán tử (operator) |
| Khả năng override | không thể | có thể |
| Thay đổi kích thước vùng nhớ cấp phát | có thể sử dụng realloc để thay đổi kích thước vùng nhớ được cấp phát | không thể thay đổi |
| Giải phóng bộ nhớ | free(x) | delete x |
| --- | --- | --- |

#### Bản chất

```cpp
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
```

Chạy tệp tin sau: [arr_pointer.cpp](https://github.com/phuoctan4141/c-cpp/blob/main/Pointer/arr_pointer.cpp)

### Mảng hai chiều

#### Bản chất

| | Col 1 | Col 2 | Col 3 | Col 4 |
| --- | --- | --- | --- | --- |
| Row 1 | [0][0] | [0][1] | [0][2] | [0][3] |
| Row 2 | [1][0] | [1][1] | [1][2] | [1][3] |
| Row 3 | [2][0] | [2][1] | [2][2] | [2][3] |
| --- | --- | --- | --- | --- |

#### Khai báo và giải phóng trên C:

```c
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
```

Chạy tệp tin sau: [arr2d_pointer.c](https://github.com/phuoctan4141/c-cpp/blob/main/Pointer/arr2d_pointer.c)

#### Khai báo và giải phóng trên C++:

```cpp
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

    // 2d tren 1d

    int p_row = 3;
    int p_col = 5;

    int *p_arr2d = new int[p_row * p_col];

    for (int col = 0; col < p_col; col++)
    {
        for (int row = 0; row < p_row; row++)
        {
            p_arr2d[col * p_row + row] = col + row;
        }
    }

    cout << "Cac phan tu trong p_arr2d " << endl;

    for (int row = 0; row < p_row; row++)
    {
        for (int col = 0; col < p_col; col++)
        {
            cout << p_arr2d[col * p_row + row];
        }

        cout << endl;
    }
    
    delete[] p_arr2d;

    return 0;
}
```

Chạy tệp tin sau: [arr2d_pointer.cpp](https://github.com/phuoctan4141/c-cpp/blob/main/Pointer/arr2d_pointer.cpp)
