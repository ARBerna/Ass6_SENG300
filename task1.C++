int fun1( int x, int y) {

    if (x == 0)
        return y;

    else
        return fun1(x - 1, x + y);

}

int main()
{
    cout << "fun1(0, 0) = " << fun1(0, 0) << endl;
}