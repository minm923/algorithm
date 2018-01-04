#include <iostream>
#include <stdexcept>
#include <stdint.h>

// 辗转相除法
int gcd(int a, int b)
{
    int x = 0;
    int y = 0;

    if (a > b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }

    int z = x % y;
    while (0 != z)
    {
        x = y;
        y = z;
        z = x % y;
    }

    return y;
}

int lcm(int a, int b)
{
    // 不能a * b / gcd(a, b) 可能会溢出
    return a / gcd(a, b) * b;
}

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
        else
        {
            // 0和任意自然数没有最大公约数和最小公倍数
            if (0 != numerator_)
            {
                int iGcd = gcd(numerator_, denominator_);
                numerator_   /= iGcd;
                denominator_ /= iGcd;
            }
        }
    }

    inline int numerator() const { return numerator_; }
    inline int denominator() const { return denominator_; }

    const Rational operator+(const Rational& that) const
    {
        int iLcm = lcm(denominator_, that.denominator());
        int iN   = iLcm/denominator_*numerator_ + iLcm/that.denominator()*that.numerator();
        return Rational(iN, iLcm);
    }

    const Rational operator+=(const Rational& that)
    {
        int iLcm = lcm(denominator_, that.denominator());
        int iN   = iLcm/denominator_*numerator_ + iLcm/that.denominator()*that.numerator();
        Rational R(iN, iLcm);

        numerator_   = R.numerator();
        denominator_ = R.denominator();

        return *this;
    }

    const Rational operator-=(const Rational& that)
    {
        Rational R(-1*that.numerator(), that.denominator());
        (*this) += R;
        return *this;
    }

    const Rational operator*=(const Rational& that)
    {
        numerator_   *= that.numerator();
        denominator_ *= that.denominator();
        return *this;
    }

    const Rational operator/=(const Rational& that)
    {
        Rational R(that.denominator(), that.numerator());
        (*this) *= R;
        return (*this);
    }

    friend  std::istream& operator>>(std::istream& is, Rational& R);

private:
    int numerator_;
    int denominator_;
};

/*
const Rational operator+(const Rational& hls, const Rational& rhs)
{
    int iLcm = lcm(hls.denominator(), rhs.denominator());
    int iN   = iLcm/hls.denominator()*hls.numerator() + iLcm/rhs.denominator()*rhs.numerator();
    
    return Rational(iN, iLcm);
}
*/

const Rational operator-(const Rational& hls, const Rational& rhs)
{
    Rational R = Rational(-rhs.numerator(), rhs.denominator());
    return hls+R;
}

const Rational operator*(const Rational& hls, const Rational& rhs)
{
    return Rational(hls.numerator()*rhs.numerator(), hls.denominator()*rhs.denominator());
}

const Rational operator/(const Rational& hls, const Rational& rhs)
{
    Rational R = Rational(rhs.denominator(), rhs.numerator());
    return hls*R;
}

// 输入输出运算符必须是非成员函数
std::ostream& operator<<(std::ostream& os, const Rational& R)
{
    // 仅打印内容 不打印换行符
    os << "numerator " << R.numerator() << " denominator " << R.denominator();
    return os;
}

// 输入输出运算符必须是非成员函数
// TODO : 各种各样的输入形式 3, 3.5, -1, -1/5, -0.2
// S1 判断有效性 溢出
// S2 先转换成小数
// S3 右移小数点转换为分数 即 有理数
std::istream& operator>>(std::istream& is, Rational& R)
{
    // copy and swap for exception safety
    Rational T;
    is >> T.numerator_ >> T.denominator_;

    if (!is)
    {
        throw std::runtime_error("invalid input");
    }
    else
    {
        R.numerator_   = T.numerator_;
        R.denominator_ = T.denominator_;
    }
}

int main(int argc, char* argv[])
{
    Rational r1(-20, 5);

    //Rational r2 = 1 + r1;// 1无法隐式转换
    //std::cout << r2 << std::endl;

    Rational r3 = r1 + 1;
    std::cout << r3 << std::endl;
    
    return 0;    
}

