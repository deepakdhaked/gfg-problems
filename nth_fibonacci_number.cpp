#include <iostream>
#include <vector>
using namespace std;

int mod = 1000000007;
int func(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = func(n - 1, dp) % mod + func(n - 2, dp) % mod;
    return dp[n];
}

int nthFibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    return func(n, dp) % mod;
}