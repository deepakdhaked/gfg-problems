#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string a, string b)
{
    if (a.length() == b.length())
    {
        vector<int> alphabets(26);
        for (int i = 0; i < a.length(); i++)
        {
            alphabets[a[i] - 'a']++;
            alphabets[b[i] - 'a']--;
        }
        for (auto i : alphabets)
        {
            if (i)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    string a = "geeksforgeeks", b = "forgeeksgeeks";
    if (isAnagram(a, b) == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}