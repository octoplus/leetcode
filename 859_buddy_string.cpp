#include <bits/stdc++.h>

using namespace std;

bool buddyStrings(string A, string B)
{
    if (A.size() != B.size())
        return false;

    bool flag[200];
    memset(flag, 0, sizeof(flag));
    int l = -1, r = -1;
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != B[i])
        {
            if (count == 0)
            {
                count++;
                l = i;
            }
            else if (count == 1)
            {
                count++;
                r = i;
            }
            else
                return false;
        }
    }
    if (l >= 0 && r >= 0 && A[l] == B[r] && A[r] == B[l])
        return true;
    else if (l >= 0 || r >= 0)
        return false;
    else
    {
        for (char c : A)
        {
            if (!flag[c])
                flag[c] = true;
            else
                return true;
        }
        return false;
    }
}

int main()
{
    int N;
    cin>>N;
    string a,b;
    for(int i=0;i<N;i++){
        cin>>a;
        cin>>b;
        cout << buddyStrings(a,b) << endl;
    }
    // string A = "ab", B = "ab";
}