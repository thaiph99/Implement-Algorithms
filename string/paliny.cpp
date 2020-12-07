// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll mod=1e9+7, base=31, nax=1e6+7;
vector<ll> p(nax), h(nax), r(nax);

ll get1(int i, int j)
{
    return (h[j]-h[i-1]*p[j-i+1]+mod*mod)%mod;
}

ll get2(int j, int i)
{
    return (r[i]-r[j+1]*p[j-i+1]+mod*mod)%mod;
}

bool isPalin(int i, int j)
{
    return get1(i,j)==get2(j,i);
}

int main()
{
    iosb;
    p[0]=1;
    FOR(i,1,n)
    p[i]=p[i-1]*base %mod;
    string s;
    cin>>s;
    s=" "+s;
    ll n = s.length();

    FOR(i,1,n)
    h[i]=(h[i-1]*base+s[i]-'a'+1)%mod;

    FORR(i,n,1)
    r[i]=(r[i+1]*base+s[i]-'a'+1)%mod;

    FOR(l,1,n)
}
