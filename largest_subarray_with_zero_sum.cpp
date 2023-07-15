#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxLen(vector<int> &arr, int n)
{
    unordered_map<int, int> m;
    int prefix_sum = 0;
    int ans = 0;
    m.insert({prefix_sum, -1});
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (m.find(prefix_sum) != m.end())
        {
            ans = max(ans, i - m[prefix_sum]);
        }
        else
        {
            m[prefix_sum] = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = arr.size();
    cout << maxLen(arr, n) << endl;
}