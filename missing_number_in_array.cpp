#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Time Complexity: O(N).
// Auxiliary Space: O(N)
int missingNumber1(vector<int> &v, int n)
{
    bool hash[n + 1];
    memset(hash, false, sizeof(hash));

    for (int i = 0; i < v.size(); i++)
    {
        hash[v[i]] = true;
    }
    int ans;
    for (int i = 1; i < n + 1; i++)
    {
        if (hash[i] == false)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

// Time Complexity: O(N).
// Auxiliary Space: O(1)
int missingNumber2(vector<int> &v, int n)
{
    long long sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    long long temp = (n * (n + 1)) / 2;
    return temp - sum;
}

// Time Complexity: O(N).
// Auxiliary Space: O(1)
int missingNumber3(vector<int> &v, int n)
{
    int xor_sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        xor_sum ^= v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        xor_sum ^= i;
    }
    return xor_sum;
}

int main()
{
    vector<int> v = {1, 2, 3, 5};
    int n = 5;
    cout << "missing number is : " << missingNumber2(v, n) << endl;
}