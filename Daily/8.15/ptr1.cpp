#include <memory>
#include <iostream>
using namespace std;

struct Node
{
    int val;
    weak_ptr<Node> next;

    Node(int val):val(val)
    {
        cout<<"Node()"<<endl;
    }
    ~Node(){
    cout<<"~Node()"<<endl;
}
};


int main(int argc, char const *argv[])
{
    auto n1 = make_shared<Node>(6);
    shared_ptr<Node> n2(new Node(64));
    // cout<<n1.use_count()<<endl;
    // cout<<n2.use_count()<<endl;
    // n1->next = n2;
    // n2->next = n1;
    // cout<<n1.use_count()<<endl;
    // cout<<n2.use_count()<<endl;
    
    weak_ptr n3 = n1;
    
    cout<<n1.use_count()<<endl;

    
    cout<<n3.lock()<<endl;

    return 0;
}
