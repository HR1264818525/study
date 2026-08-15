#include<iostream>

using namespace std;

template <typename T>
class Box
{
private:
    T data;

public:
    Box(T val):data(val){};
    void show(){
        cout<<data<<endl;
    }
    void set(T x)
    {
        data = x;
    }
};

template<typename T>
void Box<T>::show()
{
    cout<<data<<endl;   
}
int main(int argc, char const *argv[])
{
    Box x1(12);
    Box x2("HR");
    x1.show();
    x1.set(2);
    x1.show();
    x2.show();
    return 0;
}
