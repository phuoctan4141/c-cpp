#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list;   // 1
std::mutex some_mutex;  // 2

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);  // 3
    some_list.push_back(new_value);
}
bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(some_mutex);  // 4
    return std::find(some_list.begin(),some_list.end(),value_to_find)
        != some_list.end();
}

#include <iostream>

int main()
{
    add_to_list(42);
    std::cout<<"contains(1)="<<list_contains(1)<<", contains(42)="<<list_contains(42)<<std::endl;
}

/*
Biến toàn cục (1) được bảo vệ bởi mutex toàn cục (2).
Việc sử dụng std::lock_guard<std::mutex> trong hàm add_to_list() (3) và list_contains() (4), có ý nghĩa là 
việc truy cập vào dữ liệu trong chúng là lỗi trừ lẫn nhau: list_contains() sẽ không bao giờ thấy một phần của some_list
bị thay đổi bởi add_to_list().
*/
