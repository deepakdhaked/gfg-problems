#include <iostream>
using namespace std;

// Time Complexity: O(n*log(n)).
// Auxiliary Space: O(1)
bool isHappy(int N)
{
    if (N == 1 || N == 7)
    {
        return true;
    }

    int sum = N, curr = N;
    while (sum > 9)
    {
        sum = 0;
        while (curr > 0)
        {
            int d = curr % 10;
            sum += d * d;
            curr /= 10;
        }
        if (sum == 1)
        {
            return true;
        }
        curr = sum;
    }
    if (sum == 7)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 12;
    if (isHappy(n) == true)
    {
        cout << "Happy Number" << endl;
    }
    else
    {
        cout << "Not a Happy Number" << endl;
    }
}