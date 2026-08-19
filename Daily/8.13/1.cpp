// 单例模式
#include <iostream>
using namespace std;

class Singleton
{
private:
    Singleton() {
        cout<<"构造函数"<<endl;
    }      //构造函数私有化

public:
    ~Singleton() {}

    //饿汉式:声明类变量，未创建
    static Singleton instance;

    //开放一个静态接口
    static Singleton *getinstance()
    {
        //懒汉式：第一次调用才创建对象，分配空间
        static Singleton instance;
        return &instance;
    }
};

//类变量的初始化
// Singleton Singleton::instance;


int main(int argc, char const *argv[])
{
    Singleton *s1 = Singleton::getinstance();
    Singleton *s2 = Singleton::getinstance();
    Singleton *s3 = Singleton::getinstance();
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    return 0;
}
