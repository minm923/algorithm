#include "ecpp31_impl.h"

PersonImpl::PersonImpl(const std::string& name, const Data& birthday, const Address& addr)
    : name_(name),
      birthday_(birthday),
      addr_(addr)
{
}
