#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class person
{
public:
    person(string name, int age)
        : _name(name), _age(age)
    {
        cout << "person(string name, int age)" << endl;
    }
    virtual void display()
    {
        cout << "name = " << _name << endl;
        cout << "age = " << _age << endl;
    }

private:
    string _name;
    int _age;
};

class employee
    : public person
{
public:
    employee(string name, int age, string department, double salary)
        : person(name, age), _department(department), _salary(salary)
    {
        cout << "employee(string name, int age, string department, double salary)" << endl;
    }
    void display()
    {
        person::display();
        cout << "department = " << _department << endl;
        cout << "salary = " << _salary << endl;
    }
    double getSalary()
    {
        return _salary;
    }

private:
    string _department;
    double _salary;
};

void print(person * p)
{
    p->display();
}

int main(void)
{
    employee e1("xiaoming", 20, "houduan", 2000);
    employee e2("xiaohong", 21, "qianduan", 1800);
    employee e3("xiaogang", 22, "yanfa", 2500);
    print(&e1);
    // e1.display();
    // e2.display();
    // e3.display();
    
    cout << "average salary = " << (e1.getSalary() + e2.getSalary() + e3.getSalary()) / 3 << endl;
    return 0;
}