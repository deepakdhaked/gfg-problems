#include <iostream>
#include <set>
using namespace std;

int numSquareSum(int n)
{
    int squareSum = 0;
    while (n)
    {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

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

// Time Complexity: O(n*log(n)).
// Auxiliary Space: O(n) since using extra set for storage
bool isHappy2(int N)
{
    set<int> s;
    while (1)
    {
        N = numSquareSum(N);
        if (N == 1)
            return true;
        if (s.find(N) != s.end())
            return false;
        s.insert(N);
    }
}

int main()
{
    int n = 7;
    if (isHappy2(n) == true)
    {
        cout << "Happy Number" << endl;
    }
    else
    {
        cout << "Not a Happy Number" << endl;
    }
}