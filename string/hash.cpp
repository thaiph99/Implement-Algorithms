// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7, nax = 1e6+9, base = 31;
vector<ll> p(nax);

vector<ll> hashStr(string &s)
{
    ll n = s.length();
    s = " "+s;
    vector<ll> h(n+10);
    FOR(i,1,n)
    h[i]=(h[i-1]*base+s[i]-'a'+1)%mod;
    return h;
}

ll getHash(int i, int j, vector<ll> &h)
{
    return (h[j]-h[i-1]*p[j-i+1]+mod*mod)%mod;
}

int main()
{
    iosb;
    freopen("h.inp", "r", stdin);
    p[0]=1;
    FOR(i,1,nax-3)
    p[i] = (p[i-1]*base)%mod;
    string s1, s2;
    cin>>s1>>s2;
    vector<ll> h1 = hashStr(s1);
    vector<ll> h2 = hashStr(s2);
    ll n = s2.length(), m = s1.length();
    ll cmp = getHash(1,n-1,h2);
    for(int i=1; i<=m-n+1; i++)
        if(cmp==getHash(i,i+n-2,h1))
            cout<<i<<" ";
    return 0;
}
