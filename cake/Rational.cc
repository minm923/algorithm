#include <iostream>
#include <stdexcept>

class Rational
{
public:    
    // implicit conversion
    Rational(int numerator = 0, int denominator = 1)
        : numerator_(numerator),
          denominator_(denominator)
    {
        if (0 == denominator_)
        {
            // throw std::runtime_error when the denominator is 0
            throw std::runtime_error("denominator is 0");
        }
    }

    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }

private:
    int numerator_;
    int denominator_;
};

const Rational operator*(const Rational& hls, const Rational& rhs)
{
    return Rational(hls.numerator()*rhs.numerator(), hls.denominator()*rhs.denominator());
}

/*
const Rational operator-(const Rational& hls, const Rational& rhs)
{
}

const Rational operator*(const Rational& hls, const Rational& rhs)
{
}

const Rational operator*(const Rational& hls, const Rational& rhs)
{
}
*/

int main(int argc, char* argv[])
{
    Rational a(1, 2);
    Rational b = a * 3; 

    return 0;    
}
