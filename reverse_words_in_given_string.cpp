#include <iostream>
#include <stack>
using namespace std;

string reverseWords(string s)
{
    stack<string> word_stack;
    string temp = "";
    for (char ch : s)
    {
        if (ch == '.')
        {
            word_stack.push(temp);
            temp.clear();
        }
        else
        {
            temp += ch;
        }
    }

    int n = word_stack.size();
    for (int i = 0; i < n; i++)
    {
        if (i < n)
        {
            temp += ".";
        }
        temp += word_stack.top();
        word_stack.pop();
    }
    return temp;
}

int main()
{
    string s = "i.like.this.program.very.much";
    cout << reverseWords(s) << endl;
}