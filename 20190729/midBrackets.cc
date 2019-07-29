#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class CharArray
{
public:
    CharArray(int size)
    : _size(size)
    , _data(new char[size]())
    {}

    char &operator[](int idx)
    {
        if(idx < _size && idx >=0)
        {
            return _data[idx];
        }
        else
        {
            static char nullChar = '\0';
            return nullChar;
        }
    }
    int size() const { return strlen(_data); }
    ~CharArray()
    {
        if(_data)
            delete [] _data;
    }
private:
    int _size;
    char *_data;
};

int main(void)
{
    CharArray c1(20);
    const char * pstr = "hello,world";
    int sz = strlen(pstr);
    
}