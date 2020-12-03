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

int n, m, x, y;          // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

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

void dfs(int v, int p)
{
    visited[v] = true;
    tin[v] = low[v] = ++timer;
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
            if (low[to] > tin[v])
                cout << "bridge : " << v << "-" << to << endl;
        }
    }
}

void find_bridges()
{
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(1, 1);
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
    find_bridges();
    return 0;
}
