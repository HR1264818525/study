# C++ 每日一讲：拷贝构造 和 移动构造（移动语义）
## 分享前言
课堂上我们简单接触过构造函数，但当类中管理**堆内存、大缓冲区**时，编译器默认生成的拷贝逻辑会产生严重问题：内存重复释放、性能暴跌。
今天我们对比 **拷贝构造（深拷贝）** 和 **移动构造（移动语义）**，理解现代 C++ 如何解决大数据拷贝开销问题，这也是音视频、游戏开发高频使用的特性。

> 背景约定：
> - 左值：有名字、生命周期较长，可以取地址的变量
> - 右值：临时匿名对象、表达式返回值，用完马上销毁，不能持久使用

## 一、为什么我们需要手动实现拷贝/移动构造？
如果类内部持有堆内存指针（char*、数组、缓冲区）：
编译器默认拷贝构造 = **浅拷贝**
> 浅拷贝：仅仅复制指针地址，多个对象共用同一块堆内存
> ❌ 致命问题：多个对象析构时，会对同一块内存执行多次 delete，程序直接崩溃！

解决方案二选一：
1. **拷贝构造（深拷贝）**：开辟全新内存，完整复制数据，各自独立
2. **移动构造**：不复制内存，直接转移堆内存所有权（零拷贝，高性能）

## 二、核心代码实现
### BigBuffer 缓冲区类完整代码
这个类模拟音视频开发里常见的**大块数据缓冲区**（存储视频原始帧数据）
```cpp
#include <iostream>
#include <cstring>

class BigBuffer {
public:
    char* data;     // 指向堆上的大块缓冲区
    size_t len;     // 缓冲区字节长度

    // 普通构造：分配堆内存
    BigBuffer(size_t sz) : len(sz) {
        data = new char[sz];
        std::cout << "【普通构造】分配内存：" << len << " bytes\n";
    }

    // ===================== 拷贝构造函数（深拷贝）=====================
    // const BigBuffer& other：接收【左值】，const保证不修改原对象
    BigBuffer(const BigBuffer& other) : len(other.len) {
        // 1. 自己开辟一块全新堆内存
        data = new char[len];
        // 2. 将源对象内存完整复制过来
        memcpy(data, other.data, len);
        std::cout << "【拷贝构造】深拷贝，完整复制内存：" << len << " bytes\n";
    }

    // ===================== 移动构造函数（移动语义）=====================
    // BigBuffer&& other：【右值引用】，只接收临时对象
    // noexcept：告诉编译器该函数不会抛出异常，开启更多优化
    BigBuffer(BigBuffer&& other) noexcept {
        // 1. 直接接管源对象的指针，不分配新内存、不复制数据
        data = other.data;
        len = other.len;
        // 2. 源对象置空！至关重要：防止源对象析构释放已经转移走的内存
        other.data = nullptr;
        other.len = 0;
        std::cout << "【移动构造】转移指针，0内存拷贝\n";
    }

    // 析构函数：释放堆内存
    ~BigBuffer() {
        if (data != nullptr) {
            delete[] data;
            std::cout << "【析构】释放堆内存\n";
        } else {
            std::cout << "【析构】空对象，无需释放内存\n";
        }
    }
};

// 辅助函数：返回临时右值对象，用于触发移动构造
BigBuffer createTempBuffer(size_t size) {
    return BigBuffer(size);
}

int main() {
    std::cout << "======== 测试1：触发拷贝构造 ========\n";
    BigBuffer buf1(1024);
    BigBuffer buf2 = buf1; // buf1是有名左值，调用拷贝构造

    std::cout << "\n======== 测试2：触发移动构造 ========\n";
    BigBuffer buf3 = createTempBuffer(2048); // 返回临时右值，调用移动构造

    return 0;
}
