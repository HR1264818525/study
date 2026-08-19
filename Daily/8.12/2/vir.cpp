// virtual

#include <iostream>

using namespace std;

// 抽象类：包含至少有一个纯虚函数的类，不能实例化，用来继承派生子类
class Shape
{
private:
    /* data */
protected:
    string name;
    int a;
    int b;
public:
    Shape():name("图形"),a(a),b(b)
    {
        cout<<"Shape()"<<endl;
    }
    virtual ~Shape()
    {
        cout<<"xxShape()"<<endl;
    }
    virtual double area() = 0;
    void show()
    {
        cout<< "图形的名称："<<name<<endl;
    }
};


class Circle : public Shape
{
private:
    int r;
    double area;
public:
    Circle()
    {
        r = 3;
        name = "圆形";
        cout<<"Cilrcle()"<<endl;
    }
    ~Circle()
    {
        cout<<"xxCircle()"<<endl;
    }
    double area() override
    {
        area = r*r*3.14;
        return area;
    }
};

int main(int argc, char const *argv[])
{
    // Circle c1;
    c1.show();
    return 0;
}
