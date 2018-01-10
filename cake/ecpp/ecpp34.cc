#include <iostream>

/*
class Shape
{
public:
    virtual void draw() const = 0;// pure virtual function, derived class inherit interfaces not implemetation
    virtual void error(const std::string& msg);// virtual function, derived class inherit interfaces and default implemetation 
    int objectID() const;// non-virtual function, derived class inherit interface and forced implemetation 
};

class Rectangle : public Shape
{
};

class Ellipse : public Shape
{
};
*/

// 继承接口可选实现
class Plane
{
public:
    virtual void fly() = 0;
protected:    
    void defaultFly();
};

void Plane::fly()
{
    defaultFly();
}

void Plane::defaultFly()
{
    std::cout << "Plane default fly" << std::endl;
}

class ModelA : public Plane
{
public:
    virtual void fly()
    {
        defaultFly();
    }
};

class ModelB : public Plane
{
public:
    virtual void fly()
    {
        std::cout << "Model B fly" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Plane* p1 = new ModelA;
    Plane* p2 = new ModelB;

    p1->fly();
    p2->fly();

    return 0;
}

