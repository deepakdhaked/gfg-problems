#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Time Complexity : O(N)
// Auxiliary Space : O(N)
queue<int> reverse(queue<int> q)
{
    stack<int> temp;
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
    return q;
}

// Reversing a Queue using Recursion :
// Instead of explicitly using stack goal can be achieved using recursion (recursion at backend will itself maintain stack)
void reverse2(queue<int> q)
{
    if (q.empty())
    {
        return;
    }

    int curr = q.front();
    q.pop();

    reverse2(q);

    q.push(curr);
}