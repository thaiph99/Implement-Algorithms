// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define ii pair<ll, ll>

vector<ii> a(8);
map<ii, int> m;

ll dis(int i1, int i2)
{
    ii p1 = a[i1], p2 = a[i2];
    return pow(p1.fi-p1.fi, 2)+pow(p1.se-p2.se, 2);
}

bool isSqua()
{
    return dis(0,1)==dis(1,2) && dis(1,2)==dis(2,3) && dis(2,3)==dis(3,0);
}

bool isRec()
{
    return dis(4,5)==dis(6,7) && dis(5,6)==dis(7,4) && dis(4,6)==dis(5,7);
}

int main()
{
    iosb;
    freopen("b.inp", "r", stdin);
    int cnt=1;
    for(auto &i:a)
    {
        cin>>i.first>>i.second;
        m[i]=cnt++;
    }
    sort(a.begin(), a.end());
    do
    {
        if(isSqua() && isRec())
        {
            cout<<"YES"<<endl;
            FOR(i,0,3)
            cout<<m[a[i]]<<" ";
            cout<<endl;
            FOR(i,4,7)
            cout<<m[a[i]]<<" ";
            cout<<endl;
        }

    }
    while(next_permutation(a.begin(), a.end()));
    cout<<"NO";
    return 0;
}
