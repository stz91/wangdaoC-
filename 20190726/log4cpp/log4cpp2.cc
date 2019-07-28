#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

int main(void)
{
    //格式控制
    PatternLayout * ptnLayout1 = new PatternLayout();
    ptnLayout1->setConversionPattern("%d %c (%p) %m%n");
    PatternLayout * ptnLayout2 = new PatternLayout();
    ptnLayout2->setConversionPattern("%d %c (%p) %m%n");

    //输出控制
    OstreamAppender * ostreamAppender = new OstreamAppender("OstreamAppender", &cout);
    ostreamAppender->setLayout(ptnLayout1);
    FileAppender * fileappender = new FileAppender("fileAppender", "wangdao.log");
    fileappender->setLayout(ptnLayout2);

    //建立目录
    Category & mycategory = Category::getRoot().getInstance("mycategory");
    mycategory.setPriority(Priority::DEBUG);
    mycategory.addAppender(ostreamAppender);
    mycategory.addAppender(fileappender);

    mycategory.alert("this is alert");
    mycategory.crit("this is crit");
    mycategory.error("this is error");
    mycategory.warn("this is warn");
    mycategory.info("this is info");
    mycategory.notice("this is notice");

    return 0;
} 