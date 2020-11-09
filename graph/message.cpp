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

/* ---------------------------------------------------------------------------- */

const int nax = 8 * 1e2 + 9;
int visited[nax], check[nax];
vector<int> g[nax];

void dfs(int u)
{
    visited[u] = 1;
    for (auto v : g[u])
        if (!visited[v])
            dfs(v);
}

int main(int argc, char const *argv[])
{
    iosb;
    // freopen("INPUT.INP", "r", stdin);
    int n, m, u, v;
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    int cnt1 = 0, cnt2 = 0;
    FOR(i, 1, n)
    if (!visited[i])
        dfs(i), cnt1++;

    FOR(i, 1, n + 1)
    visited[i] = 0;

    FORR(i, n, 1)
    if (!visited[i])
        dfs(i), cnt2++;
    cout << min(cnt1, cnt2) << endl;
    return 0;
}
