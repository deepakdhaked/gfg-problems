#include <iostream>
using namespace std;

int setKthBit(int n, int k)
{
    int mask = 1 << k;
    return n | mask;
}

int main()
{
    int n = 10, k = 2;
    cout << setKthBit(n, k) << endl;
}