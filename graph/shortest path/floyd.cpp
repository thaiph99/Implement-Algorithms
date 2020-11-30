
// by thaiph99
#include <bits/stdc++.h>
using namespace std;
// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pus push_back
#define pob pop_back
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e2 + 9;
vector<pii> graph[nax];
vector<vector<int>> dis(nax, vector<int>(nax, INT_MAX));
vector<vector<int>> par(nax, vector<int>(nax, 0));
int n, m, k, u, v, c, type;

void dijkstraPriority(int s)
{
    dis[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push({0, s});
    while (que.size() != 0)
    {
        int v = que.top().se;
        int dv = que.top().fi;
        que.pop();
        if (dv != dis[s][v])
            continue;
        for (auto e : graph[v])
        {
            int t = e.fi;
            int dt = e.se;
            if (dis[s][t] > dis[s][v] + dt)
            {
                dis[s][t] = dis[s][v] + dt;
                par[s][t] = v;
                que.push({dis[s][t], t});
            }
        }
    }
}

void printPath(int u, int v)
{
    vector<int> ans;
    while (par[u][v] != 0)
    {
        ans.push_back(v);
        v = par[u][v];
    }
    ans.push_back(u);
    reverse(begin(ans), end(ans));
    cout << ans.size() << " ";
    for (auto e : ans)
        cout << e << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);

    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    FOR(i, 1, n)
    dijkstraPriority(i);
    FOR(i, 1, k)
    {
        cin >> type >> u >> v;
        if (type)
            printPath(u, v);
        else
            cout << dis[u][v] << endl;
    }
    return 0;
}
