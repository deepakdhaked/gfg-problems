#include <iostream>
#include <cstring>
using namespace std;

// Time Complexity : O(n*r)
// Space Complexity : O(r)
int nCr(int n, int r)
{
    if (n < r)
    {
        return 0;
    }
    if ((n - r) < r)
    {
        r = n - r;
    }

    int mod = 1000000007;
    int dp[r + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(r, i); j > 0; j--)
        {
            dp[j] = (dp[j] + dp[j - 1]) % mod;
        }
    }
    return dp[r];
}

int main()
{
    int n = 4, r = 2;
    cout << nCr(n, r) << endl;
}