#include <iostream>
#include "ecpp31_interface.h"
#include "ecpp31_impl.h"
#include <boost/shared_ptr.hpp>

int main(int argc, char* argv[])
{
    Data d;
    d.year = 2018;
    d.month = 1;
    d.day   = 6;
    
    Address a;
    a.country = 21;
    a.city = 6;

    //Person* p = new Person("minm", d, a);
    //std::cout << p->name() << std::endl;

    //Person p("minm", d, a);
    //std::cout << p.name() << std::endl;

    boost::shared_ptr<Person> sp = Person::create("minm", d, a);

    std::cout << sp->name() << std::endl;

    return 0;
}


