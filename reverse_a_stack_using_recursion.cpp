#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &s, int x)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();

        insert_at_bottom(s, x);
        s.push(temp);
    }
    else
    {
        s.push(x);
    }
}

void Reverse(stack<int> &s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();

        Reverse(s);

        insert_at_bottom(s, temp);
    }
}