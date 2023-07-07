#include <iostream>
using namespace std;

int equilibriumPoint(long long arr[], int n)
{
    if (n == 1)
    {
        return 1;
    }

    long long leftSum = 0, rightSum = 0;
    for (int i = 0; i < n; i++)
    {
        rightSum += arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        rightSum -= arr[i];
        if (leftSum == rightSum)
        {
            return i + 1;
        }
        else
        {
            leftSum += arr[i];
        }
    }
    return -1;
}

int main()
{
    long long arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Equilibrium index is : " << equilibriumPoint(arr, n) << endl;
}