#include <iostream>
#include <unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == 0)
        {
            return true;
        }
        else if (s.find(prefix_sum) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(prefix_sum);
        }
    }
    return false;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}