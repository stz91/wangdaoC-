#include <iostream>
#include <map>

using namespace std;

template <class Container>
void display(const Container &c)
{
    typename Container::const_iterator it = c.begin();
    while(it != c.end())
    {
        cout << it->first << "--->" << it->second << endl;
        ++it;
    } 
}

void test1()
{
    map<int, string> cities = {
        pair<int, string>(1, "beijing"),
        std::make_pair(2, "shanghai"),
        std::make_pair(3, "shenzhen"),
        std::make_pair(4, "guangzhou"),
    };
    display(cities);

    std::pair<map<int, string>::iterator, bool> ret = \
        cities.insert(std::make_pair(5, "wuhan"));
    if(ret.second)
    {
        cout << "元素插入成功" << endl;
        cout << ret.first->first << "--->" << ret.first->second << endl;
    }
    else
    {
        cout << "元素添加失败,map已有关键字相同的元素" << endl;
    }
    display(cities);

    cout << cities[1] << endl;
    cout << cities[2] << endl;

    cities[1] = "hangzhou";
    display(cities);

    cout << cities[6] << endl;
    display(cities);

    cities[7] = "xian";
    display(cities);
    
}

void test2()
{
    map<string, string> cities = {
        pair<string, string>("010", "beijing"),
        std::make_pair("021", "shanghai"),
        std::make_pair("0755", "shenzhen"),
        std::make_pair("0755", "guangzhou"),
    };

    display(cities);

    std::pair<map<string, string>::iterator, bool> ret = \
        cities.insert(std::make_pair("027", "wuhan"));
    if(ret.second)
    {
        cout << "元素插入成功" << endl;
        cout << ret.first->first << "--->" << ret.first->second << endl;
    }
    else
    {
        cout << "元素添加失败,map已有关键字相同的元素" << endl;
    }
    display(cities);

    cout << cities["010"] << endl;
    cout << cities["0755"] << endl;

    cities["010"] = "hangzhou";
    display(cities);

    cout << cities["021"] << endl;
    display(cities);

    cities["029"] = "xian";
    display(cities);
}



int main()
{
    //test1();
    test2();
}