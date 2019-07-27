#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//做格式转换:
//  > 把其他类型的数据转化成字符串
//  > 把字符串转换成其他类型数据
void test()
{
    stringstream ss;
    int number1 = 100;
    int number2 = 101;

    ss << "number1= " << number1
       << " number2= " << number2;

    string line = ss.str();
    cout << line << endl;;

    string word;
    int number;
    while(!ss.eof())
    {
        ss >> word >> number;
        cout << word << "--->" << number << endl;
    }
}

string int2str(int number)
{
    ostringstream oss;
    oss << number;
    return oss.str();
}

void readConfig(const string & filename)
{
    ifstream  ifs(filename);
    if(!ifs)
    {
        cout << "ifstream open file" << filename << endl;
        return;
    }
    string line;
    struct Info
    {
        string key;
        string value;
    };
    vector<Info> config;

    while(getline(ifs,line))
    {
        istringstream iss(line);
        string key,value;
        while(!iss.eof())
        {
            iss >> key >> value;
            config.push_back(Info(key,value));
        }
    }
}

int main(void)
{
    test();
    return 0;
}