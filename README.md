# Đồ Án: Hệ Thống Mua Sắm (Shopping System)

## Môn học: Lập Trình Hướng Đối Tượng (OOP)
**Ngôn ngữ:** C++ (C++23)  
**Công cụ build:** CMake  

---

## 1. Giới thiệu đề tài

Hệ thống mua sắm (Shopping System) là một ứng dụng console mô phỏng quy trình mua hàng trực tuyến hoàn chỉnh, bao gồm:
- Quản lý danh mục sản phẩm (Category)
- Quản lý sản phẩm vật lý (PhysicalProduct) và sản phẩm số (DigitalProduct)
- Giỏ hàng (Cart) với các thao tác thêm/xóa
- Quản lý tồn kho (Inventory)
- Thanh toán (Payment) qua Credit Card hoặc PayPal
- Xử lý đơn hàng (Order) và xuất hóa đơn (Invoice)

---

## 2. Các tính năng của Lập Trình Hướng Đối Tượng được áp dụng

### 2.1. Tính đóng gói (Encapsulation)
- Tất cả thuộc tính (attribute) của các class đều được khai báo `private`.
- Truy cập thông qua các phương thức getter/setter (`getName()`, `getPrice()`, `setQuantity()`,...).
- **Ví dụ:** Class `Product` có các thuộc tính `id`, `name`, `price`, `category` đều là `private`, chỉ truy cập qua getter.

### 2.2. Tính kế thừa (Inheritance)
- `PhysicalProduct` và `DigitalProduct` kế thừa từ class trừu tượng `Product`.
- `CreditCardPayment` và `PayPalPayment` kế thừa từ class trừu tượng `PaymentMethod`.
- Sử dụng từ khóa `public` trong kế thừa.

### 2.3. Tính đa hình (Polymorphism)
- Các phương thức ảo thuần túy (`pure virtual function`) trong class `Product`:
  - `virtual void display() const = 0;`
  - `virtual double getShippingFee() const = 0;`
  - `virtual std::string getType() const = 0;`
- Các phương thức ảo thuần túy trong class `PaymentMethod`:
  - `virtual bool processPayment(double amount) const = 0;`
  - `virtual std::string getMethodName() const = 0;`
- Các lớp con override lại bằng từ khóa `override`.
- Sử dụng con trỏ `Product*` để gọi phương thức đa hình tại runtime.

### 2.4. Tính trừu tượng (Abstraction)
- `Product` và `PaymentMethod` là các class trừu tượng (abstract class) — không thể tạo đối tượng trực tiếp.
- Chúng định nghĩa giao diện (interface) chung mà các lớp con phải triển khai.

---

## 3. Sơ đồ lớp (Class Diagram)

### 3.1. Danh sách các class

| STT | Class | Vai trò |
|-----|-------|---------|
| 1 | `Category` | Danh mục sản phẩm |
| 2 | `Product` | Lớp trừu tượng đại diện sản phẩm |
| 3 | `PhysicalProduct` | Sản phẩm vật lý (kế thừa Product) |
| 4 | `DigitalProduct` | Sản phẩm số (kế thừa Product) |
| 5 | `InventoryItem` | Quản lý tồn kho cho từng sản phẩm |
| 6 | `CartItem` | Một mục trong giỏ hàng |
| 7 | `Address` | Địa chỉ giao hàng |
| 8 | `Customer` | Thông tin khách hàng |
| 9 | `ShippingMethod` | Phương thức vận chuyển |
| 10 | `PaymentMethod` | Lớp trừu tượng phương thức thanh toán |
| 11 | `CreditCardPayment` | Thanh toán bằng thẻ tín dụng (kế thừa PaymentMethod) |
| 12 | `PayPalPayment` | Thanh toán bằng PayPal (kế thừa PaymentMethod) |
| 13 | `PaymentProcessor` | Xử lý thanh toán |
| 14 | `OrderItem` | Một mục trong đơn hàng |
| 15 | `Order` | Đơn hàng |
| 16 | `OrderManager` | Quản lý danh sách đơn hàng |
| 17 | `Invoice` | Xuất hóa đơn |
| 18 | `CheckoutSession` | Xử lý quy trình thanh toán |
| 19 | `ShoppingSystem` | Lớp chính điều khiển toàn bộ hệ thống |

### 3.2. Quan hệ giữa các class

```
Product (abstract)
├── PhysicalProduct (kế thừa)
└── DigitalProduct (kế thừa)

PaymentMethod (abstract)
├── CreditCardPayment (kế thừa)
└── PayPalPayment (kế thừa)

ShoppingSystem ──has──> Category (1-nhiều)
ShoppingSystem ──has──> Product (1-nhiều, qua unique_ptr)
ShoppingSystem ──has──> InventoryItem (1-nhiều)
ShoppingSystem ──has──> CartItem (1-nhiều)
ShoppingSystem ──has──> OrderManager (1-1)

Product ──has──> Category (1-1, composition)
CartItem ──uses──> Product (con trỏ thô)
InventoryItem ──uses──> Product (con trỏ thô)

Order ──has──> Customer (1-1)
Order ──has──> OrderItem (1-nhiều)
Order ──has──> ShippingMethod (1-1)

Customer ──has──> Address (1-1, composition)

CheckoutSession ──uses──> PaymentProcessor
CheckoutSession ──creates──> Order
CheckoutSession ──creates──> Invoice
```

---

## 4. Chi tiết từng class

### 4.1. Category
- **Thuộc tính:** `id` (int), `name` (string)
- **Chức năng:** Phân loại sản phẩm (Electronics, Books, Courses, Accessories)

### 4.2. Product (Abstract)
- **Thuộc tính:** `id`, `name`, `price`, `category`
- **Phương thức ảo thuần túy:** `display()`, `getShippingFee()`, `getType()`
- **Destructor ảo:** `virtual ~Product() = default;`

### 4.3. PhysicalProduct
- **Thêm thuộc tính:** `weight`, `shippingFee`
- **Phí ship:** `shippingFee + weight * 10`
- **Ví dụ:** Laptop (1500$, 2.5kg), Mouse (25$, 0.2kg)

### 4.4. DigitalProduct
- **Thêm thuộc tính:** `downloadLink`
- **Phí ship:** luôn bằng 0 (sản phẩm số không cần ship)
- **Ví dụ:** C++ E-book (10$), Online C++ Course (50$)

### 4.5. PaymentMethod (Abstract)
- **Phương thức ảo:** `processPayment(amount)`, `getMethodName()`
- **Destructor ảo:** `virtual ~PaymentMethod() = default;`

### 4.6. CreditCardPayment
- **Thuộc tính:** `cardNumber`, `expiryDate`, `cvv`
- **Xử lý:** In 4 số cuối thẻ, giả lập thanh toán thành công

### 4.7. PayPalPayment
- **Thuộc tính:** `email`
- **Xử lý:** In email PayPal, giả lập thanh toán thành công

### 4.8. ShoppingSystem
- **Vai trò:** Class chính điều khiển toàn bộ hệ thống
- **Quản lý:** `unique_ptr<Product>` cho đa hình, vector cho danh sách
- **Menu:** 9 chức năng từ xem sản phẩm đến xem lịch sử đơn hàng

---

## 5. Design Patterns và kỹ thuật nâng cao

| Kỹ thuật | Mô tả | Áp dụng |
|----------|-------|---------|
| Smart Pointer | `std::unique_ptr<Product>` quản lý bộ nhớ tự động | `ShoppingSystem::products` |
| Factory-like | `std::make_unique<>` tạo đối tượng đa hình | `seedData()` |
| Strategy Pattern | Đổi thuật toán thanh toán tại runtime | `PaymentMethod` → `CreditCard`/`PayPal` |
| Composition | Đối tượng chứa đối tượng khác | `Customer` chứa `Address`, `Product` chứa `Category` |

---

## 6. Hướng dẫn Build và Chạy

### Yêu cầu
- Trình biên dịch C++ hỗ trợ C++23 (g++ 13+, clang++ 16+)
- CMake 3.20+

### Các bước

```bash
# Bước 1: Tạo cấu hình CMake
cmake -S . -B build

# Bước 2: Biên dịch
cmake --build build

# Bước 3: Chạy chương trình
./build/ShoppingSystem
```

### Quy trình sử dụng mẫu

1. Bấm `1` — Xem danh sách sản phẩm
2. Bấm `4` — Thêm sản phẩm vào giỏ (nhập ID sản phẩm + số lượng)
3. Bấm `5` — Xem giỏ hàng
4. Bấm `7` — Thanh toán (nhập thông tin khách hàng → địa chỉ → shipping → payment)
5. Bấm `8` — Xem lịch sử đơn hàng

---

## 7. Cấu trúc thư mục

```
shopping-system/
├── CMakeLists.txt            # File cấu hình CMake
├── main.cpp                  # Điểm vào chương trình
├── ShoppingSystem.h/.cpp     # Class chính điều khiển hệ thống
├── Category.h/.cpp           # Danh mục sản phẩm
├── Product.h/.cpp            # Class trừu tượng sản phẩm
├── PhysicalProduct.h/.cpp    # Sản phẩm vật lý
├── DigitalProduct.h/.cpp     # Sản phẩm số
├── InventoryItem.h/.cpp      # Quản lý tồn kho
├── CartItem.h/.cpp           # Mục trong giỏ hàng
├── Address.h/.cpp            # Địa chỉ
├── Customer.h/.cpp           # Khách hàng
├── ShippingMethod.h/.cpp     # Phương thức vận chuyển
├── PaymentMethod.h/.cpp      # Interface thanh toán (abstract)
├── CreditCardPayment.h/.cpp  # Thanh toán thẻ tín dụng
├── PayPalPayment.h/.cpp      # Thanh toán PayPal
├── PaymentProcessor.h/.cpp   # Xử lý thanh toán
├── OrderItem.h/.cpp          # Mục trong đơn hàng
├── Order.h/.cpp              # Đơn hàng
├── OrderManager.h/.cpp       # Quản lý đơn hàng
├── Invoice.h/.cpp            # Xuất hóa đơn
├── CheckoutSession.h/.cpp    # Phiên thanh toán
└── uml-class-diagram.png     # Sơ đồ UML
```