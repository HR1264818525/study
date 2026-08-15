//工厂模式

// #include<iostream>

// using namespace std;

// class Doc
// {
// protected:
//     string name;
    
// public:
//     Doc(string name):name(name) {}
//     ~Doc() {}
//     void open()
//     {
//         cout<<"OPEN:"<<name<<endl;
//     }
//     virtual void edit() = 0;
// };

// class Word:public Doc
// {
// private:
// public:
//     Word():Doc("未命名") {

//     }
//     void edit() override
//     {
//         cout<<"EDIT Word:"<<name<<endl;
//     }
// };

// class WPS:public Doc
// {
// private:
//     /* data */
// public:
//     WPS():Doc("未命名"){

//     }
//     void edit()
//     {
//         cout<<"EDIT Word:"<<name<<endl;
//     }
// };

// class factory
// {
// private:
    
// public:
//     factory() {}
//     ~factory() {}
//     static Doc *create()
//     {

//     }
// };

// int main(int argc, char const *argv[])
// {
    
//     return 0;
// }

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 抽象产品：文档基类
class Document
{
public:
    virtual ~Document() = default;
    virtual void create() = 0;
    virtual void save() = 0;
};

// 具体产品1：Word文档
class WordDoc : public Document
{
public:
    void create() override
    {
        cout << "新建 Word 空白文档" << endl;
    }
    void save() override
    {
        cout << "保存为 .docx 文件" << endl;
    }
};

// 具体产品2：PDF文档
class PdfDoc : public Document
{
public:
    void create() override
    {
        cout << "新建 PDF 文档" << endl;
    }
    void save() override
    {
        cout << "保存为 .pdf 文件" << endl;
    }
};

// 唯一简单工厂
class DocFactory
{
public:
    static unique_ptr<Document> createDoc(const string& type)
    {
        if (type == "word")
        {
            return make_unique<WordDoc>();
        }
        else if (type == "pdf")
        {
            return make_unique<PdfDoc>();
        }
        else
        {
            cout << "不支持该文档类型" << endl;
            return nullptr;
        }
    }
};

// 客户端调用
int main()
{
    auto d1 = DocFactory::createDoc("word");
    if (d1)
    {
        d1->create();
        d1->save();
    }

    auto d2 = DocFactory::createDoc("pdf");
    if (d2)
    {
        d2->create();
        d2->save();
    }

    return 0;
}
