
#include <iostream>
#include <cmath>
using namespace std;
enum class Type
{
    TYPEA,
    TYPEB
};

struct point
{
public:
    int a, b;
    Type type;
    point(int c, int d, Type t) : a(c), b(d), type(t)
    {
    }
    void point_details()
    {
        cout << a << " " << b << endl;
        return;
    }
    class Factory
    {
    public:
        static point get_typea(int c, int d)
        {
            return {c, d, Type::TYPEA};
        }
        static point get_typeb(int c, int d)
        {
            return {c + 9, d + 20, Type::TYPEB};
        }
    };

    friend ostream &operator<<(ostream &os, const point p)
    {
        cout << "Operator overloading function called" << endl;
        os << p.a << " " << p.b << endl;
        return os;
    }
};

int main()
{
    point a = point::Factory::get_typea(1, 2);
    a.point_details();
    point b = point::Factory::get_typeb(1, 2);
    b.point_details();
    cout << a << endl;
}