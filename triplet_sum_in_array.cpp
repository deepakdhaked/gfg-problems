#include <iostream>
#include <algorithm>
using namespace std;

bool find3Numbers(int arr[], int n, int X)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int left = i + 1, right = n - 1, sum = 0;
        while (left < right)
        {
            if (arr[i] + arr[left] + arr[right] == X)
            {
                return true;
            }
            else if (arr[i] + arr[left] + arr[right] > X)
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
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 13;
    bool ans = find3Numbers(arr, n, X);
    if (ans == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}