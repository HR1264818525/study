#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    // 1. 空字符串
    string s1;
    // 2. 直接赋值
    string s2 = "hello c++";
    // 3. 重复n个字符
    string s3(5, 'a'); // "aaaaa"
    // 4. 从C字符串转换
    char arr[] = "test";
    string s4(arr);


    // cout << "请输入一句话（可带空格）：";
    // getline(cin, s1);
    // cout << "你输入的内容：" << s1 << endl;
    
    // while (getline(cin,s1))
    // {
    //     if (s1.empty())
    //     {
    //         break;
    //     }
    //     auto len = s1.size();
    //     cout<< s1<<",size:"<<len<<endl;
    //     // cout<<"请输入你的内容"<<s1<<endl;
        
    // }
    
    
    string s = "I ";
    string sub = "love code";
    s.append(sub);
    // s = "I love code"
    
    cout << s << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    return 0;
}
