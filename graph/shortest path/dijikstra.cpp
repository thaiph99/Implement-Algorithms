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
#define pob pop_back
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* ---------------------------------------------------------------------------- */

const int nax = 1e5 + 9;
vector<pii> graph[nax];
vector<ll> dis(nax, LLONG_MAX);
vector<int> par(nax, 0);
int n, m, x, y, z;

void find(int s)
{
    if (par[s] != 0)
        find(par[s]);
    cout << s << " ";
}

void dijkstraSet(int s)
{
    dis[s] = 0;
    set<pii> sett;
    sett.insert({0, s});
    while (!sett.empty())
    {
        int v = begin(sett)->se;
        sett.erase(begin(sett));
        for (auto e : graph[v])
        {
            int to = e.fi, wei = e.se;
            if (dis[v] + wei < dis[to])
            {
                sett.erase({dis[to], to});
                dis[to] = dis[v] + wei;
                par[to] = v;
                sett.insert({dis[to], to});
            }
        }
    }
}

void dijkstraPriority(int s)
{
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push({0, s});
    while (!que.empty())
    {
        int v = que.top().se;
        cout << v << endl;
        int dv = que.top().fi;
        que.pop();
        if (dv != dis[v])
            continue;
        for (auto e : graph[v])
        {
            int t = e.fi;
            int dt = e.se;
            if (dis[t] > dis[v] + dt)
            {
                dis[t] = dis[v] + dt;
                par[t] = v;
                que.push({dis[t], t});
            }
        }
    }
    find(n);
}

void dijikstra3(int s)
{
    priority_queue<int> que;
    dis[s] = 0;
    que.push(1);
    while (!que.empty())
    {
        int v = que.top();
        que.pop();
        for (auto e : graph[v])
        {
            int t = e.fi, dt = e.se;
            if (dis[t] > dis[v] + dt)
            {
                dis[t] = dis[v] + dt;
                par[t] = v;
                que.push(t);
            }
        }
    }
    if (dis[n] == LLONG_MAX)
        cout << -1 << endl;
    else
        find(n);
}

int main()
{
    iosb;
    freopen("dijk.txt", "r", stdin);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    // dijkstraSet(1);
    dijkstraPriority(1);
    // if (dis[n] == LLONG_MAX)
    //     return cout << -1, 0;
    // vector<int> path;
    // for (int v = n; v != 1; v = par[v])
    //     path.pus(v);
    // path.pus(1);
    // reverse(path.begin(), path.end());
    // for (auto e : path)
    //     cout << e << " ";
    // dijikstra3(1);
    return 0;
}
