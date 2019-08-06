#pragma once

#include <iostream>
//使用模板时,要看到其所有的实现,不能仅仅只是一部分
//
//所以一般情况下,不会将模板分为头文件和实现文件
//
//c++的头文件没有.h的后缀

template<class T>
T add(T x, T y);


#if 0
#include "add.cc"
#endif