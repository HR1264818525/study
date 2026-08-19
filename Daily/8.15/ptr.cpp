//ptr.cpp
//智能指针

#include <memory>
#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    string name;
    Person(string n) :name(n){cout<<"person"<<endl;}
    ~Person() {cout<<"~person()"<<endl;}
};



int main(int argc, char const *argv[])
{
    //共享指针
    auto p1 = make_shared <Person>("Peter");
    cout << p1.use_count()<<endl;
    shared_ptr<Person> p2 = p1;
    cout << p1.use_count()<<endl;
    shared_ptr<Person> p3 = p1;
    cout << p1.use_count()<<endl;


    p2.reset();
    p3.reset();
    cout <<p1.use_count()<<endl;



    /*-------------------------------------------------------------------*/
    //独占指针
    // unique_ptr<Person> p1(new Person("Perter"));
    // cout<<"name:"<<p1->name<<endl;
    // auto p2 = make_unique<Person>("MJ");
    // cout <<p1->name<<"'s girlfriend:"<<p2->name<<endl;

    // unique_ptr<Person> p3 = move(p2);   //p2给p3赋值后自己置空
    // cout<<p3->name<<endl;
    // if (p2 ==nullptr)
    // {
    //     cout << "null"<<endl;
    // }
    
    // Person *p0 = p1.get();  //获得裸指针不能手动析构
    // Person *p0 = p1.release();      //释放所有权，p1则不能再使用，需要手动析构
    // cout<<p0->name<<endl;
    // cout<<p1->name<<endl;

    return 0;
}
