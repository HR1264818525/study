#include <iostream>
using namespace std;

//===================== 抽象产品1：手机 =====================
class Phone
{
public:
    virtual void show() = 0;
    virtual ~Phone() {}
};

// 小米手机
class MiPhone : public Phone
{
public:
    void show() override
    {
        cout << "这是小米智能手机" << endl;
    }
};

// 苹果手机
class IPhone : public Phone
{
public:
    void show() override
    {
        cout << "这是苹果iPhone手机" << endl;
    }
};

//===================== 抽象产品2：电脑PC =====================
class PC
{
public:
    virtual void show() = 0;
    virtual ~PC() {}
};

// 小米电脑
class MiPC : public PC
{
public:
    void show() override
    {
        cout << "这是小米笔记本电脑" << endl;
    }
};

// 苹果电脑
class Mac : public PC
{
public:
    void show() override
    {
        cout << "这是苹果Mac电脑" << endl;
    }
};

//===================== 抽象工厂基类 =====================
class AbstractFactory
{
public:
    virtual Phone* createPhone() = 0;
    virtual PC* createPC() = 0;
    virtual ~AbstractFactory() {}
};

//===================== 具体工厂1：小米工厂 =====================
class MiFactory : public AbstractFactory
{
public:
    Phone* createPhone() override
    {
        return new MiPhone();
    }
    PC* createPC() override
    {
        return new MiPC();
    }
};

//===================== 具体工厂2：苹果工厂 =====================
class AppleFactory : public AbstractFactory
{
public:
    Phone* createPhone() override
    {
        return new IPhone();
    }
    PC* createPC() override
    {
        return new Mac();
    }
};

//===================== 客户端测试 =====================
int main()
{
    // 1. 创建小米全套设备
    AbstractFactory* miFac = new MiFactory();
    Phone* miPhone = miFac->createPhone();
    PC* miPc = miFac->createPC();
    miPhone->show();
    miPc->show();

    // 释放内存
    delete miPhone;
    delete miPc;
    delete miFac;

    cout << "--------分割线--------" << endl;

    // 2. 创建苹果全套设备
    AbstractFactory* appleFac = new AppleFactory();
    Phone* iphone = appleFac->createPhone();
    PC* mac = appleFac->createPC();
    iphone->show();
    mac->show();

    delete iphone;
    delete mac;
    delete appleFac;

    return 0;
}
