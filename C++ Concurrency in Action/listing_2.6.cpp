#include <thread>
#include <utility>
#include <iostream>

class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_): // 1
        t(std::move(t_))
    {
        if(!t.joinable()) // 2
            throw std::logic_error("No thread");
    }
    ~scoped_thread()
    {
        t.join(); // 3
    }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void do_something(int& i)
{
    std::cout<<"do_something: "<<i<<std::endl;
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<10;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{
    std::cout<<"do_something_in_current_thread."<<std::endl;
}

void f()
{
    int some_local_state;
    scoped_thread t{std::thread(func(some_local_state))}; // 4
        
    do_something_in_current_thread();
} // 5

int main()
{
    f();
}

/*
Tương tự như 2.3, nhưng thread được truyền trực tiếp vào scoped_thread (4) thay vì tạo ra một biến độc lập.
Khi thread đầu tiên đến cuối f() (5), các scoped_thread object bị phá hủy và sau đó chuyển thread (3) được cung cấp vào constructor.
Trong khi với thread_guard class từ 2.3, destructor kiểm tra xem thread vẫn còn joinable hay không.
Bạn có thể làm điều đó trong constructor (2) và throw an exception nếu nó không thỏa mãn.
*/
