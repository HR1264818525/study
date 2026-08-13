#include <iostream>
#include <cstring>  // memcpy头文件

using namespace std;

namespace my
{
    int *expand(int *oldarr,int oldlen,int newlen)
    {
        int *newarr = new int[newlen]();
        for (int i = 0; i < oldlen; i++)
        {
            newarr[i] = oldarr[i];
        }
        delete []oldarr;
        return newarr;
    }
    void printarr(int* arr,int len)
    {
        for (int i = 0; i < len; i++)
        {
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }
    void freearr(int *&arr)
    {
        if (arr != nullptr)
        {
            delete []arr;
            arr = nullptr;
        }
        
    }
    void addarr(int *arr,int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = i+1;
        }
        
    }

}

int main()
{
    int len = 5;
    int * array = new int[len]{1,2,3};
    cout<<"扩容前数组:";
    my::printarr(array,len);
    
    int newlen = 10;
    // len = newlen;
    
    array = my::expand(array,len,newlen);
    cout<<"扩容后数组：";
    my::printarr(array,newlen);
    my::freearr(array);
    return 0;
}