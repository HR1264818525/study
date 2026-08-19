#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Person
{
private:
    /* data */
public:
    weak_ptr <Person> p;    //使用weak_ptr则count不会计数，weak只拿了控制块地址没有实质对象，
                            //不能用weak调用name ,是空值
    string name;
    Person(string n):name(n)
    {
        cout << "name()"<<endl;
    }
    ~Person() {
    cout << "~name()"<<endl;
    }
};

void c(shared_ptr<Person> p)
{
    shared_ptr <Person> P = p;
    cout<<"p.count:"<<p.use_count()<<endl;
}

int main(int argc, char const *argv[])
{
    // unique_ptr<Person> p4 (new Person("HR"));
    auto p1 = make_shared<Person>("Peter");
    cout<<"p1 use_count:"<<p1.use_count()<< endl;
    auto p2 = make_shared<Person>("MJ");
    cout<<"p2 use_count:"<<p2.use_count()<< endl;
    shared_ptr <Person>p3 = p2;     //拷贝后count++
    cout<<"p2 use_count:"<<p2.use_count()<< endl;
    
    c(p1);      //在c()函数中拷贝p1的count++，出函数后+1重置
    cout<<"p1 use_count:"<<p1.use_count()<< endl;
    
    p1->p = p2;
    p2->p = p1;
    
    cout<<"p1 use_count:"<<p1.use_count()<< endl;
    cout<<"p2 use_count:"<<p2.use_count()<< endl;
    
    return 0;
}
