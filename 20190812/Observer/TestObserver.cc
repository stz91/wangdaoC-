#include "Subject.h"
#include "Observer.h"

#include <iostream>
#include <memory>

using namespace std;

int main(void)
{
    unique_ptr<Observer> baby1(new Baby("Tom"));
    unique_ptr<Observer> baby2(new Baby("Jerry"));
    unique_ptr<Observer> nurse1(new Nurse("Lily"));
    unique_ptr<Observer> nurse2(new Nurse("xiaohong"));

    Ring ring;
    ring.attach(baby1.get());
    ring.attach(baby2.get());
    ring.attach(nurse1.get());
    ring.attach(nurse2.get());

    Guest guest("xiaoming");

    guest.knock(ring);
    ring.detach(nurse2.get());
    cout << ">>" << endl;
    guest.knock(ring);

    return 0;
}