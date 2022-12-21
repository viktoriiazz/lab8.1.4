#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int Count(const string s)
{
    if (s.length() < 4)
        return 0;

    int k = 0;

    for (int i = 0; s[i + 3] != 0; i++)
    {
        if (s.find(s[i], i + 1) == i + 1 &&
            s.find(s[i], i + 2) == i + 2 &&
            s.find(s[i], i + 3) == i + 3)
        {
            k++;
            i += 3;
        }
    }

    return k;
}

string Change(string& s)
{
    if (s.length() < 4)
        return s;

    for (int i = 0; s[i + 3] != 0; i++)
    {
        if (s.find(s[i], i + 1) == i + 1 &&
            s.find(s[i], i + 2) == i + 2 &&
            s.find(s[i], i + 3) == i + 3)
        {
            s.replace(i, 4, "**");
        }
    }

    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "String contained " << Count(str) << " groups of 4 same characters" << endl; string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}