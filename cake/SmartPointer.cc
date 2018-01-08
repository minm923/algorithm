#include <iostream>

template<typename T>
class MySmartPointer
{
public:    
    explicit MySmartPointer(T* const p)
        : pT_(p),
          pCount_(new int(1))
    {

    }

    // rule of three
    ~MySmartPointer() 
    {
        std::cout << "before dec count = " << getCount() << std::endl;
        decrCount();
        std::cout << "after dec count = " << getCount() << std::endl;
        if (0 == getCount() )
        {
            std::cout << "releasePT" << std::endl;
            releasePT();
            releaseCount();
        }
    }

    MySmartPointer(MySmartPointer& that)
    {
        pT_     = that.pT_;
        pCount_ = that.pCount_;
        incrCount();
    }

    MySmartPointer& operator=(const MySmartPointer& that)
    {
        pT_     = that.pT_;
        pCount_ = that.pCount_;
        incrCount();

        return *this;
    }

    T* operator->()
    {
        return pT_;
    }

    int  getCount()  { return *pCount_; }

private:        
    void releasePT()    { delete pT_; pT_ = NULL; }
    void releaseCount() { delete pCount_; pCount_ = NULL; }

    void incrCount() { ++(*pCount_); }
    void decrCount() { --(*pCount_); }

    T* pT_;
    int* pCount_;
};

template<class T>
std::ostream& operator<<(std::ostream& os, MySmartPointer<T>& sp)
{
    os << sp.getCount();

    return os;
}

void func(MySmartPointer<int> p)
{
    std::cout << "infunc " << std::endl;
}

void func2(MySmartPointer<int>& p)
{
    std::cout << "infunc2 " << std::endl;
}

int main(int argc, char * argv[])
{
    MySmartPointer<int> msp(new int(10));
    std::cout << msp << std::endl;

    func(msp);
    std::cout << msp << std::endl;

    func2(msp);
    std::cout << msp << std::endl;

    MySmartPointer<int> msp2(new int(10));
    std::cout << msp2 << std::endl;
    
    MySmartPointer<int> msp3(msp2);
    std::cout << msp3 << std::endl;

    MySmartPointer<int> msp4 = msp3;
    std::cout << msp4 << std::endl;

    std::cout << "start deconstruct" << std::endl;

    return 0;    
}

