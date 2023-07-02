#include <iostream>
using namespace std;

int setSetBit(int x, int y, int l, int r)
{
    int mask = 1 << (r - l + 1);
    mask--;
    mask = mask << (l - 1);
    mask = y & mask;
    x = x | mask;
    return x;
}

int main()
{
    int x = 44, y = 3, l = 1, r = 5;
    cout << "Output is : " << setSetBit(x, y, l, r) << endl;
}