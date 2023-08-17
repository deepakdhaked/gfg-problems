#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(N * N).
// Space Complexity : O(1).
vector<int> leaders(int a[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = i; j < n; j++)
        {
            if (a[j] > a[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[n - 1]);
    return ans;
}

// Time Complexity : O(N).
// Space Complexity : O(N).
vector<int> leaders(int a[], int n)
{
    int leader = a[n - 1];
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= leader)
        {
            ans.push_back(a[i]);
            leader = a[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int a[] = {16, 17, 4, 3, 5, 2};
    int n = 6;

    vector<int> ans = leaders(a, n);
    for (int i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;
}