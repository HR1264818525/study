#include <iostream>
#include <string>

using namespace std;

class Brand
{
protected:
    // double price;
public:
    int id;
    string name;
    Brand(int id, string name) : id(id), name(name)
    {
    }
    ~Brand() {}
};

class Product
{
private:
    string name;
    double price;
    Brand *brand;

public:
    Product(string name, double price, Brand *brand) : name(name), price(price), brand(brand)
    {
    }
    ~Product() {}
    void showProducts()
    {
        cout << "产品：" << name << " ,品牌：" << brand->name << ",价格：" << price << endl;
    }
};

int main(int argc, char const *argv[])
{
    Brand b1(1,"HuaWei");
    Brand b2(2,"iPhone");

    Product p1("手机",1999,&b1);
    Product p2("手表",200,&b1);
    Product p3("手机",8848,&b2);
    p3.showProducts();
    p2.showProducts();
    p1.showProducts();
    return 0;
}
