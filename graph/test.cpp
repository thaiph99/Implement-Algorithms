// by thaiph99
#include <bits/stdc++.h>
using namespace std;

// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define pus push_back
#define pop pop_back
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* ------------------------------------------------ */

int main()
{
    string s;
    cin >> s;
    int ans = 0, cnt = 5;
    FOR(i, 0, s.length() - 2)
    {
        if (cnt == 0)
        {
            ans++, cnt = 5;
            cout << i << endl;
        }
        if (s[i] == s[i + 1])
            cnt--;
        else
        {
            cnt = 5, ans++;
            cout << i << endl;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}