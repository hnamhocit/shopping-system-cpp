# CÂU HỎI VẤN ĐÁP - Shopping System (OOP C++)

---

## PHẦN 1: CÂU HỎI VỀ TỔNG QUAN DỰ ÁN

### Câu 1: Dự án của em làm về cái gì? Mô tả tổng quan?

**Trả lời:**
Dự án của em là một hệ thống mua sắm (Shopping System) viết bằng C++, mô phỏng quy trình mua hàng trực tuyến. Hệ thống bao gồm:
- Quản lý danh mục và sản phẩm (có 2 loại: sản phẩm vật lý và sản phẩm số)
- Giỏ hàng (thêm, xóa sản phẩm)
- Quản lý tồn kho
- Thanh toán qua Credit Card hoặc PayPal
- Tạo đơn hàng và xuất hóa đơn
- Xem lịch sử đơn hàng

### Câu 2: Dự án có bao nhiêu class? Kể tên và vai trò?

**Trả lời:**
Dự án có **19 class**, chia thành các nhóm:

**Nhóm sản phẩm:**
- `Category`: Danh mục sản phẩm (ví dụ: Electronics, Books)
- `Product`: Class trừu tượng đại diện cho sản phẩm chung
- `PhysicalProduct`: Sản phẩm vật lý (có trọng lượng, phí ship)
- `DigitalProduct`: Sản phẩm số (có link download, phí ship = 0)

**Nhóm kho & giỏ hàng:**
- `InventoryItem`: Quản lý số lượng tồn kho của mỗi sản phẩm
- `CartItem`: Một mục trong giỏ hàng (gồm sản phẩm + số lượng)

**Nhóm thanh toán:**
- `PaymentMethod`: Class trừu tượng cho phương thức thanh toán
- `CreditCardPayment`: Thanh toán bằng thẻ tín dụng
- `PayPalPayment`: Thanh toán bằng PayPal
- `PaymentProcessor`: Xử lý giao dịch thanh toán

**Nhóm đơn hàng:**
- `OrderItem`: Một mục trong đơn hàng
- `Order`: Đơn hàng hoàn chỉnh
- `OrderManager`: Quản lý danh sách đơn hàng
- `Invoice`: Xuất hóa đơn

**Nhóm khách hàng & vận chuyển:**
- `Address`: Địa chỉ giao hàng
- `Customer`: Thông tin khách hàng
- `ShippingMethod`: Phương thức vận chuyển

**Nhóm điều khiển:**
- `CheckoutSession`: Xử lý quy trình thanh toán
- `ShoppingSystem`: Class chính điều khiển toàn bộ hệ thống

---

## PHẦN 2: CÂU HỎI VỀ 4 TÍNH CHẤT OOP

### Câu 3: Dự án thể hiện tính đóng gói (Encapsulation) ở đâu?

**Trả lời:**
Tất cả thuộc tính trong các class đều được khai báo **`private`**, không cho phép truy cập trực tiếp từ bên ngoài. Thay vào đó sử dụng các phương thức **getter/setter** để truy cập.

**Ví dụ trong class `Product`:**
```cpp
class Product {
private:          // Thuộc tính private
    int id;
    std::string name;
    double price;
    Category category;

public:           // Getter public
    int getId() const;
    std::string getName() const;
    double getPrice() const;
};
```

**Lợi ích:** Bảo vệ dữ liệu, kiểm soát được cách dữ liệu bị thay đổi, dễ bảo trì code.

### Câu 4: Dự án thể hiện tính kế thừa (Inheritance) ở đâu?

**Trả lời:**
Dự án có **2 cây kế thừa**:

**Cây 1 — Product:**
```
Product (abstract)
├── PhysicalProduct
└── DigitalProduct
```

**Cây 2 — PaymentMethod:**
```
PaymentMethod (abstract)
├── CreditCardPayment
└── PayPalPayment
```

**Ví dụ code:**
```cpp
class PhysicalProduct : public Product {    // Kế thừa public từ Product
private:
    double weight;
    double shippingFee;
public:
    // Override các phương thức ảo của Product
    double getShippingFee() const override;
    std::string getType() const override;
    void display() const override;
};
```

**Lợi ích:** Tái sử dụng code, `PhysicalProduct` và `DigitalProduct` không cần viết lại `getId()`, `getName()`, `getPrice()` mà kế thừa từ `Product`.

### Câu 5: Dự án thể hiện tính đa hình (Polymorphism) ở đâu?

**Trả lời:**
Dự án sử dụng **đa hình runtime** (runtime polymorphism) thông qua **phương thức ảo** (`virtual`) và **con trỏ lớp cha**.

**Ví dụ:** Trong `ShoppingSystem`, danh sách sản phẩm được lưu bằng con trỏ `Product*`:
```cpp
std::vector<std::unique_ptr<Product>> products;  // Con trỏ lớp cha

// Khi gọi display(), C++ tự chọn đúng hàm tùy theo loại sản phẩm
for (const auto& product : products) {
    product->display();       // Gọi PhysicalProduct::display() hoặc DigitalProduct::display()
    product->getShippingFee(); // PhysicalProduct trả phí ship, DigitalProduct trả 0
}
```

Tương tự với `PaymentMethod`:
```cpp
std::unique_ptr<PaymentMethod> paymentMethod;
// Có thể trỏ đến CreditCardPayment hoặc PayPalPayment
paymentMethod->processPayment(amount);  // Gọi đúng hàm tương ứng
```

**Lợi ích:** Không cần dùng if/else để kiểm tra loại sản phẩm, code mở rộng dễ dàng (thêm loại sản phẩm mới chỉ cần tạo class mới kế thừa Product).

### Câu 6: Dự án thể hiện tính trừu tượng (Abstraction) ở đâu?

**Trả lời:**
Dự án có **2 class trừu tượng** (abstract class):

**1. `Product`** — có phương thức ảo thuần túy:
```cpp
virtual void display() const = 0;           // = 0 nghĩa là pure virtual
virtual double getShippingFee() const = 0;
virtual std::string getType() const = 0;
```

**2. `PaymentMethod`** — có phương thức ảo thuần túy:
```cpp
virtual bool processPayment(double amount) const = 0;
virtual std::string getMethodName() const = 0;
```

**Đặc điểm:**
- Không thể tạo đối tượng trực tiếp từ `Product` hay `PaymentMethod` (sẽ lỗi compile).
- Các lớp con **bắt buộc** phải override tất cả các phương thức ảo thuần túy.
- Chúng đóng vai trò như một "hợp đồng" (contract/interface) định nghĩa những gì lớp con phải triển khai.

---

## PHẦN 3: CÂU HỎI VỀ KỸ THUẬT C++

### Câu 7: `const` ở cuối phương thức có nghĩa gì?

**Trả lời:**
`const` ở cuối phương thức nghĩa là phương thức đó **không được phép thay đổi bất kỳ thuộc tính nào** của đối tượng.

```cpp
std::string getName() const;  // Hàm chỉ đọc, không sửa đổi đối tượng
void setQuantity(int q);      // Hàm này sửa đổi đối tượng nên KHÔNG có const
```

**Lợi ích:** Trình biên dịch sẽ báo lỗi nếu trong hàm `const` mà ta vô tình thay đổi thuộc tính → an toàn hơn.

### Câu 8: `virtual` và `override` dùng để làm gì?

**Trả lời:**
- **`virtual`:** Khai báo ở lớp cha, cho phép lớp con ghi đè (override) phương thức này. Khi gọi qua con trỏ/tham chiếu lớp cha, C++ sẽ gọi đúng phiên bản của lớp con (dynamic dispatch).
- **`override`:** Khai báo ở lớp con, thông báo rằng phương thức này đang ghi đè phương thức ảo của lớp cha. Nếu viết sai tên hàm hoặc sai tham số, trình biên dịch sẽ báo lỗi.
- **`= 0`:** Biến phương thức ảo thành **pure virtual**, buộc lớp con phải triển khai.

```cpp
// Lớp cha
virtual void display() const = 0;  // Pure virtual

// Lớp con
void display() const override;     // Override + trình biên dịch kiểm tra
```

### Câu 9: `std::unique_ptr` là gì? Tại sao dùng nó?

**Trả lời:**
`std::unique_ptr` là **smart pointer** (con trỏ thông minh), tự động giải phóng bộ nhớ khi không còn sử dụng.

**Tại sao cần dùng:**
- Khi lưu `Product` vào vector, ta không thể lưu trực tiếp vì `Product` là abstract class.
- Ta phải dùng con trỏ để hỗ trợ đa hình. Nhưng nếu dùng con trỏ thô (`Product*`), ta phải tự `delete` → dễ bị **memory leak**.
- `unique_ptr` tự động `delete` khi ra khỏi scope.

```cpp
// Tạo
std::vector<std::unique_ptr<Product>> products;
products.push_back(std::make_unique<PhysicalProduct>(1, "Laptop", 1500.0, cat, 2.5, 25.0));

// Khi vector bị hủy → unique_ptr tự động delete từng Product → KHÔNG memory leak
```

### Câu 10: `std::make_unique` là gì?

**Trả lời:**
`std::make_unique<T>(args...)` là hàm helper để tạo `unique_ptr`:
- Cấp phát bộ nhớ bằng `new`
- Gói vào `unique_ptr`
- An toàn hơn gọi `new` trực tiếp

```cpp
// Cách dùng make_unique (khuyến khích)
auto p = std::make_unique<PhysicalProduct>(1, "Laptop", 1500.0, cat, 2.5, 25.0);

// Tương đương với (không khuyến khích)
std::unique_ptr<Product> p(new PhysicalProduct(1, "Laptop", 1500.0, cat, 2.5, 25.0));
```

### Câu 11: `virtual ~Product() = default;` có ý nghĩa gì?

**Trả lời:**
Đây là **virtual destructor**. Khi ta `delete` một đối tượng qua con trỏ lớp cha, C++ cần biết gọi destructor của lớp con, không phải lớp cha.

```cpp
Product* p = new PhysicalProduct(...);
delete p;  // Nếu destructor KHÔNG virtual → chỉ gọi ~Product() → memory leak
           // Nếu destructor CÓ virtual → gọi ~PhysicalProduct() rồi ~Product() → đúng
```

**Quy tắc:** Lớp nào có phương thức virtual thì nên có **virtual destructor**.

`= default` nghĩa là dùng destructor mặc định do compiler tạo ra (vì class Product không cần dọn dẹp gì đặc biệt).

### Câu 12: Tại sao `CartItem` và `InventoryItem` dùng con trỏ thô `Product*`?

**Trả lời:**
`CartItem` và `InventoryItem` chỉ **tham chiếu** (trỏ đến) sản phẩm, chúng **không sở hữu** sản phẩm đó. Sản phẩm được sở hữu và quản lý bởi `ShoppingSystem` (thông qua `unique_ptr`).

- `unique_ptr` = **sở hữu** bộ nhớ (chịu trách nhiệm delete)
- Con trỏ thô = **tham chiếu** (chỉ trỏ đến, không delete)

Nếu `CartItem` cũng dùng `unique_ptr` thì khi xóa `CartItem` sẽ xóa luôn sản phẩm → sai logic.

---

## PHẦN 4: CÂU HỎI VỀ DESIGN PATTERN

### Câu 13: Dự án có sử dụng Design Pattern nào không?

**Trả lời:**
Có, dự án áp dụng một số pattern:

**1. Strategy Pattern (PaymentMethod):**
- `PaymentMethod` là interface/strategy chung.
- `CreditCardPayment` và `PayPalPayment` là 2 strategy cụ thể.
- `PaymentProcessor` nhận bất kỳ `PaymentMethod` nào và xử lý → có thể dễ dàng thêm phương thức thanh toán mới.

**2. Composition:**
- `Customer` chứa `Address` (khách hàng "có" địa chỉ).
- `Product` chứa `Category` (sản phẩm "có" danh mục).
- `Order` chứa `Customer`, `ShippingMethod`, `vector<OrderItem>`.

**3. Factory-like (make_unique):**
- Dùng `std::make_unique<PhysicalProduct>(...)` và `std::make_unique<DigitalProduct>(...)` để tạo đối tượng đa hình.

---

## PHẦN 5: CÂU HỎI VỀ LUỒNG HOẠT ĐỘNG

### Câu 14: Mô tả luồng hoạt động khi khách hàng mua hàng?

**Trả lời:**
1. **Xem sản phẩm** (`viewProducts`) → Hiển thị toàn bộ sản phẩm bằng đa hình (`product->display()`).
2. **Thêm vào giỏ** (`addProductToCart`) → Kiểm tra tồn kho (`InventoryItem::isAvailable()`), nếu đủ thì tạo `CartItem`.
3. **Thanh toán** (`checkout` → `CheckoutSession::start()`):
   - Nhập thông tin khách hàng → tạo `Customer` + `Address`
   - Chọn phương thức shipping → tạo `ShippingMethod`
   - Chọn phương thức thanh toán → tạo `CreditCardPayment` hoặc `PayPalPayment` (đa hình)
   - `PaymentProcessor::process()` xử lý thanh toán
   - Nếu thành công: tạo `Order` + `OrderItem`, thêm vào `OrderManager`, xuất `Invoice`
4. **Xóa giỏ hàng** — giỏ hàng được clear sau khi checkout thành công.

### Câu 15: Tại sao dùng `std::vector` mà không dùng mảng thường?

**Trả lời:**
- `std::vector` là mảng **động**, tự động thay đổi kích thước khi thêm/xóa phần tử.
- Mảng thường có kích thước cố định, phải khai báo trước số lượng.
- `vector` cung cấp các hàm tiện lợi: `push_back()`, `erase()`, `size()`, `empty()`, `clear()`.
- `vector` tự quản lý bộ nhớ, không cần `new`/`delete` thủ công.

---

## PHẦN 6: CÂU HỎI NÂNG CAO (PHÒNG THỦ)

### Câu 16: Nếu muốn thêm loại sản phẩm mới (ví dụ SubscriptionProduct), em phải làm gì?

**Trả lời:**
Chỉ cần:
1. Tạo class `SubscriptionProduct` kế thừa từ `Product`.
2. Override 3 phương thức: `display()`, `getShippingFee()`, `getType()`.
3. Thêm sản phẩm vào `seedData()` bằng `make_unique<SubscriptionProduct>(...)`.

**Không cần sửa** `ShoppingSystem`, `CartItem`, `Invoice`,... nhờ đa hình → đây là ưu điểm của OOP (Open/Closed Principle).

### Câu 17: Nếu muốn thêm phương thức thanh toán mới (ví dụ MoMo), em phải làm gì?

**Trả lời:**
1. Tạo class `MoMoPayment` kế thừa từ `PaymentMethod`.
2. Override 2 phương thức: `processPayment()`, `getMethodName()`.
3. Thêm lựa chọn mới trong `CheckoutSession::start()`.

**PaymentProcessor không cần sửa** vì nó nhận `PaymentMethod` (lớp cha) → đa hình xử lý.

### Câu 18: Dự án có bị memory leak không?

**Trả lời:**
**Không**, vì:
- Sản phẩm được quản lý bằng `std::unique_ptr<Product>` → tự giải phóng.
- Payment method trong `CheckoutSession` cũng dùng `std::unique_ptr<PaymentMethod>` → tự giải phóng.
- Các đối tượng khác (`Category`, `Customer`, `Order`,...) được lưu bằng value trong `vector` → tự giải phóng khi `vector` bị hủy.
- `Product` có **virtual destructor** → gọi đúng destructor của lớp con.

### Câu 19: `#pragma once` là gì?

**Trả lời:**
`#pragma once` là chỉ thị tiền xử lý (preprocessor directive), đảm bảo file header chỉ được include **một lần** duy nhất trong quá trình biên dịch, tránh lỗi **multiple definition**.

Tương đương với include guard truyền thống:
```cpp
#ifndef PRODUCT_H
#define PRODUCT_H
// nội dung
#endif
```

Nhưng `#pragma once` ngắn gọn hơn và được hầu hết compiler hiện đại hỗ trợ.

### Câu 20: CMake là gì? Tại sao dùng CMake?

**Trả lời:**
CMake là **hệ thống build** (build system generator), giúp quản lý quá trình biên dịch dự án C++ có nhiều file.

**Tại sao dùng:**
- Dự án có **42 file** (.h và .cpp), nếu biên dịch thủ công bằng `g++` phải liệt kê tất cả file → rất dài và khó quản lý.
- CMake tự động phát hiện dependencies giữa các file.
- CMake hỗ trợ đa nền tảng (Windows, Linux, macOS).

```cmake
cmake_minimum_required(VERSION 3.20)
project(ShoppingSystem VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
add_executable(ShoppingSystem main.cpp Category.cpp Product.cpp ...)
```

### Câu 21: Tại sao dùng C++23?

**Trả lời:**
Em sử dụng C++23 để có thể dùng các tính năng hiện đại của C++ như:
- `std::make_unique` (từ C++14)
- `auto` type deduction
- Range-based for loop
- Smart pointers

Tuy nhiên dự án này không dùng tính năng đặc thù nào chỉ có ở C++23, nên có thể hạ xuống C++14 hoặc C++17 mà vẫn biên dịch được.

### Câu 22: `std::getline` khác `std::cin >>` thế nào?

**Trả lời:**
- `std::cin >>` đọc **một từ** (dừng ở khoảng trắng/enter).
- `std::getline` đọc **cả dòng** (dừng ở enter).

Khi nhập tên "Nguyen Van A":
- `cin >>` chỉ lấy "Nguyen"
- `getline` lấy "Nguyen Van A"

Trong `CheckoutSession`, em dùng `getline` để nhập tên khách hàng, địa chỉ (có thể chứa khoảng trắng).

**Lưu ý:** Sau khi dùng `cin >>`, buffer còn ký tự `\n`, phải dùng `cin.ignore()` trước `getline` để tránh bị bỏ qua input.

### Câu 23: Static method `Invoice::generateInvoice()` và `CheckoutSession::start()` có ý nghĩa gì?

**Trả lời:**
`static` method là phương thức **của class** chứ không phải **của đối tượng**. Gọi trực tiếp qua tên class mà không cần tạo đối tượng:
```cpp
Invoice::generateInvoice(order);       // Không cần: Invoice inv; inv.generateInvoice(order);
CheckoutSession::start(cart, manager); // Không cần: CheckoutSession session; session.start(...);
```

**Lý do dùng static:** `Invoice` và `CheckoutSession` không có thuộc tính riêng, chúng chỉ là "utility class" thực hiện một chức năng cụ thể → không cần tạo đối tượng.
