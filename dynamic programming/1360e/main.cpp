// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
int tc, n;
string a, b;
int solve()
{
    int res = 0;
    FOR(i, 0, n - 1)
    if (i < n && a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] == b[i + 1])
        res++, i++;
    else if (a[i] != b[i])
        res++;
    return res;
}

int main(int argc, char const *argv[])
{
    iosb;
    cin >> n >> a >> b;
    cout << solve() << endl;
    return 0;
}
