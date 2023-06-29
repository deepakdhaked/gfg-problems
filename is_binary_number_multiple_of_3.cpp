#include <iostream>
#include <set>
using namespace std;

int isDivisible(string s)
{
    int odd = 0, even = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int bit = s[i] - '0';
        if (i % 2 == 0)
        {
            even += bit;
        }
        else
        {
            odd += bit;
        }
    }
    int delta = abs(even - odd);
    if (delta % 3 == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    string s = "11101000111";
    int ans = isDivisible(s);
    if (ans == 1)
    {
        cout << "Divisible by 3" << endl;
    }
    else
    {
        cout << "Not Divisible by 3" << endl;
    }
}