#include <iostream>

class Rational
{
public:
    Rational(int n=0, int d=1)
        : numerator_(n),
          denominator_(d)
    {
    }

    int num() const
    { return numerator_; }

    int den() const
    { return denominator_; }

    /*
     * 改用 non-member function
    const Rational operator* (const Rational& rhs) const
    {
        return Rational (numerator_*rhs.numerator_, denominator_*rhs.denominator_);
    }
    */

private:    
    int numerator_;
    int denominator_;
};

// non-member function
const Rational operator* (const Rational& lhs, const Rational& rhs)
{
    return Rational (lhs.num()*rhs.num(), rhs.den()*rhs.den());
}


int main(int argc, char* argv[])
{
    Rational oneEight(1, 8);
    Rational oneHalf(1, 2);
    Rational res    = oneEight * oneHalf;
    //Rational res2 = 2 * oneEight;// not ok
    Rational res3   = oneEight * 2;// ok, because of implicit cast; not ok, when explicit Rational @6

    std::cout << res.num() << " " << res.den() << std::endl;
    std::cout << res3.num() << " " << res3.den() << std::endl;

    return 0;
}

