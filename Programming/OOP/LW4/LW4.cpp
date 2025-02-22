#include <iostream>
#define _USE_MATH_DEFINES
// #include <cmath>
#include <math.h>
using namespace std;

class Polygon
{
    private:
        int sides;
        float len;
        float ang;
        float to_rad(float deg)
        {
            return deg * M_PI / 180.0;
        }
        float to_deg(float rad)
        {
            return rad * 180.0 / M_PI;
        }
    public:
        Polygon()
        {
            sides = 3;
            len = 1.0;
            ang = 0.0;
        }
        Polygon(int s, float l, float a)
        {
            float buff;
            if (s < 3) {
                cout << "Number of sides can't be less than 3!"
                << " Default number of sides is created (n = 3)" << endl;
                sides = 3;
            } else {
                sides = s;
            }
            if (len <= 0.0) {
                cout << "Side's length can't be less or equal to zero!"
                << "Side of default length is created (a = 1)" << endl;
                len = 1.0;
            } else {
                len = l;
            }
            ang = modf(a / 360.0, &buff) * 360.0;
        }
        Polygon operator ++ ()
        {
            sides++;
            return *this;
        }
        Polygon operator ++ (int)
        {
            return ++(*this);
        }
        Polygon operator -- ()
        {
            if (sides - 1 < 3) {
                cout << "Can't make the number of sides less than 3!" << endl;
                return *this;
            }
            sides--;
            return *this;
        }
        Polygon operator -- (int)
        {
            return --(*this);
        }
        Polygon operator + (int x)
        {
            Polygon copy = (*this);
            copy.sides += x;
            return copy;
        }
        Polygon operator - (int x)
        {
            if (sides - x < 3) {
                cout << "Can't make the number of sides less than 3!" << endl;
                return (*this);
            }
            Polygon copy = (*this);
            copy.sides -= x;
            return copy;
        }
        Polygon operator * (float x)
        {
            if (x == 0.0) {
                cout << "Can't multiply the length of an edge by 0" << endl;
                return *this;
            }
            Polygon copy = (*this);
            copy.len *= x;
            return copy;
        }
        Polygon operator / (float x)
        {
            if (x == 0.0) {
                cout << "Can't divide the length of an edge by 0" << endl;
                return *this;
            }
            Polygon copy = (*this);
            copy.len /= x;
            return copy;
        }
        float perimeter()
        {
            return len * sides;
        }
        float area()
        {
            return (sides * pow(circumscribed_radius(),2) * sin(to_rad(central_angle_deg()))) / 2;
        }
        float central_angle_deg()
        {
            return 360.0 / sides;
        }
        void view_orientation()
        {
            float buff = ang;
            for (int i=0;i<sides;i++) {
                cout << "Side " << i << ':' << buff << endl;
                buff += central_angle_deg();
            }
            return;
        }
        float circumscribed_radius()
        {
            return len / (2 * sin(M_PI / sides));
        }
        float inscribed_radius()
        {
            return circumscribed_radius() * cos(M_PI / sides);
        }
        void change_orientation(float value)
        {
            ang += value;
            return;
        }
        void print()
        {
            cout << "Number of sides: n = " << sides << endl;
            cout << "Side length: a = " << len << endl;
            cout << "Orientation of main side: alf = " << ang << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Polygon& plg)
        {
            stream << "Number of sides: n = " << plg.sides << endl <<
            "Side length: a = " << plg.len << endl << 
            "Orientation of main side: alf = " << plg.ang << endl;
            return stream;
        }
};

int main()
{
    Polygon p1(6,2.64,-780.0);
    cout << "Perimeter: " << p1.perimeter() << endl <<
    "Area: " << p1.area() << endl <<
    "Circumscribed radius: " << p1.circumscribed_radius() << endl <<
    "Inscribed radius: " << p1.inscribed_radius() << endl << 
    "Central angle: " << p1.central_angle_deg() << endl;
    p1.view_orientation();
}