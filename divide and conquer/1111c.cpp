// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e5 + 9;
int n, k, a, b, f[nax];

ll solve(ll l, ll r)
{

    ll i = lower_bound(f + 1, f + k + 1, l) - (f + 1);
    ll j = upper_bound(f + 1, f + k + 1, r) - (f + 1);
    ll x = j - i;
    ll power = (x == 0 ? a : b * x * (r - l + 1));
    if (l == r || x == 0)
        return power;
    return min(power, solve(l, (l + r) / 2) + solve((l + r) / 2 + 1, r));
}

int main(int argc, char const *argv[])
{
    freopen("1111c.txt", "r", stdin);
    cin >> n >> k >> a >> b;
    ll nn = pow(2, n);
    FOR(i, 1, k)
    cin >> f[i];
    sort(f + 1, f + 1 + k);
    cout << solve(1, nn);
}
