#include <iostream>
using namespace std;
#define mod (int)(1e9 + 7)

int sumOfNaturals(int n)
{
    return ((n * 1LL * (n + 1)) / 2) % mod;
}

int main()
{
    int n = 6;
    cout << "Sum of Natural Numbers is : " << sumOfNaturals(n) << endl;
}