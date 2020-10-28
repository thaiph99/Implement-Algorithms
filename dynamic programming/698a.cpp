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

const int nax = 1e2 + 9;
int n, a[nax], tc;
vector<vector<int>> dp(nax, vector<int>(3, INT_MAX));

int main(int argc, char const *argv[])
{
    iosb;
    freopen("input.txt", "r", stdin);
    int x;
    cin >> n;
    FOR(i, 0, 2)
    dp[0][i] = 0;
    FOR(i, 1, n)
    {
        cin >> x;
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (x == 1 || x == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if (x == 2 || x == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}