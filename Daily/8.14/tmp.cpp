//模板编程
//函数模板
//类模板

#include<iostream>

using namespace std;

template<typename T>
T getMax(T a, T b)
{
    // 三目运算符：判断大小并返回较大值
    return (a > b) ? a : b;
}

template<typename C>
void change(C &a,C &b)
{
    auto temp = a;
    a = b;
    b = temp;
}


template<typename t1,typename t2>
void printTwo(t1 val1,t2 val2)
{

}

int main(int argc, char const *argv[])
{
    cout << getMax(12, 36) << endl;

    // 编译器推导 T = double，实例化 double getMax(double a,double b)
    cout << getMax(3.14, 2.71) << endl;

    // 编译器推导 T = string，调用string自身的>运算符比较字符串字典序
    cout << getMax(string("apple"), string("banana")) << endl;
    int x = 2,y = 1;
    change(x,y);
    cout <<x<<","<<y <<endl;
    return 0;
}
