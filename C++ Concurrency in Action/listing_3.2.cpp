#include <mutex>
#include <iostream>

class some_data
{
    int a;
    std::string b;

public:
    void do_something()
    {
        std::cout << "do_something." << std::endl;
    }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;

public:
    template <typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data);                         // 1
    }
};

some_data *unprotected;

void malicious_function(some_data &protected_data)
{
    unprotected = &protected_data;
    std::cout << "malicious_function." << std::endl;
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function);     //2
    unprotected->do_something();           //3
}

int main()
{
    foo();
}

/*
Trong ví dụ này, process_data có vẻ không có vấn đề gì, std::lock_ guard bảo vệ dữ liệu rất tốt.
Nhưng lệnh gọi hàm func (1) do người dùng cung cấp ở đây là foo có thể bỏ qua cơ chế bảo vệ
để đặt hàm malicious_ function được truyền vào (2) và sau đó gọi hàm do_something() (3) mà không bị khóa bởi mutex.

Vấn đề với đoạn mã này là nó hoàn toàn không được bảo vệ,
chỉ đơn giản là đánh dấu tất cả các mã cấu trúc dữ liệu có thể truy cập là loại trừ lẫn nhau.
Trong trường hợp này, nó đã bỏ lỡ code trong foo() để gọi unprotected->do_something().

Thật không may, C++ không thể cung cấp bất kỳ trợ giúp nào
và chỉ có thể được bảo vệ bởi các nhà phát triển bằng cách khóa chính xác mutex để bảo vệ dữ liệu.
Từ quan điểm lạc quan, vẫn có cách: không bao giờ truyền con trỏ hoặc tham chiếu đến dữ liệu được bảo vệ bên ngoài phạm vi Mutex.
Cho dù bằng cách trả lại chúng từ một hàm, lưu trữ chúng trong bộ nhớ hiển thị bên ngoài hoặc chuyển chúng dưới dạng
đối số với hàm do người dùng cung cấp.
*/
