#include <iostream>
using namespace std;

// 顶层基类
class A
{
public:
    int num = 10;
    A()
    {
        cout << "A的构造函数执行" << endl;
    }
    void showA()
    {
        cout << "A::num = " << num << endl;
    }
};

// 虚继承A：virtual public
class B : virtual public A
{
};

// 虚继承A：virtual public
class C : virtual public A
{
};

// 子类D继承B、C
class D : public B, public C
{
};

int main()
{
    D d;

    // 无歧义，直接调用，全局只有一份A的成员
    d.showA();
    d.num = 66;
    d.showA();

    return 0;
}
