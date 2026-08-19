#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 前置声明，解决循环依赖
class Brand;

// 基类（用来练继承+多态）
class BaseGoods
{
protected:
    int id;
    string name;
    double price;
public:
    BaseGoods(int i, string n, double p) : id(i), name(n), price(p) {}

    // 虚函数，实现多态
    virtual void show()
    {
        cout << "通用产品：" << name << " 价格：" << price << endl;
    }

    double getPrice() { return price; }
};

// 商品类：继承 BaseGoods（is-a），组合引用 Brand
class Product : public BaseGoods
{
private:
    Brand* brand; // 指针关联所属品牌，组合关系
public:
    // 子类构造：初始化父类 + 品牌指针
    Product(int i, string n, double p, Brand* b)
        : BaseGoods(i, n, p), brand(b) {}

    // 重写虚函数，多态
    void show() override
    {
        cout << "具体商品：" << name << " 售价：" << price << endl;
    }
};

// 品牌类：内部 vector<Product> 组合多个商品（核心 has-a）
class Brand
{
private:
    int id;
    string name;
    vector<Product> productList; // 组合：品牌包含一堆商品
public:
    Brand(int bid, string bname) : id(bid), name(bname) {}

    // 给品牌添加商品
    void addProduct(Product p)
    {
        productList.push_back(p);
    }

    void showAllProducts()
    {
        cout << "\n===== 品牌：" << name << " =====" << endl;
        for (auto& item : productList)
        {
            item.show(); // 多态调用子类重写的show
        }
    }
};

class Customer
{
private:
    vector<Order*>Orderlist;
public:
    Customer(/* args */) {}
    ~Customer() {}
};

class Item
{
private:
    /* data */
public:
    Product *p;
    int num;
    int price;


    Item(Product *p,int num,int price): p(p),num(num),price(price){}
    ~Item() {}
};

class Order
{
private:
    /* data */
public:
    Customer customer;
    vector<Item>itemlist;       //组合
    Order(/* args */) {}
    ~Order() {}
    void addItem(Item &item)
    {
        itemlist.push_back(item);
    }
    // void addItem(string p,int price,int num)
    // {
    //     itemlist.push_back(Item(p,price,num));
    // }
    void showOrder()
    {
        cout<<"========订单详细========="<<endl;
        int totalMoney = 0;
        for(auto &oneItem:itemlist)
        {
        // oneItem.p 就是Product商品指针，可以调用商品show()
            cout << "【商品信息】";
            oneItem.p->show();

            int subTotal = oneItem.price * oneItem.num;
            cout << "购买数量：" << oneItem.num
                 << "  单项金额：" << subTotal << endl;
            cout << "----------------------------" << endl;

            totalMoney += subTotal;
        }
    }
};



// 测试主函数
int main()
{
    // 1. 创建品牌对象
    Brand huawei(1, "华为");

    // 2. 创建商品，绑定品牌地址
    Product p1(101, "Mate70", 5999, &huawei);
    Product p2(102, "Watch", 1299, &huawei);

    // 3. 品牌组合装入商品
    huawei.addProduct(p1);
    huawei.addProduct(p2);

    // 4. 打印品牌下所有商品
    huawei.showAllProducts();

    // 单独多态演示
    BaseGoods* g = &p1;
    g->show();

    Item i1(&p1,2,5999+5999);
    Item i2(&p2,2,1299*2);
    Order o1;
    o1.addItem(i1);
    o1.addItem(i2);

    o1.showOrder();
    return 0;
}
