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
const int nax = 2 * 1e5 + 9;
int tc, n;

void show(vector<vector<long long>> dp, int j)
{
    FOR(i, 0, n + 5)
    cout << setw(5) << dp[i][j];
    cout << endl;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("1373d.txt", "r", stdin);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n - 1)
        cin >> a[i];
        FOR(i, 0, n - 1)
        cout << setw(5) << a[i];
        cout << endl;
        vector<vector<long long>> dp(n + 9, vector<long long>(3));
        FOR(i, 0, n - 1)
        {
            dp[i + 1][0] = dp[i][0] + (i & 1 ? 0 : a[i]);
            if (i + 2 <= n)
                dp[i + 2][1] = max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]);
            dp[i + 1][2] = max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]);
        }
        show(dp, 0);
        show(dp, 1);
        show(dp, 2);
        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    }
    return 0;
}
