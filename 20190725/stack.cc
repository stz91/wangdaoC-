#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class student
{
public:
    student(int id, const char* name)
    : _id(id)
    , _name(new char[strlen(name)+1]())
    {   
        cout << "student(int id, char* name)" << endl;
        strcpy(_name,name);
    }
    void * operator new(size_t sz)
    {
        cout << "void operate new(size_t sz)" << endl;
        void *ret = malloc(sz);
        return ret;
    }
    void operator delete(void *p)
    {
        cout << "void operator delete(void *p)" << endl;
        free(p);
    } 
    void print()
    {
        cout << "id: " << _id << endl;
        cout << "name: " << _name << endl;
    }
    void destory()
    {
        cout << "~student()" << endl;
        if(_name)
        {
            delete [] _name;
            _name = nullptr;
        }
    }
private:
    ~student()
    {
        cout << "~student()" << endl;
        if(_name)
        {
            delete [] _name;
            _name = nullptr;
        }
    }
    int _id;
    char *_name;
};

int main()
{   
    student * s1 = new student(1, "xiaoming");
    s1->print();
    s1->destory();
    // delete s1;
    return 0;
}