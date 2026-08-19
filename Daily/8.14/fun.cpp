#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {54,23,66,5,8};
    sort(v.begin(),v.end(),[](int a,int b){return a>b;});

    for_each(v.begin(),v.end(),[](int e){cout<<e<<endl;});

    auto it = find_if(v.begin(),v.end(),[](int a){return a<9;});




    /*-----------------------------------------------------------------------------*/
    // int n = 9;
    // auto f = [=](int m)
    // {
    //     cout<<m<<endl;
    //     cout<<n<<endl;
    // };

    
    // auto z = [=](int x,int y)
    // {
    //     return x+y;
    // };

    // cout<<z(8,9)<<endl;

    

    //1. **`[]` 捕获列表**：空 `[]`，代表不捕获任何外部局部变量，只能访问全局 / 静态变量。
    //2. **`()` 参数列表**：没有形参，调用时不需要传参。
    //3. **`{}` 函数体**：当前是空函数体。
    //4. **返回值**：没有 return，编译器推导返回类型为 `void`。
    //5. **`auto f`**：把这个匿名可调用对象（闭包）存到变量`f`；**每个 lambda 都是
    //独有的匿名类型，不能直接手写类型，只能 auto 或者 std::function**。
    return 0;
}
