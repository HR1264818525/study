//op.cpp
//继承

#include<iostream>

using namespace std;
//A,B,C
class A
{
private:
    int pri_a;  //所有继承成员全部变成子类 private，不再是 is-a 关系，等价于内部组合复用，几乎不用。

protected:
    int pro_a;  //父类 public 降级为 protected，只能在子类内部、孙子类访问，外部对象无法调用；

    public:
    int pub_a;  //保留父类接口，严格体现 is-a，多态、框架全部用它；
    A():pri_a(0),pro_a(0),pub_a(0) {
        cout<<"A()"<<endl;
    }
    A(int a,int b,int c):pri_a(a),pro_a(b),pub_a(c)
    {
        cout << "A(int,int,int)"<<endl;
    }
    virtual ~A() {
    cout<<"xigouA()"<<endl;
    }
    virtual void show()
    {
        cout<< pri_a<<","<<pro_a<<","<<pub_a<<endl;
    }
    int getpri_a()
    {
        return(pri_a);
    }
};

class B:public A
{
    private:
    int pri_b;
    public:
    B():A(1,2,3){
        cout<<"B()"<<endl;
    }
    B(int a,int b, int c, int d):A(a,b,c),pri_b(d){
        cout<<"B()"<<endl;
    }
    ~B(){
        cout<<"xigouB()"<<endl;
    }
    void show()
    {
        cout<< getpri_a()<<","<<pro_a<<","<<pub_a<<","<<pri_b<<endl;
    }
};

class C:public B
{
    private:
    /* data */
    public:
    C(/* args */) {
        cout<<"C()"<<endl;
    }
    ~C() {
    cout<<"xigouC()"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    // A a;
    // a.show();
    // B b(1,2,3,4);
    // b.show();
    // C c;
    // c.show();

    // A *a;
    // a = new A;
    // a->show();
    // delete a;
    
    // B *b;
    // b = new B;
    // b->show();
    // delete b;
    
    A *a;
    a = new B;
    a->show();
    delete a;
    return 0;
}
