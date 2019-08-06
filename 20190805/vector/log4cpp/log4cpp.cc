#include "log4cpp.h"

#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Mylogger *Mylogger::_pInstance = nullptr;

Mylogger *Mylogger::getInstance()
{
	if (_pInstance == nullptr)
		_pInstance = new Mylogger();
	return _pInstance;
}

void Mylogger::destroy()
{
	if (_pInstance)
		delete _pInstance;
}

Mylogger::Mylogger()
	: _mycategory(Category::getRoot().getInstance("mycategory"))
{
	PatternLayout *pLayout1 = new PatternLayout();
	pLayout1->setConversionPattern("%d [%p] %m%n");

	PatternLayout *pLayout2 = new PatternLayout();
	pLayout2->setConversionPattern("%d [%p] %m%n");

	OstreamAppender *pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
	pOstreamAppender->setLayout(pLayout1);

	FileAppender *pFileAppender = new FileAppender("fileAppender", "wangdao.log");
	pFileAppender->setLayout(pLayout2);

	_mycategory.addAppender(pOstreamAppender);
	_mycategory.addAppender(pFileAppender);
	_mycategory.setPriority(Priority::DEBUG);

	cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger()
{
	Category::shutdown();
	cout << "~Mylogger()" << endl;
}

template <class... Args>
void Mylogger::error(Args... args)
{
	_mycategory.error(args...);
}
void Mylogger::warn(const char *msg)
{
	_mycategory.warn(msg);
}

void Mylogger::info(const char *msg)
{
	_mycategory.info(msg);
}

void Mylogger::debug(const char *msg)
{
	_mycategory.debug(msg);
}

} //end of namespace wd
