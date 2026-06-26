# Hướng dẫn Chạy và Sử dụng (Shopping System)

Tài liệu này hướng dẫn chi tiết cách biên dịch dự án bằng hệ thống CMake và hướng dẫn sử dụng các tính năng chính của Shopping System.

---

## 1. Hướng dẫn Biên dịch (Build) với CMake

Dự án này sử dụng công cụ CMake để quản lý quá trình biên dịch C++. Để build dự án từ đầu, bạn vui lòng mở terminal ở thư mục gốc của project (nơi chứa file `CMakeLists.txt`) và làm theo các bước sau:

### Bước 1: Tạo cấu hình CMake
Chạy lệnh sau để sinh ra các file cấu hình build:
```bash
cmake -S . -B build
```
*(Giải thích: `-S .` chỉ định thư mục source code là thư mục hiện tại, `-B build` yêu cầu CMake tạo một thư mục tên là `build` để chứa các file sinh ra nhằm không làm rác thư mục code gốc).*

### Bước 2: Biên dịch mã nguồn (Compile)
Sau khi Bước 1 chạy xong, dùng lệnh sau để tiến hành compile:
```bash
cmake --build build
```
*(Quá trình biên dịch sẽ chạy và build từng file `.cpp`. Khi đạt `[100%] Built target ShoppingSystem`, hệ thống đã sẵn sàng).*

### Bước 3: Chạy chương trình
Cuối cùng, khởi động ứng dụng bằng lệnh:
```bash
./build/ShoppingSystem
```

> **Mẹo:** Nếu sau này bạn có chỉnh sửa thêm code, bạn chỉ cần chạy lại **Bước 2** và **Bước 3** mà không cần chạy lại Bước 1 (trừ khi bạn thêm file `.cpp` mới vào `CMakeLists.txt`).

---

## 2. Hướng dẫn Sử dụng (User Guide)

### Các chức năng trên Menu
Khi chương trình khởi chạy thành công, bạn sẽ thấy Menu chính:
```text
===== SHOPPING SYSTEM =====
1. View all products
2. View categories
3. View products by category
4. Add product to cart
5. View cart
6. Remove product from cart
7. Checkout
8. View Order History
0. Exit
Choose: 
```

### Cách thử nghiệm quy trình mua hàng chuẩn:
1. Bấm **`4`** để mua sản phẩm (Ví dụ nhập ID `1` để mua Laptop, nhập số lượng `1`).
2. Bấm **`4`** lần nữa (Nhập ID `2` để mua Chuột, nhập số lượng `2`).
3. Bấm **`5`** để kiểm tra giỏ hàng xem hàng đã vào đủ chưa.
4. Bấm **`7`** để tiến hành thanh toán (Checkout).

### Trải nghiệm Checkout (Phím 7)
Ngay khi bạn chọn `7`, hệ thống sẽ yêu cầu bạn nhập liệu tuần tự:
1. **Thông tin khách hàng:** *Tên, Email, Số điện thoại*.
2. **Thông tin địa chỉ:** *Số/Tên đường, Thành phố, Bang/Tỉnh, Mã ZIP*.
3. **Hình thức Giao hàng:**
   - Nhập `1` cho Standard ($5.0, mất 3-5 ngày).
   - Nhập `2` cho Express ($15.0, mất 1-2 ngày).
4. **Hình thức Thanh toán:**
   - Nhập `1` (Credit Card): Bạn sẽ cần nhập số thẻ (ví dụ `123456789`), hạn sử dụng (`12/26`) và mã CVV (`123`).
   - Nhập `2` (PayPal): Nhập Email PayPal.
   *(Ghi chú: Đây là hệ thống giả lập nên bạn có thể nhập số thẻ bất kỳ. Giao dịch sẽ luôn được thông qua để bạn có thể xem được Hóa đơn).*

### Hóa đơn và Lịch sử (Phím 8)
- Ngay sau khi nhập thẻ thành công, hệ thống sẽ in ra một tờ **Hóa đơn (Invoice)** chuyên nghiệp hiển thị rõ thông tin người mua, chi tiết sản phẩm, phí giao hàng và tổng tiền.
- Bất cứ lúc nào sau đó, bạn có thể quay lại Menu chính và bấm **`8`** để tra cứu danh sách lịch sử các Đơn hàng (Order ID, Tên người mua, Tổng tiền).