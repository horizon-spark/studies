#include <iostream>

//Task 1

// class Integer
// {
// public:
//     Integer(double n)
//     {
//         value = n;
//     }
 
//     void print()  const
//     {
//         std::cout << "value: " << value << std::endl;
//     }

//     Integer& operator * (int number)
//     {
//         value *= number;
//         return *this;
//     }

//     Integer& operator * (double number)
//     {
//         value *= number;
//         return *this;
//     }

// private:
//     double value;
// };

// int main()
// {
//     Integer num1{23.5};
//     Integer num2{34.2};
//     Integer num3{num1 * 2};
//     Integer num4{num2 * 3.5};

//     num3.print();
//     num4.print();
// }

// Task 2

class Rational 
{
public:
    Rational(int num, int denum)
    {
        this->numerator = num;
        this->denumerator = denum;
    }
    Rational operator + (Rational& other)
    {
        int num = numerator;
        int denum = denumerator;
        if (denumerator != other.denumerator)
        {
            num = num * other.denumerator + other.numerator * denum;
            denum *= other.denumerator;
        }
        else 
        {
            num += other.numerator;
        }
        return Rational{num,denum};
    }
    Rational operator * (Rational& other)
    {
        int num = numerator;
        int denum = denumerator;
        num *= other.numerator;
        denum *= other.denumerator;
        return Rational{num,denum};
    }
    int get_numerator()
    {
        return numerator;
    }
    int get_denumerator()
    {
        return denumerator;
    }
private:
    int numerator;
    int denumerator;
}; 

std::ostream& operator << (std::ostream& stream, Rational& fraction)
{
    stream << "Value: " << fraction.get_numerator() << "/" << fraction.get_denumerator() << std::endl;
    return stream;
}

int main()
{
    Rational f1{5,4};
    Rational f2{1,2};
    Rational f3{f1+f2};
    Rational f4{f1*f2};
    std::cout << f3;
    std::cout << f4;

}