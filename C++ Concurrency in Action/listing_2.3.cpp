#include <thread>
#include <iostream>

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
        t(t_)
    {}
    ~thread_guard()
    {
        if(t.joinable())    // 1
        {
            t.join();       // 2
        }
    }
    thread_guard(thread_guard const&)=delete;   // 3
    thread_guard& operator=(thread_guard const&)=delete;
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
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
        
    do_something_in_current_thread();
}   // 4

int main()
{
    f();
}

/*
Khi thực hiện thread hiện tại đến cuối f (4), các đối tượng (object) cục bộ bị phá hủy theo hướng ngược lại.
Do đó đối tượng thread_guard g(t) bị phá hủy đầu tiên.
Ngay cả khi do_something_in_current_thread throws an exception, điều này vẫn diễn ra.

Trong ~thread_guard(), kiểm tra đầu tiên xem liệu đối tượng thread có đang joinable() (1) trước khi gọi join() (2).
Điều này rất quan trọng, bởi vì join() chỉ có thể được gọi một lần cho một luồng thực thi nhất định, 
vì vậy sẽ là một sai lầm nếu làm như vậy nếu luồng đó đã joined.

Hàm the copy constructor and copy-assignment operators (3) được đánh dấu =delete để đảm bảo rằng chúng không được trình biên dịch
tự động cung cấp. Copying and assigning object như vậy sẽ rất là nguy hiểm,
bởi vì sao đó nó có thể tồn tại lâu hơn phạm vi mà thread mà nó đang joining.

Nếu bạn không muốn đợi thread kết thúc, bạn có thể tách (detaching) thread ra để tránh các trường hợp exception-safety.
Điều này phá vỡ sự liên kết của thread với đối tượng std::thread
và đảm bảo rằng std::terminate() sẽ không được gọi khi đối tượng std::thread bị phá hủy,
mặc dù thread vẫn đang chạy trong nền.
*/
