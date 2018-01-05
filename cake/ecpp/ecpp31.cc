#include <iostream>

/*
#include <string>
// Date 和 Address 存在严重的编译依赖关系
#include "Date.h"
#include "Address.h"

class Person
{
public:
    Person(const std::string& name, const Data& birthday, const Address& addr);

    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:    
    // implemetation details
    std::string theName;
    Date   theBirthData;
    Address  theAddress;
};
*/

// interfaces class

#include <string>
#include <boost/shared_ptr.hpp>

class PersonImpl;
class Date;
class Address;

class Person
{
public:
    Person(const std::string& name, const Data& birthday, const Address& addr);
    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:    
    // 指向具体实现的指针 pimpl idiom
    // 使用person的客户代码 就完全与Date Address 以及Person的实现分离
    boost::shared_ptr<PersonImpl> pImpl;
};

// implemetation class


int main(int argc, char * argv[])
{

    return 0;    
}

