#include <iostream> 
#include <cmath>
using namespace std;
class Vector;

class Coordinate 
{
    friend class Vector;
    private:
        float x;
        float y;
        float z;

        float length()
        {
            return sqrt(pow(x,2) + pow(y,2) + pow(z,2)); 
        }
        Coordinate to_cylindrical()
        {
            float r, f;
            r = sqrt(pow(x,2) + pow(y,2));
            f = atan2(y,x);
            Coordinate res(r,f,z);
            return res;
        }
        Coordinate to_spherical()
        {
            float r,t,f;
            r = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
            t = atan2(sqrt(pow(x,2) + pow(y,2)),z);
            f = atan2(y,x);
            Coordinate res(r,t,f);
            return res;
        }

    public:
        Coordinate()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        Coordinate(float a, float b, float c)
        {
            x = a;
            y = b;
            z = c;
        }
        Coordinate operator + (Coordinate& coord)
        {
            Coordinate res(x + coord.x, y + coord.y, z + coord.z);
            return res;
        }
        Coordinate operator - (Coordinate& coord)
        {
            Coordinate res(x - coord.x, y - coord.y, z - coord.z);
            return res;
        }
        bool operator > (Coordinate& coord)
        {
            if ((*this).length() > coord.length())
                return true;
            return false;
        }
        bool operator < (Coordinate& coord)
        {
            if ((*this).length() < coord.length())
                return true;
            return false;
        }
        bool operator >= (Coordinate& coord)
        {
            if ((*this).length() >= coord.length())
                return true;
            return false;
        }
        bool operator <= (Coordinate& coord)
        {
            if ((*this).length() <= coord.length())
                return true;
            return false;
        }
        bool operator == (Coordinate& coord)
        {
            if ((*this).length() == coord.length())
                return true;
            return false;
        }
        bool operator != (Coordinate& coord)
        {
            if ((*this).length() != coord.length())
                return true;
            return false;
        }
        friend ostream& operator << (ostream& stream, Coordinate& coord)
        {
            stream << '(' << coord.x << ',' << coord.y << ',' << coord.z << ')' << endl;
            return stream; 
        }
        void print_dec()
        {
            cout << '(' << x << ',' << y << ',' << z << ')' << endl;
            return;
        }
        void print_cyl()
        {
            Coordinate res = (*this).to_cylindrical();
            res.print_dec();
            return;
        }
        void print_sph()
        {
            Coordinate res = (*this).to_spherical();
            res.print_dec();
            return;
        }
};

class Vector
{
    private:
        float x;
        float y;
        float z;
        
        float length()
        {
            return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        }
        float angle()
        {
            return acos(x / (*this).length());
        }
        
    public:
        Vector()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        Vector(float a, float b, float c)
        {
            x = a;
            y = b;
            z = c;
        }
        Vector(Coordinate& c1, Coordinate& c2)
        {
            x = c2.x - c1.x;
            y = c2.y - c1.y;
            z = c2.z - c1.z;
        }
        Vector operator + (Vector& vec)
        {
            Vector res(x + vec.x, y + vec.y, z + vec.z);
            return res;
        }
        Vector operator - (Vector& vec)
        {
            Vector res(x - vec.x, y - vec.y, z - vec.z);
            return res;
        }   
        Vector operator * (float a)
        {
            Vector res(x * a, y * a, z * a);
            return res;
        }
        Vector operator / (float a)
        {
            Vector res(x / a, y / a, z / a);
            return res;
        }
        bool is_collinear(Vector& vec)
        {
            if ((x / vec.x == y / vec.y) && (y / vec.y == z / vec.z))
                return true;
            return false;
        }
        bool operator > (Vector& vec)
        {
            if ((*this).length() > vec.length())
                return true;
            return false;
        }
        bool operator < (Vector& vec)
        {
            if ((*this).length() < vec.length())
                return true;
            return false;
        }
        bool operator >= (Vector& vec)
        {
            if ((*this).length() >= vec.length())
                return true;
            return false;
        }
        bool operator <= (Vector& vec)
        {
            if ((*this).length() <= vec.length())
                return true;
            return false;
        }
        bool operator == (Vector& vec)
        {
            if ((*this).length() == vec.length())
                return true;
            return false;
        }
        bool operator != (Vector& vec)
        {
            if ((*this).length() != vec.length())
                return true;
            return false;
        }
        void print()
        {
            cout << '(' << x << ',' << y << ',' << z << ')' << endl;
            return;
        }
        friend ostream& operator << (ostream& stream, Vector& vec)
        {
            stream << '(' << vec.x << ',' << vec.y << ',' << vec.z << ')' << endl;
            return stream; 
        }
};
int main()
{
    Vector v1(1,1,1), v2(-2,-2,-2);
    bool b = v1 < v2;
    cout << v1 << v2 << endl;
}