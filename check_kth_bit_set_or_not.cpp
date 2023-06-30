#include <iostream>
using namespace std;

bool checkKthBit(int n, int k)
{
    int mask = (1 << (k));
    return (n & mask) == 0 ? false : true;
}

int main()
{
    int n = 4, k = 2;
    bool res = checkKthBit(n, k);
    if (res == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}