#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Person
{
private:
    /* data */
public:
    string name;
    Person(string n):name(n)
    {
        cout << "name()"<<endl;
    }
    ~Person() {
    cout << "name()"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    auto P1 = make_unique<Person>("Peter");
    unique_ptr<Person> P2(new Person("MJ"));
    cout<<P1->name<<endl;
    cout<<P2->name<<endl;
    
    // unique_ptr<Person> P3 = P2;  错误使用禁止拷贝

    unique_ptr<Person> P4 = move(P1);//move把P1转为右值，调用移动构造

    if (P1 ==nullptr)
    {
        cout<<"P1为空"<<endl;
    }
    cout<<"P4name:"<<P4->name<<endl;

    // -------- release()：释放管理权，返回裸指针，**不会调用析构！**
    Person *raw = P2.release();     //P2 release后堆对象交个指针raw
    cout<<"raw name:"<<raw->name<<endl;
    delete raw; //裸指针必须手动释放

    // -------- reset()：释放当前管理的对象，可以接管新对象
    unique_ptr<Person> p (new Person("Nade"));
    p.reset();      //不传参数：直接释放Alice，p变为空
    p.reset(new Person("Mei"));
    cout<<"p reset更新后："<<p->name<<endl;
    return 0;
}
