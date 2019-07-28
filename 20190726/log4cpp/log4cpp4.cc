#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;
inline std::string int2string(int line)
{
    std::ostringstream oss;
    oss << line;
    return oss.str();
}
#define suffix(msg) std::string(msg).append(" (").append(__FILE__).append(":").append(__func__).append(":").append(int2string(__LINE__)).append(")").c_str()

class MyLog
{
public:
    static MyLog *getinstance()
    {
        if (nullptr == _p)
        {
            _p = new MyLog();
        }
        return _p;
    }
    static void destroy()
    {
        if (_p)
        {
            delete _p;
        }
        _p = nullptr;
    }

    void LogInfo(const char *msg)
    {
        _myCategory.info(suffix(msg));
    }
    void LogError(const char *msg)
    {
        _myCategory.error(suffix(msg));
    }
    void LogWarn(const char *msg)
    {
        _myCategory.warn(suffix(msg));
    }
    void LogDebug(const char *msg)
    {
        _myCategory.debug(suffix(msg));
    }
    void LogCrit(const char *msg)
    {
        _myCategory.crit(suffix(msg));
    }
    void LogNotice(const char *msg)
    {
        _myCategory.notice(suffix(msg));
    }

private:
    static MyLog *_p;
    Category &_myCategory;
    MyLog()
        : _myCategory(Category::getRoot().getInstance("mycategory"))
    {
        PatternLayout *ptnLayout1 = new PatternLayout();
        ptnLayout1->setConversionPattern("%d %c (%p) %m%n");
        PatternLayout *ptnLayout3 = new PatternLayout();
        ptnLayout3->setConversionPattern("%d %c (%p) %m%n");

        RollingFileAppender *rollingFileAppender = new RollingFileAppender(
            "rollingFileAppender",
            "rollingtest.log",
            1024 * 1024,
            5);
        rollingFileAppender->setAppend(ptnLayout3);

        //输出控制
        OstreamAppender *ostreamAppender = new OstreamAppender("OstreamAppender", &cout);
        ostreamAppender->setLayout(ptnLayout1);

        //建立日志记录器
        _myCategory.setPriority(Priority::DEBUG);
        _myCategory.addAppender(ostreamAppender);
        _myCategory.addAppender(rollingFileAppender);
    }
    ~MyLog()
    {
        cout << "~MyLog" << endl;
        _myCategory.shutdown();
    }
};

MyLog *MyLog::_p = nullptr;

int main(void)
{
    MyLog *p1 = MyLog::getinstance();
    MyLog *p2 = MyLog::getinstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    p1->LogError("this is error msg");
    p1->LogInfo("this is info msg");
    p1->LogWarn("this is warn msg");
    p1->LogNotice("this is notice msg");
    p1->LogCrit("this is crit msg");

    MyLog::destroy();
    return 0;
}