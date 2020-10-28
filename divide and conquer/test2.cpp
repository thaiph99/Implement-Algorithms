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

#include <bits/stdc++.h>
using namespace std;
int n;
int isOk(char s1, char s2)
{
    int res = (s1 - '0') * 10 + (s2 - '0');
    return 'a' - 'a' + 1 <= res && res <= 'z' - 'a' + 1;
}

long long solve(string s)
{
    vector<long long> dp(n + 10, 0);
    dp[0] = 1, dp[1] = 1;
    FOR(i, 1, n - 1)
    {
        if ('1' <= s[i] && s[i] <= '9')
            dp[i + 1] += dp[i];
        if (isOk(s[i - 1], s[i]) && '1' <= s[i - 1] && s[i - 1] <= '9')
            dp[i + 1] += dp[i - 1];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s)
    {
        n = s.length();
        if (s == "0")
            break;
        cout << solve(s) << endl;
    }
}
