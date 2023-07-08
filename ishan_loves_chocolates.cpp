#include <iostream>
#include <vector>
using namespace std;

int chocolates(int n, vector<int> &arr)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] >= arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return arr[left];
}

int main()
{
    vector<int> arr = {5, 9, 2, 6};
    cout << "Tastiness leve is : " << chocolates(arr.size(), arr) << endl;
}