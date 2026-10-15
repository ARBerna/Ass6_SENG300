#include <iostream>
using namespace std;

int fun1( int x, int y) {

    if (x == 0)
        return y;

    else
        return fun1(x - 1, x + y);

}

int main()
{
    //cout << "fun1(0, 0) = " << fun1(0, 0) << endl;
    cout << "fun1(-10, 0) = " << fun1(-10, 0) << endl;
    //cout << "fun1(0, -7) = " << fun1(0, -7) << endl;
    //cout << "fun1(1, 5) = " << fun1(1, 5) << endl;
    //cout << "fun1(10, 5) = " << fun1(10, 5) << endl;

    return 0;
}