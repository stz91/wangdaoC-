#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
    void * voidPint = malloc(sizeof(int));
    int * intPint = static_cast<int*>(voidPint);
    *intPint = 1;

    //float * floatPint = static_cast<float*>(intPint);
    //不同类型的指针不能强制转换
}