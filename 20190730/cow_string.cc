#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class cowString
{
    //设计模式之代理模式
    class charProxy
    {
    public:
        charProxy(cowString &self, int idx)
            : _self(self), _idx(idx)
        {
            cout << "charProxy(cowString & self, int idx)" << endl;
        }
        charProxy &operator=(const char &ch)
        {
            if (_idx < _self.size() && _idx >= 0)
            {
                if (_self.refCount() > 1)
                {
                    _self.decreaseRefCount();
                    char *ptmp = new char(_self.size() + 5) + 4;
                    strcpy(ptmp, _self._pstr);
                    _self._pstr = ptmp;
                    _self.initRefCount();
                }
                _self._pstr[_idx] = ch;
            }
            return *this;
        }
        operator char()
        {
            return _self._pstr[_idx];
        }
        //friend std::ostream &operator<<(std::ostream os, const charProxy &rhs);

    private:
        cowString &_self;
        int _idx;
    };

public:
    //friend std::ostream &operator<<(std::ostream os, const charProxy &rhs);
    cowString()
        : _pstr(new char[1 + 4]() + 4)
    {
        initRefCount();
        cout << "cowString()" << endl;
    }
    cowString(const char *pstr)
        : _pstr(new char[1 + 4]() + 4)
    {
        initRefCount();
        strcpy(_pstr, pstr);
        cout << "cowString(const char* pstr)" << endl;
    }
    cowString(const cowString &rhs)
        : _pstr(rhs._pstr)
    {
        increaseRefCount();
        cout << "cowString(const cowString &rhs)" << endl;
    }
    cowString &operator=(const cowString &rhs)
    {
        cout << "cowString &operator=(const cowString &rhs)" << endl;
        if (this != &rhs)
        {
            decreaseRefCount();
            if (0 == refCount())
            {
                delete[](_pstr - 4);
            }
            _pstr = rhs._pstr;
            increaseRefCount();
        }
        return *this;
    }

    charProxy &operator[](int idx)
    {
        if (idx < strlen(_pstr) && idx >= 0)
        {
            if (refCount() > 1)
            {
                decreaseRefCount();
                char *ptmp = new char(size() + 5) + 4;
                strcpy(ptmp, _pstr);
                _pstr = ptmp;
                initRefCount();
            }
        }
    }
#if 1
    const charProxy &operator[](int idx) const
    {
        cout << "const char & operator[](int idx) const" << endl;
    }
#endif
    ~cowString()
    {
        cout << "~cowString()" << endl;
        decreaseRefCount();
        if (0 == refCount())
        {
            delete[](_pstr - 4);
        }
    }
    void Print()
    {
        cout << _pstr << endl;
    }

    const char *c_str() const
    {
        return _pstr;
    }

    int size() const
    {
        return strlen(_pstr);
    }
    int refCount()
    {
        return *(int *)(_pstr - 4);
    }

private:
    void initRefCount()
    {
        *(int *)(_pstr - 4) = 1;
    }
    void increaseRefCount()
    {
        ++*(int *)(_pstr - 4);
    }
    void decreaseRefCount()
    {
        --*(int *)(_pstr - 4);
    }
    char *_pstr;
};
std::ostream &operator<<(std::ostream os, const cowString &rhs);
std::ostream &operator<<(std::ostream os, const cowString::charProxy &rhs)
{
    os << rhs._self._pstr[rhs._idx];
    return os;
}
void test0()
{
    cowString c1 = "helloworld";
    cowString c2 = c1;
    printf("%p\n", c1.c_str());
    printf("%p\n", c2.c_str());
    cout << "c1.size = " << c1.size() << endl;
    cout << "c2.size = " << c2.size() << endl;
    cout << "c1.refcount = " << c1.refCount() << endl;
    cout << "c2.refcount = " << c2.refCount() << endl;
    c2.Print();
    c1.Print();

    cowString c3;
    c3 = c1;
    c3.Print();
    printf("%p\n", c3.c_str());
    cout << "执行赋值操作之后" << endl;
    c3[0] = 'x';
    cout << "c3[0] = " << c3[0] << endl;
    c3.Print();
    printf("%p\n", c3.c_str());
}

int main()
{
    test0();
    return 0;
}