#include <iostream>
#include <string>

using namespace std;

class Gas;
class Brand;

class Gas
{
private:
public:
    virtual ~Gas()= default;
    virtual void refurl() = 0;
};

class Electric
{
private:
    /* data */
public:
    virtual ~Electric() = default;
    virtual void charge() = 0;
};

class Car
{
private:
    /* data */
public:
    Car(/* args */) {}
    ~Car() {}
};

class Moto
{
private:
    /* data */
public:
    Moto(/* args */) {}
    ~Moto() {}
};

class GasCar:public Car,public Gas
{
private:
    /* data */
public:
    GasCar(/* args */) {}
    ~GasCar() {}
};
int main(int argc, char const *argv[])
{

    return 0;
}
