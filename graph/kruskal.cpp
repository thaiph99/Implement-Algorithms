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

const int nax = 1e6;
int par[nax];
int rak[nax];

struct edge
{
    int u, v, w;
};

bool cmp(edge &a, edge &b)
{
    return a.w < b.w;
}

int find(int u)
{
    if (par[u] != u)
        par[u] = find(par[u]);
    return par[u];
}

bool join(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return false;
    if (rak[u] == rak[v])
        rak[u]++;
    rak[u] < rak[v] ? par[u] = v : par[v] = u;
    return true;
}

int main(int argc, char const *argv[])
{
    iosb;
    //freopen("kruskal.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;
    sort(begin(edges), end(edges), cmp);
    FOR(i, 1, n)
    {
        par[i] = i;
        rak[i] = 0;
    }
    ll ans = 0, cnt = 0;
    for (auto &e : edges)
    {
        if (join(e.u, e.v))
            ans += e.w, cnt++;
        if (cnt == n)
            break;
    }
    cout << ans << endl;
    return 0;
}
