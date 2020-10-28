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

int n;
string s, a;

int main(int argc, char const *argv[])
{
    iosb;
    freopen("delstr.txt", "r", stdin);
    cin >> n >> s;
    FOR(i, 0, s.length() - 2)
    if (s[i] != s[i + 1])
        a.push_back(s[i]);
    cout << a << endl;
    return 0;
}
