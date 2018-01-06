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


#include <string>
#include <boost/shared_ptr.hpp>
#include "ecpp31_impl_fwd.h"

// interfaces class / handle class
class Person
{
public:
    Person(const std::string& name, const Data& birthday, const Address& addr);
    // 如果要用inline 必须把成员函数的定义也放到.h文件中
    // 但这样做便需要知道pImple的实现 Person 便不再是接口类
    std::string name() const;
    Data   birthDate() const;
    Address  address() const;

private:    
    // 指向具体实现的指针 pimpl idiom
    // 使用person的客户代码 就完全与Date Address 以及Person的实现分离
    boost::shared_ptr<PersonImpl> pImpl;
};

