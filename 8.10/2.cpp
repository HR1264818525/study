#include<iostream>

using namespace std;


void swap_ref(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main(int argc, char const *argv[])
{
    int a = 42;
    int b = 64;

    // int *p;
    // p = &a;
    // *p = 43;
    // p = &b;

    // 引用：& 标识 r 是引用，变量的别名
    // 引用声明时必须赋值，不可再次赋值
    int &r = a;

    cout << a << "," <<r << endl;
    r++;
    a++;
    cout << a << "," <<r << endl;
    cout << &a << endl;
    cout << &r << endl;

    swap(a,b);
    cout << a << " " << b;



    return 0;
}
