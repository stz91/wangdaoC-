#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

int main(void)
{
    OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
    ostreamAppender->setLayout(new BasicLayout());
    
    Category & root = Category::getRoot();
    root.setPriority(Priority::DEBUG);
    root.addAppender(ostreamAppender);
    
    root.alert("this is alert");
    root.crit("this is crit");
    root.error("this is error");
    root.warn("this is warn");
    root.info("this is info");
    root.notice("this is notice");

    Category::shutdown();
    return 0;
}