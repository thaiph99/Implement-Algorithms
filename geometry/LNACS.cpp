//thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int nax = 1e3+9;
int a[nax], b[nax], f[nax][nax], n, m;

int main()
{
    iosb;
    cin>>n>>m;
    FOR(i,1,n)
    cin>>a[i];
    FOR(i,1,m)
    cin>>b[i];
    FOR(i,2,n+1)
    FOR(j,2,m+1)
    f[i][j]= (a[i-1]==b[j-1] ? f[i-2][j-2]+1 : max(f[i-1][j],f[i][j-1]));
    cout<<f[n+1][m+1]<<endl;
}
