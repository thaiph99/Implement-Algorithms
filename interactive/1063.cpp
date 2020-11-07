// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int n;
bool ir(ll x, ll y)
{
    cout << x << " " << y << endl;
    fflush(stdout);
    string s;
    cin >> s;
    return s == "black";
}

int main()
{
    iosb;
    cin >> n;
    if (n == 1)
    {
        ir(0, 0);
        return cout << "0 1 1 1", 0;
    }
    ll l = 0, r = 1e9, m;
    bool an1 = ir(0, 0), an2, xuong;

    for (int i = 2; i <= n; i++)
    {
        m = (l + r) / 2;
        an2 = ir(m, 1);
        if (an2 == an1)
            l = m;
        else
            r = m;
        an2 = an1;
    }
    cout << l << " " << 0 << " " << r << " " << endl;
    return 0;
}
