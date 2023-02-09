#include <map>
#include <string>
#include <mutex>
#include <shared_mutex>

class dns_entry
{};

class dns_cache
{
    std::map<std::string,dns_entry> entries;
    std::shared_mutex entry_mutex;
public:
    dns_entry find_entry(std::string const& domain)
    {
        std::shared_lock<std::shared_mutex> lk(entry_mutex);    // 1
        std::map<std::string,dns_entry>::const_iterator const it=
            entries.find(domain);
        return (it==entries.end())?dns_entry():it->second;
    }
    void update_or_add_entry(std::string const& domain,
                             dns_entry const& dns_details)
    {
        std::lock_guard<std::shared_mutex> lk(entry_mutex); // 2
        entries[domain]=dns_details;
    }
};

int main()
{}

/*
Listing 3.13 Protecting a data structure with std::shared_mutex
Trong ví dụ này, find_entry() sử dụng std::shared_lock để bảo vệ quyền chia sẻ và quyền chỉ đọc (1).
Điều này cho phép các threads gọi find_entry() đồng thời mà không bị lỗi.
Mặt khác, update_or_add_entry() sử dụng std::lock_guard<> để cung cấp quyền truy cập độc quyền vào table ngay khi nó được update (2).
Không chỉ các threads khác không được truy cập update_or_add_entry(), mà các threads gọi find_entry() cũng bị chặn.

Tức là các threads có thể gọi find_entry() đồng thời để đọc dự liệu, nhưng khi một thread nào đó thay đổi giá trị khi gọi hàm update_or_add_entry()
se chặn truy cập dữ liệu và các hàm trên.
*/
