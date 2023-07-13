#include <iostream>
using namespace std;

string onesComplement(string s, int n)
{
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            temp += '0';
        }
        else
        {
            temp += '1';
        }
    }
    return temp;
}

int main()
{
    string s = "101";
    cout << "1's Compliment is : " << onesComplement(s, s.size()) << endl;
}