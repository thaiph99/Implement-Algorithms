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

string s1, s2;

bool solve(string &a, string &b)
{
    int n = a.size();
    if (n == 1)
        return a == b;
    if (a == b)
        return true;
    if (n == 0 || n & 1)
        return false;
    int mid = n & 1 ? n / 2 + 1 : n / 2;
    int mid1 = n & 1 ? mid - 1 : mid;
    string a1 = string(begin(a), begin(a) + mid), a2 = string(begin(a) + mid1, end(a));
    string b1 = string(begin(b), begin(b) + mid), b2 = string(begin(b) + mid1, end(b));
    return (solve(a2, b1) && solve(a1, b2)) || (solve(a1, b1) && solve(a2, b2));
}

int main(int argc, char const *argv[])
{
    iosb;
    // freopen("559b.txt", "r", stdin);
    cin >> s1 >> s2;
    cout << (solve(s1, s2) ? "YES" : "NO") << endl;
    return 0;
}
