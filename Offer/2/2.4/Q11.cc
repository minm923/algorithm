#include <stdio.h>

int Global_Invalid_Output = 0;

bool equal(double num1, double num2)
{
    if ((num1-num2)<0.0000001 || (num1-num2)>-0.0000001)
        return true;        
    else
        return false;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    for (int i=0; i<exponent; ++i)
    {
        base *= base;
    }
    return base;
}

double PowerWithUnsignedExponent2(double base, unsigned int exponent)
{
    if (0 == exponent)
    {
        return 1;
    }
    else if (1 == exponent)
    {
        return base;
    }
    else
    {
        double result = PowerWithUnsignedExponent2(base, exponent>>1);// trick >> 1
        result *= result;        
        if (exponent & 0x01)
        {
            result *= base;
        }
    }
}

double Power(double base, int exponent)
{
    if (equal(base, 0.0) && exponent < 0)// attention 底数为0 幂为负数的特殊情况
    {
        Global_Invalid_Output = 1;
        return 0;
    }

    if (exponent > 0)
    {
        base = PowerWithUnsignedExponent2(base, exponent);
    }
    else if (0 == exponent)// if equal(base, 0) return 1
    {
        base = 1;
    }
    else
    {
        exponent = -exponent;
        base = PowerWithUnsignedExponent2(base, exponent);
       
        base = 1 / base;
    }

    return base;    
}

int main(int argc, char* argv[])
{
    printf("%lf\n",Power(2.3, 3));
    printf("%lf\n",Power(2.3, 0));
    printf("%lf\n",Power(2.3, -3));
    printf("%lf\n",Power(0, -2));

    return 0;
}
