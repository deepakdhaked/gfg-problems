#include <iostream>
#include <stack>
using namespace std;

string reverse(string s)
{
    stack<char> char_stack;
    for (char ch : s)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            char_stack.push(ch);
        }
    }
    string ans = "";
    for (char ch : s)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            ans += char_stack.top();
            char_stack.pop();
        }
        else
        {
            ans += ch;
        }
    }
    return ans;
}

int main()
{
    string s = "A&x#";
    cout << reverse(s) << endl;
}