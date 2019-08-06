#include "log4cpp.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test2()
{
	int number = 10;
	logError("this is error message, %d", 10);
	LogWarn("this is warn message");
	LogInfo("this is info message");
	LogDebug("this is debug message");
}
 
int main(void)
{
	test2();
	wd::Mylogger::destroy();
	return 0;
}