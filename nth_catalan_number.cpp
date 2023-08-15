#include <iostream>
#include <cstring>
using namespace std;

int findCatalan(int n)
{
    // create a dp[] array.
    unsigned long int dp[n + 1];
    int mod = 1e9 + 7;

    // set 0th and 1st catalan = 1.
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % mod;
        }
    }

    return dp[n];
}