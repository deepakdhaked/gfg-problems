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

// recrsive approach (top-down approach)
// Time Complexity : O(N)
// Space Complexity : O(N)
int nthFibonacci(int n)
{
    vector<int> dp(n + 1, -1);
    return func(n, dp) % mod;
}

// iterative approach (bottom-up approach)
// Time Complexity : O(N)
// Space Complexity : O(1)
int nthFibonacci(int n)
{
    int second_previous = 0;
    int first_previous = 1;

    if (n == 0)
    {
        return second_previous;
    }

    int current;
    for (int i = 2; i <= n; i++)
    {
        current = (first_previous + second_previous) % mod;

        // update second_previous and first_previous
        second_previous = first_previous;
        first_previous = current;
    }
    return first_previous;
}