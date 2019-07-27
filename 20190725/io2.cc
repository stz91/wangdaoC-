#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


//所有的流对象都是不能复制的

void test0()
{
    ifstream ifs;
    ifs.open("test.txt");
    if(!ifs.good())
    {
        cout << "ifstream open file error!" << endl;
        return ;
    }

    //string word;
    //while(ifs >> word)
    string line;
    vector<string> file;
    while(getline(ifs,line))
    {
        cout << line << endl;
        file.push_back(line);
    }
}

void test1()
{
    ofstream ofs("test.txt");
    if(!ofs)
    {
        cout << "ofstream open file error!" << endl;
        return ;
    }
    ofs.close();
}

void test4()
{
    //把某文件的内容一次性读完
    string filename = "test.txt";
    ifstream ifs(filename,ios::ate);
    if(!ifs)
    {
        cout << "ifstream open files " << filename << endl;
        return ;
    }

    int length = ifs.tellg();
    cout << "ifs.tellg() = " << ifs.tellg() << endl;


    ifs.seekg(0);
    char buf[length + 1] = {0}; 
    ifs.read(buf, length);
    // printf("buf = %s\n", buf);

    string content(buf);
    cout << content << endl;
    
}

int main(void)
{
    //test0();
    test4();
    return 0;
}