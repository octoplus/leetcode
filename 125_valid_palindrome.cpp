#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    if (s.size() <= 1)
        return true;
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        while (i < j && !isalnum(s[i]))
            i++;
        while (i < j && !isalnum(s[j]))
            j--;
        if (i == j)
            break;
        // cout<<s[i]<<","<<s[j]<<endl;
        if (tolower(s[i]) != tolower(s[j]))
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    // string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    string s;
    cin>>s;
    if (isPalindrome(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}