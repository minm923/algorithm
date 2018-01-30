#include <iostream>

class NonCopyable
{
public:
    NonCopyable() {}
    ~NonCopyable() {}

private:
    NonCopyable(const NonCopyable& that); 
    NonCopyable& operator=(const NonCopyable& that);
};

//EBO
class test2 : public NonCopyable
{
public:    
    test2(int i)
     : i_(i)
    {

    }

private:    
    int i_;
};

class test3 : private NonCopyable
{
public:    
    test3(int i)
     : i_(i)
    {

    }

private:    
    int i_;
};

class test4
{
public:    
    test4(int i)
     : i_(i)
    {

    }

private:    
    int i_;
    NonCopyable n_;
};

int main(int argc, char * argv[])
{
    /*
    test2 t1(1);
    test2 t2(2);
    t2 = t1;

    test3 t3(3);        
    test3 t4(4);
    t3 = t4;
    */

    test4 t5(5);
    test4 t6(6);
    t5 = t6;

    return 0;
}

