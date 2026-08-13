#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // 容器，模板类型
    // vector<int>v1;
    // vector<int>v2(10);
    // vector<int>v3(10,1);
    // vector<int>v4{10,1};

    // cout<<v1.size()<<endl;
    // cout<<v2.size()<<endl;
    // cout<<v3.size()<<endl;
    // cout<<v4.size()<<endl;
    
    // //尾部添加元素
    // vector<int> v;

    // //分配空间
    // //v.reserve(17);
    // for (int i = 0; i < 17; i++)
    // {
    //     v.push_back(i);
    //     cout<<v.size()<< "\t"<< v.capacity()<<endl;
    // }
    
    
    // //尾部删除元素
    // v.pop_back(); // 删除最后一个 3

    // //指定位置插入
    // // 在下标1的位置插入 2
    // v.insert(v.begin()+1, 2);
    // // 结果：1,2,3,4
    
    // //指定位置删除
    // v.erase(v.begin()+2); // 删除下标2的3
    // // 结果：1,2,4

    vector<int> v = {10,20,30,40};

    // 定义迭代器 it
    vector<int>::iterator it;

    // 从 begin 开始循环，直到不等于 end
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " "; // *it 取出迭代器指向的元素
    }
    return 0;
}
