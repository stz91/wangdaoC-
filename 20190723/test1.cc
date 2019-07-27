#include <iostream>
using std::cout;
using std::endl;

int a = 10;
char * p1;//即使没有显示初始化,系统也会清零

int main(void)
{
    int b = 20;
    char s[] = "helloworld";//文字常量区,不能进行修改
    char * p2;//栈上就不会清零,也就是所谓的野指针
    return 0;
}