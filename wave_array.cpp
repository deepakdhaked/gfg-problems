#include <iostream>
#include <vector>
using namespace std;

void convertToWave(int n, vector<int> &arr)
{
    for (int i = 0; i < n - 1; i += 2)
    {
        arr[i] = arr[i] ^ arr[i + 1];
        arr[i + 1] = arr[i] ^ arr[i + 1];
        arr[i] = arr[i] ^ arr[i + 1];
    }
}

int main()
{
    vector<int> odd = {1, 2, 3, 4, 5};
    vector<int> even = {2, 4, 7, 8, 9, 10};
    convertToWave(odd.size(), odd);
    for (auto i : odd)
    {
        cout << i << " ";
    }
}