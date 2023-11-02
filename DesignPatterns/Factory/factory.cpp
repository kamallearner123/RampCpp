
#include <iostream>
#include <cmath>
using namespace std;
enum class Type {TYPEA, TYPEB};

struct point {
    public:
    int a,b;
    Type type;
    point(int c, int d, Type t):a(c), b(d), type(t) {
    }
        void point_details() {
        cout << a << " "  << b << endl;
        return;
    }

    friend ostream& operator<<(ostream &os, const point p){
        cout << "Operator overloading function called" << endl;
        os << p.a << " " << p.b << endl;
        return os;
    }
};


class Factory {
    public:
    static point get_typea(int c, int d) {
        return {c,d,Type::TYPEA};
    }
    static point get_typeb(int c, int d) {
        return {c+10,d+20,Type::TYPEB};
    }
};

int main()
{
    point a = Factory::get_typea(1,2);
    a.point_details();
    point b = Factory::get_typeb(1,2);
    b.point_details();
    cout << a << endl;

}