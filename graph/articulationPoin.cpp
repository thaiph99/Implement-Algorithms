// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define pii pair<ll, ll>
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void is_cutPoint(int v)
{
    cout << "Point : " << v << endl;
}

const int nax = 1e6;
int n, m, x, y, timer;   // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<int> visited(nax, -1), tin(nax, -1), low(nax, -1);
void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                is_cutPoint(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        is_cutPoint(v);
}

void show()
{
    cout << "index : ";
    FOR(i, 1, n)
    cout << i << " ";
    cout << endl;
    cout << "low   : ";
    FOR(i, 1, n)
    cout << low[i] << " ";
    cout << endl;
    cout << "tin   : ";
    FOR(i, 1, n)
    cout << tin[i] << " ";
    cout << endl;
}

void find_cutpoints()
{
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin >> n >> m;
    timer = 0;
    visited.assign(n, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    adj.assign(n + 1, vector<int>(0));
    FOR(i, 1, m)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_cutpoints();
    return 0;
}
