#include<iostream>
#include<memory>
#include<string>

using namespace std;

struct Data
{
    unique_ptr<int> ptr;
};

int main(int argc, char const *argv[])
{
    Data d1;
    d1.ptr = make_unique<int>(100);
    // Data d2 = d1;
    Data d2 = move(d1);
    return 0;
}
