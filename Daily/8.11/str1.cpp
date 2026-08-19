#include<iostream>
#include<cstring>


using namespace std;

int main(int argc, char const *argv[])
{
    string s = "World";
    
    s.insert(0,"Hello");

    //函数写法	功能
    // str.insert(pos, str2)	在 pos 插入完整 str2
    // str.insert(pos, c_str)	在 pos 插入 char * 常量字符串
    // str.insert(pos, n, ch)	在 pos 插入 n 个相同字符 ch
    // str.insert(pos, s2, off, len)	截取 s2 从 off 开始 len 个字符插入
    return 0;
}
