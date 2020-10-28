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

struct edge
{
    int u, v, w;

    edge(int uu, int vv, int ww)
    {
        u = uu, v = vv, w = ww;
    }
};

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

const int nax = 3 * 1e3 + 9;
int par[nax], rak[nax], n, x;

int find(int u)
{
    if (par[u] != u)
        par[u] = find(par[u]);
    return par[u];
}

bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (rak[u] == rak[v])
        rak[u]++;
    rak[u] > rak[v] ? par[v] = u : par[u] = v;
    return true;
}

int main(int argc, char const *argv[])
{
    iosb;
    //freopen("fwater.txt", "r", stdin);
    cin >> n;
    vector<edge> edges;
    FOR(i, 1, n)
    {
        cin >> x;
        edges.pus(edge(0, i, x));
        edges.pus(edge(i, 0, x));
    }
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        cin >> x;
        if (i != j)
            edges.pus(edge(i, j, x));
    }
    sort(begin(edges), end(edges), cmp);

    FOR(i, 0, n)
    par[i] = i;

    ll ans = 0, cnt = 0;
    for (auto e : edges)
    {
        if (join(e.u, e.v))
            ans += e.w;
        if (cnt == n)
            break;
    }
    cout << ans << endl;
    return 0;
}
