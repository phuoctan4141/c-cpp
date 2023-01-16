#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

template <typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        result = std::accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);

    if (!length) // 1
        return init;

    unsigned long const min_per_thread = 8;
    unsigned long const max_threads =
        (length + min_per_thread - 1) / min_per_thread; // 2

    unsigned long const hardware_threads =
        std::thread::hardware_concurrency();

    unsigned long const num_threads = // 3
        std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

    unsigned long const block_size = length / num_threads; // 4

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1); // 5

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size); // 6
        threads[i] = std::thread(            // 7
            accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i]));
        block_start = block_end; // 8
    }
    accumulate_block<Iterator, T>()(
        block_start, last, results[num_threads - 1]); // 9

    std::for_each(threads.begin(), threads.end(),
                  std::mem_fn(&std::thread::join)); // 10

    return std::accumulate(results.begin(), results.end(), init); // 11
}

int main()
{
    std::vector<int> vi;
    for (int i = 0; i < 10; ++i)
    {
        vi.push_back(10);
    }
    int sum = parallel_accumulate(vi.begin(), vi.end(), 5);
    std::cout << "sum=" << sum << std::endl;
}

/*
Nếu phạm vi input là rỗng (null) (1), bạn nhận được giá trị ban đầu được cung cấp là giá trị tham số của init.
Nếu như có nhiều hơn một phần tử trong phạm vi, bạn cần phải chia số lượng phần tử cần xử lý
cho số nhiệm vụ tối thiểu trong một block size để đưa ra số thread tối đa cần hoạt động (2).

Số thread để thực hiện là tối thiểu của max_threads mà bạn tính được và hardware_threads được hỗ trợ (3).
Nếu std::thread:: hardware_concurrency() trẩ về không, chọn một số mà bạn muốn, trong trường hợp này là 2 (3).
Bạn không muốn chạy quá nhiều thread vì điều đó sẽ làm chậm mọi thứ trên một single-core machine, nhưng tương tự như vậy,
bạn không muốn chạy quá ít vì bạn sẽ bỏ qua tính đồng thời có sẵn.

Sô lượng phần tử trong mỗi thread là độ dài trong phạm vi được chia bởi số thread (4).

Bây giờ số lượng thread đã được xác định, bạn có thể tạo std::vector<T> để lưu trữ kết quả trung gian
và std::vector<std::thread> cho các thread (5).
Bởi vì đã có một thread trước khi bắt đầu (main thread), bạn cần khởi chạy ít hơn một thread so với num_threads.

Sử dụng một vòng lập để bắt đầu các thread: block_end Iterator trỏ đến cuối block hiện tại (6) và khởi động một thread mới
để tính toán accumulate kết quả cho block hiện tại (7).
Khi Iterator trỏ đến cuối block hiện tại, block tiếp theo sẽ được khởi chạy (8).

Sau khi khởi chạy tất cả các thread, thread (9) này sau đó có thể xử lý kết quả của block cuối cùng.
Bởi vì bạn biết block cuối cùng là gì, không quan trọng có bao nhiêu phần tử trong block cuối cùng.

Khi đã accumulate cho block cuối cùng, bạn có thể đợi tất cả các thread với std::for_ each (10) (như trong listing_2.8),
sau đó cộng tất cả các kết quả với std::accumulate (11).
*/
