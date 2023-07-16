#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string FirstNonRepeating(string s)
{
    int n = s.size();
    int frequency[26] = {0};
    queue<char> q;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        frequency[s[i] - 'a']++;
        q.push(s[i]);
        while (!q.empty())
        {
            if (frequency[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}