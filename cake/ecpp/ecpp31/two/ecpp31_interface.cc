#include "ecpp31_interface.h"
#include "ecpp31_impl.h"

/*
Person::Person(const std::string& name, const Data& birthday, const Address& addr)
    : pImpl(new PersonImpl(name, birthday, addr))    
{}

std::string Person::name() const { return pImpl->name(); };
Data   Person::birthDate() const { return pImpl->birthDate(); };
Address  Person::address() const { return pImpl->address(); };

*/

boost::shared_ptr<Person> Person::create(const std::string& name, 
                                        const Data& birthday, 
                                        const Address& addr)
{
    return boost::shared_ptr<Person>(new PersonImpl(name, birthday, addr));
}

