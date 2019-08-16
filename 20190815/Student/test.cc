#include "controller.h"
#include "Student.h"
#include "View.h"
#include "SubView.h"
#include <memory>
int main()
{
    Controller c1;
    c1.attach(Student(1, "xiaoming"));
    std::unique_ptr<View> view(new Subview1());
    c1.show(view.get());
    return 0;
}