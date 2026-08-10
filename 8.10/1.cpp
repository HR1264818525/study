#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // cout << "hello C++\n";

    // int a ;
    // int b ;
    // cin >> a >> b;
    // cout << "数值a:" << a << ",数值b:" << b << endl;
    // cout << "a+b=" << a + b << endl;
    
    int val = 0;
    int sum = 0;
    while (cin>> val)
    {
        sum += val;
    }
    cout << "sum = " << sum <<endl;


}


