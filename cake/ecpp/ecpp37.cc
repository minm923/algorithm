#include <iostream>

class Shape
{
public:
    enum ShapeColor {Red, Green, Blue};

    virtual void draw(ShapeColor color = Red)
    {
        std::cout << "shape draw color : " << color << std::endl;
    }

};

class Rectangle : public Shape
{
public:
    virtual void draw(ShapeColor color = Green)
    {
        std::cout << "Rectangle draw color : " << color << std::endl;
    }
};

class Circle : public Shape
{
public:    
    virtual void draw(ShapeColor color)
    {
        std::cout << "Circle draw color : " << color << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Shape * ps;
    Shape * pr = new Rectangle;
    Shape * pc = new Circle;

    pr->draw();
    pc->draw();

    return 0;
}

