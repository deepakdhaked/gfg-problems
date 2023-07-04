#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(N)
// Space Complexity : O(1)
vector<int> subarraySum(vector<int> &arr, int n, long long s)
{
    vector<int> ans;
    long long sum = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        sum += arr[j];
        while (sum > s && i < j)
        {
            sum -= arr[i];
            i++;
        }

        if (sum == s)
        {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    long long s = 15;
    vector<int> result = subarraySum(arr, arr.size(), s);
    cout << "(" << result[0] << ", " << result[1] << ")" << endl;
}