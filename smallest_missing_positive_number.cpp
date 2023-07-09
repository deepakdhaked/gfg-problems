#include <iostream>
using namespace std;

// Time Complexity: O(N)
// Auxiliary Space: O(N)
int missingNumber1(int arr[], int n)
{
    bool hash[n + 1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            hash[arr[i]] = true;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (hash[i] == false)
        {
            return i;
        }
    }
    return n + 1;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
int missingNumber2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}

int main()
{
    int arr[] = {0, 10, 2, -10, -20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = missingNumber1(arr, n);
    cout << "Smallest missing positive number is : " << ans << endl;
}