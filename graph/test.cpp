// by thaiph99
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* ------------------------------------------------ */

const int nax = 1e5;
vector<int> g[nax], used(nax), low(nax), tin(nax);
int cutPoi, bri, t, n, m, u, v;
set<int> cutPoint;

void dfs(int v, int p = -1)
{
    used[v] = 1;
    tin[v] = low[v] = t++;
    int children = 0;
    for (int to : g[v])
    {
        if (to == p)
            continue;
        if (used[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bri++;
            if (low[to] >= tin[v] && p != -1)
            {
                cutPoi++;
                cutPoint.insert(v);
                // cout << "point : " << v << endl;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1)
    {
        cutPoint.insert(v);
        cutPoi++;
        // cout << "point : " << v << endl;
    }
}

int main()
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    FOR(i, 1, n)
    if (!used[i])
        dfs(i);

    cout << cutPoint.size() << " " << bri << endl;
    return 0;
}