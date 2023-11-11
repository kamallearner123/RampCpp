#include <iostream>
using namespace std;
class error{
    public:
    void print_error() {
        cout << "Error!!!" << endl;
    }
};
void fun() throw (int) {
    int a = 100;
    throw(a);
    return;
}

void fun(int *ptr, int x) throw (int *, int) // Dynamic Exception specification
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}

int main() {
    int a = 0, b = 100;
    try {
        error e1;
        fun((int *)100,0);
    }
    catch (error e) {
        cout << "Exception is caught" << endl;
        e.print_error();
    }
    catch (int e) {
        cout << "Integer" << endl;
    }
    catch(...) {
        cout << "Default" << endl;
    }
    return 0;
}