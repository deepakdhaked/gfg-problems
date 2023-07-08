#include <iostream>
#include <algorithm>
using namespace std;

bool findTriplets(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int left = i + 1, right = n - 1, sum = 0;
        while (left < right)
        {
            if (arr[i] + arr[left] + arr[right] == 0)
            {
                return true;
            }
            else if (arr[i] + arr[left] + arr[right] > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = findTriplets(arr, n);
    if (ans == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}