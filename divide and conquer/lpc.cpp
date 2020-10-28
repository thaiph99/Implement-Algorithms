// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

string getCommonPrefix(string s1, string s2)
{
    string res;
    for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++)
        if (s1[i] != s2[j])
            return res;
        else
            res.push_back(s1[i]);
    return res;
}

string solve(string a[], int left, int right)
{
    if (left == right)
        return a[left];
    if (left < right)
    {
        int mid = (left + right) / 2;
        string s1 = solve(a, left, mid);
        string s2 = solve(a, mid + 1, right);
        return getCommonPrefix(s1, s2);
    }
    return "";
}

int main(int argc, char const *argv[])
{
    string a[] = {"11122233", "11123442", "11122222"};
    int n = sizeof(a) / sizeof(string);
    cout << n << endl;
    cout << solve(a, 0, n - 1);
    return 0;
}
