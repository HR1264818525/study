#include<iostream>
#include<string>

using namespace std;

class Cat
{
private:
    string name;
    int age;
public:
    Cat();
    Cat(string name,int age);
    ~Cat();

    string getname(string name);
    int getAge(int age);
};

