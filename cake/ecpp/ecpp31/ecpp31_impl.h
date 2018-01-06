#include <string>

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
class PersonImpl
{
public:    
    PersonImpl(const std::string& name, const Data& birthday, const Address& addr);
    inline std::string name() const { return name_; };
    inline Data   birthDate() const { return birthday_; };
    inline Address  address() const { return addr_; };

private:
    std::string name_;
    Data        birthday_;
    Address     addr_;
};

