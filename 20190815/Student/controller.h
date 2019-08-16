#include "Student.h"
#include "View.h"
#include <map>
#include <iostream>
using std::cout;
using std::endl;




class Controller
{
public:
    void attach(const Student &student) { _students.insert(std::make_pair(student.getId(), student)); }
    void detach(size_t id) { _students.erase(id); }
    void show(View *view)
    {
        for (auto it = _students.begin(); it != _students.end(); ++it)
        {
            view->reset(&(it->second));
            view->show();
            cout << endl;
        }
    }

private:
    std::map<size_t, Student> _students;
};