#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(N)
// Space Complexity : O(1)
int maxIndexDiff(vector<int> &arr, int n, long long k)
{
    long long product = 1;
    int count = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        product *= arr[j];
        while (product >= k && i < j)
        {
            product /= arr[i];
            i++;
        }
        if (product < k)
        {
            count += (j - i) + 1;
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 9, 2, 8, 6, 4, 3};
    long long k = 100;
    cout << "Number of subarray having product less than k is : " << maxIndexDiff(arr, arr.size(), k) << endl;
}