#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>


using namespace std;

class QueryResult;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, 
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f)
    : sought(s), lines(p), file(f) { }
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
}