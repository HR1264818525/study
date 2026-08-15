#include<iostream>

#include <vector>      // 动态数组
#include <list>        // 双向链表
#include <deque>       // 双端队列
#include <array>       // 固定数组
#include <forward_list> // 单向链表

#include<set>
#include<map>
//1. **根节点必须是黑色**
//2. **所有叶子 (NIL 哨兵) 都是黑色**
//3. 如果一个节点是红色，则它的两个子节点都必须是黑色（**不能出现连续两个红节点**）
//4. 从**任意一个节点出发，到它所有后代叶子的每一条路径，黑色节点数量完全相等** → 黑高相同
//5. 每个新插入节点默认是**红色**
//
//> 
//> 重点理解规则 3：不能红红相连。这是插入时最常破坏的约束。

#include <unordered_map>
#include <unordered_set>


//无序关联容器
using namespace std;

int main(int argc, char const *argv[])
{






/*----------------------------------------------------------------*/
/*----------------------------------------------------------------*/

//    multimap<int, string> m;


// m.insert({3, "three"});
// m.insert({2, "two"});
// m.insert({1, "one"});

// for (auto &x : m) {
    //     cout << x.first << " " << x.second << endl;
    // }
    
    // m.erase(2);
    
    // cout << "after erase: " << endl;
    // for (auto &x : m) {
        //     cout << x.first << " " << x.second << endl;
        // }
        // set<int> s;
        // s.insert(42);
        // s.insert(7);
        // s.insert(32);
        // s.insert(4);
        // s.insert(55);
        
        // for(auto &&i:s)
        // {
            //     cout<<i<<endl;
            // }
            
/*----------------------------------------------------------------*/

// vector<int> v = {10,20,30};

// // 完整写法：定义vector<int>类型的正向迭代器it
// // iterator是vector内部嵌套的迭代器类，由泛型模板实例化而来
// vector<int>::iterator it;

// // 循环：it从起始位置begin开始，不等于末尾哨兵end就循环
// for (it = v.begin(); it != v.end(); ++it)
// {
    //     // *it 迭代器重载解引用运算符，取出指向的元素值
    //     cout << *it << " ";
    // }
    // cout << endl;
    
    // // C++11 auto自动推导迭代器类型，简化代码（项目推荐）
    // for (auto iter = v.begin(); iter != v.end(); ++iter)
    // {
        //     cout << *iter << " ";
        // }
        
/*----------------------------------------------------------------*/
        // list<int> l = {1, 2, 3};
        
        // l.push_front(0);
        // l.push_back(4);
        
        // for (int x : l) {
            //     cout << x << " ";
            // }
            // cout << endl;
            
            // cout << "front = " << l.front() << endl;
            // cout << "back = " << l.back() << endl;
            
            
            // l.insert(l.begin(),100);
            
            // l.pop_front();
            // l.pop_back();
            
            // for (auto &&i : l) {
                //     cout << i << " ";
                // }
                // cout << endl;
                
                // deque<int> d;
                // deque<int> d2(5,10);
                // deque<int> d3 = {1,2,3};
                
                // d.push_back(1);
                // d.push_front(1);
                // d.pop_back();
                // d.pop_front();
                
                // d.at(2);
                
                
                
                return 0;
            }
            