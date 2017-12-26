// g++ -fdump-class-hierarchy -o dia diamondcpp.cc
class Base 
{
public:
  int _iBase;
  char _cBase;
public:
  Base() : _iBase(1111), _cBase('A') 
  {
  }
  virtual void func() 
  {
  }
  virtual void baseFunc() 
  {
  }
};

class Base1 : public virtual Base 
{
public:
  int _iBase1;
  char _cBase1;
public:
  Base1() : _iBase1(2222), _cBase1('B')
  {
  }
  virtual void func()
  {
  }
  virtual void func1()
  {
  }
  virtual void baseFunc1()
  {
  }
};

class Base2 : public virtual Base
{
public:
  int _iBase2;
  char _cBase2;
public:
  Base2() : _iBase2(3333), _cBase2('C') 
  {
  }
  virtual void func()
  {
  }
  virtual void func2()
  {
  }
  virtual void baseFunc2()
  {
  }
};

class Derive : public virtual Base1, public virtual Base2
{
public:
  int _iDerive;
  char _cDerive;
public:
  Derive() : _iDerive(4444), _cDerive('D')
  {
  }
  virtual void func()
  {
  }
  virtual void func1()
  {
  }
  virtual void func2()
  {
  }
  virtual void deriveFunc()
  {
  }
};

//typedef void(*Fun)();


int main(int argc, char** argv) {
  return sizeof(Derive);
}
