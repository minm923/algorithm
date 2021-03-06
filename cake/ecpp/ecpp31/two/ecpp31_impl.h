#include "ecpp31_interface.h"
#include <string>

#ifndef PERSON_IMPL
#define PERSON_IMPL

struct Data
{
    int year;
    int month;
    int day;
};

struct Address
{
    int country;
    int city;
    int area;
};

// implemetation class
class PersonImpl : public Person
{
public:    
    PersonImpl (const std::string& name, const Data& birthday, const Address& addr);
    // rule of three
    virtual ~PersonImpl() {}

    PersonImpl (const PersonImpl& that) 
    {   
        name_      = that.name_; 
        birthday_  = that.birthday_;
        addr_      = that.addr_;
    }

    PersonImpl& operator=(const PersonImpl& that)
    {
        if (this != &that)
        {
            name_      = that.name_; 
            birthday_  = that.birthday_;
            addr_      = that.addr_;
        }
    }

    std::string name() const { return name_; };
    Data   birthDate() const { return birthday_; };
    Address  address() const { return addr_; };

private:
    std::string name_;
    Data        birthday_;
    Address     addr_;
};

#endif // PERSON_IMPL
