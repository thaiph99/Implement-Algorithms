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

ll mod = 1e9 + 7;

ll epow(ll x, ll y, ll m)
{
    // cout << x << ":" << y << endl;
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll tmp = epow(x, y / 2, m);
    if (y % 2 == 0)
        return ((tmp % m) * (tmp % m)) % m;
    else
        return ((((tmp % m) * (tmp % m)) % m) * x) % m;
}

int main()
{
    iosb;
    ll a, b, c, t;
    cin >> t;
    FOR(it, 1, t)
    {
        cin >> a >> b >> c;
        ll bc = epow(b, c, mod - 1);
        ll ans = epow(a, bc, mod);
        cout << ans << endl;
    }
}
