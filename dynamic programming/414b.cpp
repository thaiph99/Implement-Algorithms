// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = (ll)a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int nax = 2*1e3+9;
const int mod = 1e9+7;
ll n, k, dp[nax][nax];
vector<int> a[nax];

ll sol(int n, int k)
{
    if(dp[n][k]!=-1)
        return dp[n][k];
    if(k==1)
        return 1;
    ll res=0;
    for(auto i : a[n])
        res=(res+sol(i,k-1))%mod;
    return dp[n][k]=res;
}

int main()
{
    iosb;
    for(int i=1; i<nax; i++)
        for(int j=i; j<nax; j+=i)
            a[j].push_back(i);
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    ll ans=0;
    FOR(i,1,n)
    ans=(ans+sol(i,k))%mod;
    cout<<ans<<endl;
    return 0;
}
