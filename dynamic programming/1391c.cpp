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

ll solve(ll x, map<ll, ll> &dp)
{
    if (x == 1)
        return 1;
    if (x == 0)
        return 0;
    if (dp[x] != 0)
        return dp[x];
    return dp[x] = max(x, solve(x / 2, dp) + solve(x / 3, dp) + solve(x / 4, dp));
}

int main()
{
    iosb;
    // freopen("input.txt", "r", stdin);
    ll x;
    while (cin >> x)
    {
        map<ll, ll> dp;
        cout << solve(x, dp) << endl;
    }
    return 0;
}