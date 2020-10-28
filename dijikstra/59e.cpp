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

/* ---------------------------------------------------------------------------- */

const int nax = 3 * 1e3 + 9;
vector<int> graph[nax], path;
map<pair<pii, int>, int> hashh;
int n, m, k, a, b, c, cnt, par[nax][nax];
pii ans;

void dijikstra3(int s)
{
    queue<pii> que;
    que.push({1, 1});
    ans = {-1, -1};
    while (!que.empty())
    {
        pii v = que.front();
        que.pop();
        if (v.se == n)
        {
            ans = v;
            break;
        }
        for (auto t : graph[v.se])
        {
            if (par[v.se][t] || hashh[{v, t}])
                continue;
            par[v.se][t] = v.fi;
            que.push({v.se, t});
        }
    }
    if (ans.fi == -1)
    {
        cout << -1;
        return;
    }
    while (ans.se != 1)
        path.pus(ans.se), ans = {par[ans.fi][ans.se], ans.fi};
    path.push_back(1);
    reverse(begin(path), end(path));
    cout << path.size() - 1 << endl;
    for (auto i : path)
        cout << i << " ";
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("59e.txt", "r", stdin);
    cin >> n >> m >> k;
    FOR(i, 1, m)
    {
        cin >> a >> b;
        graph[a].pus(b);
        graph[b].pus(a);
    }
    FOR(i, 1, k)
    {
        cin >> a >> b >> c;
        hashh[{{a, b}, c}]++;
    }
    dijikstra3(1);
    return 0;
}
