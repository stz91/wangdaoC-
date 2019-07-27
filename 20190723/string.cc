#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class String
{
public:
    String()
        : _pstr(new char[11]{})
    {
        strcpy(_pstr, "helloworld");
    }
    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 1])
    {
        strcpy(this->_pstr, pstr);
    }
#if 0
    String(const String & rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String(const String & rhs)" << endl;
    }
#endif

    //1.不能去掉&, 因为在复制构造时又会触发复制构造,无限递归,采用引用直接使用就避免了这个问题
    //2.不能去掉const关键字, 如果是一个右值,则无法赋值.
    String(const String &rhs)
        : _pstr(new char[strlen(rhs._pstr)]())
    {
        strcpy(_pstr, rhs._pstr);
        cout << "String(const String & rhs)" << endl;
    }

    //=操作符要考虑三种情况的实现
    //1.自复制
    //2.回收左操作数
    //3.进行神拷贝
    String &operator=(const String &rhs)
    {
        if (this != &rhs)//考虑自复制的情况
        {
            delete[] _pstr; //回收左操作数的空间
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
            cout << "String &operator=(const String & rhs)" << endl;
            return *this;
        }
    }
    ~String()
    {
        cout << "~String()" << endl;
        if (_pstr)
            delete[] _pstr;
    }
    void print()
    {
        cout << "print() = ";
        cout << this->_pstr << endl;
    }

private:
    char *_pstr;
};

int main()
{
    String str1;
    str1.print();
    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print(); //String::print(&str2);
    str3.print();

    String str4 = str3;
    str4.print();

    str4.operator=(str3);
    str4.print();

    return 0;
}