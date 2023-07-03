#include <iostream>
using namespace std;

int maxIndexDiff(int arr[], int n)
{
    int LeftMin[n], RightMax[n];
    LeftMin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        LeftMin[i] = min(arr[i], LeftMin[i - 1]);
    }

    RightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        RightMax[i] = max(arr[i], RightMax[i + 1]);
    }

    int i = 0, j = 0, maxDiff = -1;
    while (i < n && j < n)
    {
        if (LeftMin[i] <= RightMax[j])
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return maxDiff;
}

int main()
{
    int n = 9;
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    cout << "Maximum index difference is : " << maxIndexDiff(arr, n) << endl;
}