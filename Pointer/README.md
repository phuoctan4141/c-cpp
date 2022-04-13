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

```cpp
int n = 5;
int *arr;

arr = new int[n];
```


