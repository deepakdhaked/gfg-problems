#include <iostream>
#include <unordered_map>
using namespace std;

string PartyType(long long int arr[], int n)
{
    unordered_map<long long, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    if (m.size() < n)
    {
        return "BOYS";
    }
    return "GIRLS";
}

int main()
{
    long long arr[] = {1, 3, 2, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << PartyType(arr, n) << endl;
}