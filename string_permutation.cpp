#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solveRecursive(string s, vector<string> &ans, int index)
{
    if (index >= s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int j = index; j < s.length(); j++)
    {
        swap(s[index], s[j]);
        solveRecursive(s, ans, index + 1);

        // BackTracking
        swap(s[index], s[j]);
    }
}

// Time Complexity : O(N * N!)
// Space Complexity : O(1) - not consider recursion stack space**
vector<string> permutation(string s)
{
    vector<string> ans;
    int n = s.length();
    solveRecursive(s, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}