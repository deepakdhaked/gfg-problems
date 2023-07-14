#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

void deleteMid(stack<int> &s, int n)
{
    stack<int> temp;
    int mid = ceil(n / 2);

    while (mid--)
    {
        temp.push(s.top());
        s.pop();
    }

    s.pop();
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}