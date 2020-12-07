// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int nax=1e3+9;
ll a[nax], n, dp[nax];
vector<ll> g[nax];
map<ll, ll> m;

ll dfs(ll n)
{
    if(dp[n])
        return dp[n];
    ll ans=0;
    for(auto i: g[n])
        ans=max(ans, dfs(i));
    return dp[n]=ans+1;
}

int main()
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++)
        m[a[i]]=i;
    for(int i=1; i<n; i++)
        for(ll j=i+1; j<=n; j++)
        {
            ll x = a[i]+a[j];
            g[m[x]].push_back(i), g[m[x]].push_back(j);
        }
    ll res=0;
    for(int i=1; i<=n; i++)
        res=max(res, dfs(i));
    cout<<res<<endl;
}
