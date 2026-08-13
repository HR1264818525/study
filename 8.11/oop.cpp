#include<iostream>
#include<string>

using namespace std;


class Cat
{
private:
    string name;
    int *age;
    string color;
public:
    //构造函数：初始化对象成员
    Cat() {
        age = new int(0);
        name = "tom";
        cout<<"~Cat()构造函数\n";

    }
    //析构函数：销毁对象成员
    ~Cat() {
        delete age;
        cout<<"~Cat()析构函数\n";
    }
};

int main(int argc, char const *argv[])
{
    //创建了对象
    //c1函数内的局部变量，栈空间，函数结束时，自动销毁
    Cat *c1 = new Cat();
    delete c1;
    c1 = nullptr;
    Cat c2;
    return 0;
}
