// by thaiph99
#include <bits/stdc++.h>
using namespace std;

// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define pii pair<ll, ll>
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int maxn = 1e4;
vector<int> g[maxn], topo;
int slx;
int dd[maxn], visited[maxn], ans[maxn];

void DFS(int u)
{
    for (auto e : g[u])
        if (!visited[e])
            visited[e] = 1, DFS(e);
    topo.push_back(u);
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    int n, m, u, v;
    cin >> n >> m;
    int nn = n;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    FOR(i, 1, n)
    if (!visited[i])
        visited[i] = 1, DFS(i);
    reverse(begin(topo), end(topo));
    for (auto i : topo)
        cout << i << " ";
    cout << endl;
    return 0;
}
