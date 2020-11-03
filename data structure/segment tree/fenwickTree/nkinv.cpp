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

const ll nax = 6 * 1e5 + 9;
ll n, x, ans, f[nax];

ll getx(ll x)
{
    ll res = 0;
    for (ll i = x; i >= 1; i -= i & -i)
        res += f[i];
    return res;
}

void updatex(ll x)
{
    for (ll i = x; i <= n; i += i & -i)
    {
        cout << i << ":" << f[i] << endl;
        f[i]++;
    }
}

void show()
{
    FOR(i, 1, n + 1)
    cout << f[i] << " ";
    cout << "--------" << endl;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> x;
        // ans += getx(x + 1);
        updatex(x);
        show();
    }
    cout << ans << endl;
    return 0;
}
