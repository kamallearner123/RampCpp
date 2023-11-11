
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
    static Factory PointFactory;
    private:
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

point point::PointFactory;

int main()
{
    point a = point::PointFactory::get_typea(1, 2);
    a.point_details();
    point b = point::PointFactory::get_typeb(1, 2);
    b.point_details();
    cout << a << endl;
}