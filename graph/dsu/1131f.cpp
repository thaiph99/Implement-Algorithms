// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= (int)(b); i++)
#define FORR(i, a, b) for (int i = a; i >= (int)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int nax=15*1e4+9;
ll n, par[nax], rak[nax], u, v;
vector<ll> g[nax];

int find(ll u)
{
    return par[u]==-1 ? u : par[u]=find(par[u]);
}

void join(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if(u==v)
        return;
    if(rak[u]<rak[v])
        swap(u,v);
    par[v]=u;
    g[u].push_back(v);
    if(rak[u]==rak[v])
        rak[u]++;
}

void dfs(ll uu)
{
    cout<<uu<<" ";
    for(auto &vv : g[uu])
        dfs(vv);
}

int main()
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin>>n;
    memset(par, -1, sizeof(par));
    FOR(i,1,n-1)
    {
        cin>>u>>v;
        join(u,v);
    }
    dfs(find(1));
}
