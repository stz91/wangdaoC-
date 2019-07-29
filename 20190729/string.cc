#include <iostream>
#include <string.h>
#include <limits>
#include <stdio.h>
using std::cout;
using std::endl;

class String
{
public:
    String()
        : _sz(1024), _pstr(new char[1024]())
    {
        cout << "String()" << endl;
    }
    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 1]())
    {
        strcpy(_pstr, pstr);
        cout << "String(const char* pstr)" << endl;
    }
    String(const String &rhs)
        : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        strcpy(_pstr, rhs._pstr);
        cout << "String(const String& rhs)" << endl;
    }

    //=的重载
    String &operator=(const String &rhs)
    {
        if (_pstr)
        {
            delete[] _pstr;
        }
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
        return *this;
    }
    String &operator=(const char *pstr)
    {
        if (_pstr)
        {
            delete[] _pstr;
        }
        _pstr = new char[strlen(pstr) + 1]();
        strcpy(_pstr, pstr);
        return *this;
    }
    ~String()
    {
        if (_pstr)
        {
            delete[] _pstr;
        }
        cout << "~String()" << endl;
    }
    void Print()
    {
        cout << _pstr << endl;
    }

    //+=的重载
    String &operator+=(const String &rhs)
    {
        _pstr = (char *)realloc(_pstr, strlen(_pstr) + strlen(rhs._pstr) + 1);
        _pstr = strcat(_pstr, rhs._pstr);
        return *this;
    }
    String &operator+=(const char *pstr)
    {
        _pstr = (char *)realloc(_pstr, strlen(_pstr) + strlen(pstr) + 1);
        _pstr = strcat(_pstr, pstr);
        return *this;
    }

    //[]的重载
    char &operator[](std::size_t index)
    {
        static char szNull = '\0';
        if (index < strlen(_pstr) && index >= 0)
        {
            return _pstr[index];
        }
        else
        {
            cout << "下标越界" << endl;
            return szNull;
        }
    }

    //size()
    std::size_t size() const
    {
        return strlen(_pstr);
    }
    //c_str()
    const char *c_str() const
    {
        return this->_pstr;
    }
    //!=的重载
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);

    //<,>,<=,>=的重载
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);

    //<<, >>的重载
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

    //+的重载
    friend String operator+(const String &, const String &);
    friend String operator+(const String &, const char *);
    friend String operator+(char *, const String &);

private:
    char *_pstr;
    size_t _sz;
};

bool operator==(const String &lhs, const String &rhs)
{
    if (!strcmp(lhs._pstr, rhs._pstr))
    {
        return true;
    }
    else
        return false;
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    int ret = strcmp(lhs._pstr, rhs._pstr);
    if (ret < 0)
        return true;
    else
    {
        return false;
    }
}
bool operator>(const String &lhs, const String &rhs)
{
    int ret = strcmp(lhs._pstr, rhs._pstr);
    if (ret > 0)
        return true;
    else
    {
        return false;
    }
}
bool operator<=(const String &lhs, const String &rhs)
{
    return !(lhs > rhs);
}
bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}
void test0()
{
    String s1("helloworld");
    String s2 = "nihao";
    s1 += s2;
    s2 += "hello";
    s1.Print();
    s2.Print();
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}
void readChar(std::istream &is, char &c)
{
    while (is >> c, !is.eof())
    {
        if (is.bad())
        {
            cout << "istream has corrupted!" << endl;
        }
        else if (is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "pls input a valid value!" << endl;
            continue;
        }
        break;
    }
}
std::istream &operator>>(std::istream &is, String &s)
{
    cout << "pls input a valid string!" << endl;
    int idx = 0;
    is.getline(s._pstr, 1024);
    return is;
}

String operator+(const String &lhs, const String &rhs)
{
    String Str;
    Str._pstr = new char[strlen(lhs._pstr) + strlen(rhs._pstr) + 1];
    Str._pstr = strcat(lhs._pstr, rhs._pstr);
    return Str;
    
}
String operator+(const String &lhs, const char *pstr)
{
    String Str;
    Str._pstr = new char[strlen(lhs._pstr) + strlen(pstr) + 1];
    Str._pstr = strcat(lhs._pstr, pstr);
    return Str;
}
String operator+(char *pstr, const String &rhs)
{
    String Str;
    Str._pstr = new char[strlen(rhs._pstr) + strlen(pstr) + 1];
    Str._pstr = strcat(pstr, rhs._pstr);
    return Str;
}

void test1()
{
    String s1("helloworld");
    String s2 = "nihao";
    String s3 = "nihao";
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s1[2] = " << s1[2] << endl;
    if (s3 == s2)
    {
        cout << "s3 == s2" << endl;
    }
    if (s1 != s2)
    {
        cout << "s1 != s2" << endl;
    }
}

void test2()
{
    String s1("helloworld");
    String s2 = "zello";
    cout << (s1 > s2) << endl;
}

void test3()
{
    String s1("helloworld");
    cout << s1 << endl;
    String s2;
    std::cin >> s2;
    s2.Print();
}

void test4()
{
    String s1("helloworld");
    String s2 = "zello";
    String s3;
    s3 = s1 + s2;
    s3.Print();
}

int main(void)
{
    //test0();
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}