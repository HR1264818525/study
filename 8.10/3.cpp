// 3
#include<iostream>

using namespace std;

// namespace a
// {
//     int a{9};
//     void hello()
//     {
//         cout<<"Hello A\n";
//     }
// }

int main(int argc, char const *argv[])
{
    //动态内存管理

   // 1. 分配int堆内存，默认随机值
    int* p1 = new int;
    // 2. 分配并直接初始化为10
    int* p2 = new int(10);

    cout << *p1 << endl;
    cout << *p2 << endl; // 输出10
    
    // 释放单个对象
    delete p1;
    cout << p1 << " " << *p1 << endl;
    delete p2;
    p1 = nullptr; // 置空，防止野指针
    cout << p1 << endl;
    p2 = nullptr;






    
    // 分配10个int数组，未初始化默认随机值
    int* arr1 = new int[10];

    // C++11列表初始化，剩余元素自动补0
    int* arr2 = new int[5]{1,2,3};

    int newsize = 10;
    int * newArr = new int[newsize]{};
    for (int i = 0; i < 5; i++)
    {
        newArr[i] = arr2[i];
    }
    
    delete []arr2;
    arr2 =nullptr; 
    arr2 = newArr;

    // 遍历访问
    for(int i=0; i<newsize; i++)
    {
        cout << arr2[i] << " ";
    }

    // 数组释放必须加 []
    delete[] arr1;
    delete[] arr2;
    arr1 = nullptr;
    arr2 = nullptr;
    
    //方法二 需要加入#include<cstring>

    // // 1. 开辟更大空间：扩容到10个int
    // int new_len = 10;
    // int* new_arr = new int[new_len]{};

    // // 2. memcpy拷贝内存
    // // 拷贝字节数 = 元素个数 × 单个int大小 sizeof(int)
    // memcpy(new_arr, arr2, 5 * sizeof(int));

    // // 释放旧数组
    // delete[] arr2;
    // arr2 = nullptr;

    // // 指针指向新数组，扩容完成
    // arr2 = new_arr;

    // // 遍历验证
    // for(int i=0; i<new_len; i++)
    // {
    //     cout << arr2[i] << " ";
    // }

    // // 释放最终内存
    // delete[] arr2;
    // arr2 = nullptr;

    return 0;
}
