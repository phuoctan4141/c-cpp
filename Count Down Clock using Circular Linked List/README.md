# Count Down Clock using Circular Linked List

## Yêu cầu:

Chúng ta có thể lấy được thời gian hiện tại để đồng hồ có thể chạy như thời gian thực hay chúng ta có thể đếm ngược mà chúng ta muốn.

## Cách thức thực hiện:
**1. Khai báo struct Node và struct sClock:**
+ struct Node (dùng để lưu giá trị):
```cpp
int data
Node* Next
Node* Prev
```

+ struct sClock (dung để lưu các giá trị của đồng hồ: giờ, phút, giây):
```cpp
pNode h (giờ)
pNode m (phút)
pNode s (giây)
```
  
**2.Thao tác:**
+ Tạo danh sách rỗng.
+ Hàm tạo node.
+ Hàm thêm vào cuối danh sách (mỗi lần thêm, ta cho nút cuối trỏ đến nút đầu và ngược lại, để tạo danh sách liên kết vòng hai chiều).
+ Hàm tìm node có giá trị X.
+ Hàm tạo, gán giá trị hiện thực cho đồng hồ.
+ Hàm xuất ra đồng hồ (có thể chạy đúng với thời gian thực).
+ Hàm xuất bộ đếm ngược của đồng hồ.
