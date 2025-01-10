#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
class Complex
{
    private:
        float Re;
        float Im;
    public:
        Complex()
        {
            this->Re = 1.0;
            this->Im = 1.0;
        }
        Complex(float a, float b)
        {
            this->Re = a;
            this->Im = b;
        }
        Complex conjugated() const
        {
            Complex res(this->Re, -(this->Im));
            return res;
        }
        float absolute() const
        {
            float res = sqrt(pow(this->Re,2) + pow(this->Im,2));
            return res;
        }
        float argument() const
        {
            float res = 0;
            if (this->Re > 0) {
                res = atan(this->Im / this->Re);
            } else if (this->Im > 0) {
                res = PI + atan(this->Im / this->Re);
            } else {
                res = -PI + atan(this->Im / this->Re); 
            }
            return res;
        }
        Complex degree(int n) const
        {
            float Re = 0, Im = 0, a = pow((*this).absolute(),n);
            Re = a * cos(n * (*this).argument());
            Im = a * sin(n * (*this).argument());
            Complex res(Re,Im);
            return res;
        }
        void root(int n) const
        {
            float Re = 0, Im = 0, a = pow((*this).absolute(),1.0/n);
            for (int k = 0; k < n; k++) {
                Re = a * cos(((*this).argument() + 2 * PI * k) / n);
                Im = a * sin(((*this).argument() + 2 * PI * k) / n);
                Complex buff(Re, Im);
                buff.print();
            }    
            return;
        }
        Complex operator + (const Complex& x)
        {
            Complex res(this->Re + x.Re, this->Im + x.Im);
            return res;
        }
        Complex operator + (const float& x)
        {
            Complex res(this->Re + x, this->Im);
            return res;
        }
        Complex operator - (const Complex& x)
        {
            Complex res(this->Re - x.Re, this->Im - x.Im);
            return res;
        }
        Complex operator - (const float& x)
        {
            Complex res(this->Re - x, this->Im);
            return res;
        }
        Complex operator * (const Complex& x) const
        {
            Complex res(this->Re * x.Re - this->Im * x.Im, this->Im * x.Re + this->Re * x.Im);
            return res;
        }
        Complex operator * (const float& x)
        {
            Complex res(this->Re * x, this->Im * x);
            return res;
        }
        Complex operator / (const Complex& x) const
        {
            Complex num = *this * x.conjugated(), denom = x * x.conjugated(),
            res(num.Re / denom.Re, num.Im / denom.Re);
            return res;
        }
        Complex operator / (const float& x)
        {
            Complex res(this->Re / x, this->Im / x);
            return res;
        }
        void print()
        {
            if (this->Im > 0)
                cout << this->Re << '+' << this->Im << 'i' << endl;
            else if (this->Im < 0)
                cout << this->Re << '-' << -(this->Im) << 'i' << endl; 
            else 
                cout << this->Re << endl;
        }
        void print_trigonometric()
        {
            cout << (*this).absolute() << "(cos(" << (*this).argument() << ") + isin("
            << (*this).argument() << "))" << endl;
            return;
        }
        void print_exponential()
        {
            cout << (*this).absolute() << " * exp(i" << (*this).argument() << ')' << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Complex& num)
        {
            if (num.Im > 0)
                stream << num.Re << '+' << num.Im << 'i' << endl;
            else if (num.Im < 0)
                stream << num.Re << '-' << -(num.Im) << 'i' << endl; 
            else 
                stream << num.Re << endl;
        }
        Complex operator ++ ()
        {
            (this->Re)++;
            return *this;
        }
        Complex operator -- ()
        {
            (this->Re)--;
            return *this;
        }
        Complex operator ++ (int)
        {
            (this->Im)++;
            return *this;
        }
        Complex operator -- (int)
        {
            (this->Im)--;
            return *this;
        }
        bool operator > (const Complex& num)
        {
            if ((*this).absolute() > num.absolute())
                return true;
            return false;
        }
        bool operator > (const float& num)
        {
            if ((*this).absolute() > abs(num))
                return true;
            return false;
        }
        bool operator < (const Complex& num)
        {
            if ((*this).absolute() < num.absolute())
                return true;
            return false;
        }
        bool operator < (const float& num)
        {
            if ((*this).absolute() < abs(num))
                return true;
            return false;
        }
        bool operator >= (const Complex& num)
        {
            if ((*this).absolute() >= num.absolute())
                return true;
            return false;
        }
        bool operator >= (const float& num)
        {
            if ((*this).absolute() >= abs(num))
                return true;
            return false;
        }
        bool operator <= (const Complex& num)
        {
            if ((*this).absolute() <= num.absolute())
                return true;
            return false;
        }
        bool operator <= (const float& num)
        {
            if ((*this).absolute() <= abs(num))
                return true;
            return false;
        }
        bool operator == (const Complex& num)
        {
            if ((*this).absolute() == num.absolute())
                return true;
            return false;
        }
        bool operator == (const float& num)
        {
            if ((*this).absolute() == abs(num))
                return true;
            return false;
        }
        bool operator != (const Complex& num)
        {
            if ((*this).absolute() != num.absolute())
                return true;
            return false;
        }
        bool operator != (const float& num)
        {
            if ((*this).absolute() != abs(num))
                return true;
            return false;
        }
};

int main()
{
    Complex c1(3,1.732), c2(7,-6), c3 = c1.degree(2);
    c1.print_trigonometric();
    c1.print_exponential();

}