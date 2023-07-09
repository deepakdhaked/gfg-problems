#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity : O(N * Log(N))
// Auxiliary Space : O(1)
long long smallestpositive(vector<long long> array, int n)
{
    sort(array.begin(), array.end());
    long long int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (array[i] <= ans)
            ans += array[i];
        else
            return ans;
    }
    return ans;
}

int main()
{
    vector<long long> v = {1, 10, 3, 11, 6, 15};
    cout << "the number is : " << smallestpositive(v, v.size()) << endl;
}