#pragma once

#include <log4cpp/Category.hh>
#include <string>
#include <sstream>

using namespace log4cpp;

namespace wd
{

class Mylogger
{
public:
	static Mylogger * getInstance();
	static void destroy();

	template <class... Args>
    void error(Args... args);
	
	void warn(const char * msg);
	void info(const char * msg);
	void debug(const char * msg);

private:
	Mylogger();
	~Mylogger();

private:
	static Mylogger * _pInstance;
	Category & _mycategory;
};

#define prefix(msg)	string("[").append(__FILE__)\
		.append(":").append(__FUNCTION__)\
		.append(":").append(std::to_string(__LINE__))\
		.append("] ").append(msg)

#define logError(msg, ...) wd::Mylogger::getInstance()->error(prefix(msg), ##__VA_ARGS__)
#define LogWarn(msg) wd::Mylogger::getInstance()->warn(prefix(msg).c_str())
#define LogInfo(msg) wd::Mylogger::getInstance()->info(prefix(msg).c_str())
#define LogDebug(msg) wd::Mylogger::getInstance()->debug(prefix(msg).c_str())

}//end of namespace wd
