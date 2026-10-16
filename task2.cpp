#include <iostream>
#include <string>
using namespace std;

int firstLowercase(const string &s, int index = 0)
{
    if(index >= s.length())
    {
        return -1;
    }

    if(islower(s[index]))
    {
        return index;
    }

    return firstLowercase(s, index + 1);
}

int main()
{
    cout << firstLowercase("HELlo") << endl;
    cout << firstLowercase("ABCDEF") << endl;
    cout << firstLowercase("aBC") << endl;
}