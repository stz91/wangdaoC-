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

int main(void)
{
    //输出布局
    PatternLayout *ptnLayout1 = new PatternLayout();
    ptnLayout1->setConversionPattern("%d %c (%p) %m%n");
    PatternLayout *ptnLayout2 = new PatternLayout();
    ptnLayout2->setConversionPattern("%d %c (%p) %m%n");
    PatternLayout *ptnLayout3 = new PatternLayout();
    ptnLayout3->setConversionPattern("%d %c (%p) %m%n");

    RollingFileAppender *rollingFileAppender = new RollingFileAppender(
        "rollingFileAppender",
        "rollingwangdao.log",
        1024,
        5);
    rollingFileAppender->setAppend(ptnLayout3);

    //输出控制
    OstreamAppender *ostreamAppender = new OstreamAppender("OstreamAppender", &cout);
    ostreamAppender->setLayout(ptnLayout1);

    //建立日志记录器
    Category &mycategory = Category::getRoot().getInstance("mycategory");
    mycategory.setPriority(Priority::DEBUG);
    mycategory.addAppender(ostreamAppender);
    mycategory.addAppender(rollingFileAppender);

    for (int idx = 0; idx != 100; ++idx)
    {
        mycategory.alert("%d this is alert", idx);
        mycategory.crit("this is crit");
        mycategory.error("this is error");
        mycategory.warn("this is warn");
        mycategory.info("this is info");
        mycategory.notice("this is notice");
    }
    return 0;
}