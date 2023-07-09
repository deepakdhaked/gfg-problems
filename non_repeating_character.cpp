#include <iostream>
#include <unordered_map>
using namespace std;

char nonrepeatingCharacter(string s)
{
    unordered_map<char, int> frequency;
    for (char i : s)
    {
        frequency[i]++;
    }
    for (char i : s)
    {
        if (frequency[i] == 1)
        {
            return i;
        }
    }
    return '$';
}

int main()
{
    string s = "zxvczbtxyzvy";
    char ans = nonrepeatingCharacter(s);
    if (ans == '$')
    {
        cout << "No non-repeating character" << endl;
    }
    else
    {
        cout << "the first non-repeating chararcter is : " << ans << endl;
    }
}