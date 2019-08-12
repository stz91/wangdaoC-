#include <iostream>
#include <memory>

using namespace std;

struct FileDeleter//函数对象
{
    void operator()(FILE *fp)
    {
        if(fp)
        {
            fclose(fp);
            cout << ">> fclose(fp)" << endl;
        }
    }
};

void test0()
{
    unique_ptr<FILE, FileDeleter> up(fopen("test.txt", "a＋"), FileDeleter());

    string msg = "helloworld\n";
    fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test1()
{
    shared_ptr<FILE> sp(fopen("test.tet", "a+"), FileDeleter());
    string msg = "helloworld\n";
    fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main()
{
    // test0();
    test1();
    return 0;
}