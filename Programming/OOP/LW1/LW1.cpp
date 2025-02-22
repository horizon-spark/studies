#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// i<=abs(min(num,denom))
// i<=min(abs(num),abs(denom))
class Fraction 
{
    private:
        int num;
        int denom;

        void reduce(int& num, int& denom)
        {
            for (int i=2;i<=min(abs(num),abs(denom));i++) {
                if (num % i == 0 && denom % i == 0) {
                    num /= i;
                    denom /= i;
                }
            }
            return;
        }

        void to_fraction(float x, int& num, int& denom)
        {
            float fr, b;
            denom = 1;
            while (fr = modf(x,&b) != 0.0) {
                x *= 10.0;
                denom *= 10;
            }
            num = x;
            return;
        }

        void fix_sign(int& num, int& denom)
        {
            if ((num < 0 && denom < 0) || (denom < 0)) {
                num *= -1;
                denom *= -1;
            }
            return;
        }

    public:
        void reduce()
        {
            for (int i=2;i<=min(abs(num),abs(denom));i++) {
                if (num % i == 0 && denom % i == 0) {
                    num /= i;
                    denom /= i;
                }
            }
            return;
        }

        void fix_sign()
        {
            if ((num < 0 && denom < 0) || (denom < 0)) {
                num *= -1;
                denom *= -1;
            }
            return;
        }

        Fraction()
        {
            num = 1;
            denom = 1;
        }

        // Fraction(int numerator, int denomerator)
        // {
        //     reduce(numerator,denomerator);
        //     num = numerator;
        //     denom = denomerator;
        // }

        Fraction(float numerator, float denomerator)
        {
            int num1,num2,denom1,denom2;
            to_fraction(numerator,num1,denom1);
            to_fraction(denomerator,num2,denom2);
            num1 *= denom2;
            denom1 *= num2;
            reduce(num1,denom1);
            fix_sign(num1,denom1);
            num = num1;
            denom = denom1;
        }

        Fraction operator + (const Fraction& fract)
        {
            Fraction res((num * fract.denom + fract.num * denom),(denom * fract.denom));
            res.reduce();
            return res;
        }

        Fraction operator + (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr(num1,num2);
            fr.reduce();
            return *this + fr;
        }

        Fraction operator - (const Fraction& fract)
        {
            Fraction res((num * fract.denom - fract.num * denom),(denom * fract.denom));
            res.reduce();
            return res;
        }

        Fraction operator - (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr(num1,num2);
            fr.reduce();
            return *this - fr;
        }

        Fraction operator * (const Fraction& fract)
        {
            Fraction res((num * fract.num),(denom * fract.denom));
            res.reduce();
            return res;
        }

        Fraction operator * (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr(num1,num2);
            fr.reduce();
            return *this * fr;
        }

        Fraction operator / (const Fraction& fract) 
        {
            Fraction res((num * fract.denom),(denom * fract.num));
            res.reduce();
            res.fix_sign();
            return res;
        }

        Fraction operator / (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr(num1,num2);
            fr.reduce();
            return *this / fr;
        }

        friend ostream& operator << (ostream& stream, const Fraction& fract)
        {
            stream << fract.num << '/' << fract.denom << endl;
            return stream;
        }

        Fraction operator ++ ()
        {
            num += 1;
            return *this;
        }

        Fraction operator ++ (int)
        {
            Fraction copy {*this};
            ++num;
            return copy;
        }

        Fraction operator -- ()
        {
            num -= 1;
            return *this;
        }

        Fraction operator -- (int)
        {
            Fraction copy {*this};
            --num;
            return copy;
        }

        bool operator > (const Fraction& fract)
        {
            Fraction fr1 = *this, fr2 = fract;
            fr1.num *= fr2.denom;
            fr2.num *= fr1.denom;
            if (fr1.num > fr2.num)
                return true;
            else 
                return false;
        }

        bool operator > (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr1 = *this, fr2(num1,num2);
            return fr1 > fr2;
        }

        bool operator < (const Fraction& fract)
        {
            Fraction fr1 = *this, fr2 = fract;
            fr1.num *= fr2.denom;
            fr2.num *= fr1.denom;
            if (fr1.num < fr2.num)
                return true;
            else 
                return false;
        }

        bool operator < (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr1 = *this, fr2(num1,num2);
            return fr1 < fr2;
        }

        bool operator >= (const Fraction& fract)
        {
            Fraction fr1 = *this, fr2 = fract;
            fr1.num *= fr2.denom;
            fr2.num *= fr1.denom;
            if (fr1.num >= fr2.num)
                return true;
            else 
                return false;
        }

        bool operator >= (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr1 = *this, fr2(num1,num2);
            return fr1 >= fr2;
        }

        bool operator <= (const Fraction& fract)
        {
            Fraction fr1 = *this, fr2 = fract;
            fr1.num *= fr2.denom;
            fr2.num *= fr1.denom;
            if (fr1.num <= fr2.num)
                return true;
            else 
                return false;
        }

        bool operator <= (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr1 = *this, fr2(num1,num2);
            return fr1 <= fr2;
        }

        bool operator == (const Fraction& fract)
        {
            Fraction fr1 = *this, fr2 = fract;
            fr1.num *= fr2.denom;
            fr2.num *= fr1.denom;
            if (fr1.num == fr2.num)
                return true;
            else 
                return false;
        }

        bool operator == (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr1 = *this, fr2(num1,num2);
            return fr1 == fr2;
        }

        bool operator != (const Fraction& fract)
        {
            Fraction fr1 = *this, fr2 = fract;
            fr1.num *= fr2.denom;
            fr2.num *= fr1.denom;
            if (fr1.num != fr2.num)
                return true;
            else 
                return false;
        }

        bool operator != (const float& x)
        {
            int num1,num2;
            to_fraction(x,num1,num2);
            Fraction fr1 = *this, fr2(num1,num2);
            return fr1 != fr2;
        }

        void print()
        {
            if (num == 0) 
                cout << 0 << endl;
            else
                cout << num << '/' << denom << endl;
            return;
        }

        void print_num()
        {
            cout << num << endl;
            return;
        }
};

int main()
{
    // Fraction fr1(1,10), fr2(2,8), fr3 = fr1 / fr2;
    // fr1.print();
    // fr2.print();
    // fr3.print();
    // bool cmp = fr2 == fr1;
    // cout << cmp << endl;

    Fraction fr1(2,5);
    bool cmp = fr1 > 0.4;
    cout << cmp << endl;
    
}
