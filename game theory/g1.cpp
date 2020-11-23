// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int maxi=1e6+5;

int cnt[maxi],b[maxi];
int p,q,ans,n,t,tmp,xs,m;

void solve()
{
    scanf("%d",&n);
    xs=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&p);
        xs=xs^cnt[p];
    }
    if(xs==0) printf("2\n");
    else printf("1\n");
}

ll testt=0;
void sito()
{
    cnt[1]=0;
    for(int i=2; i<maxi; i++)
    {
        if(b[i]==0)
        {
            for(int j=i; j<maxi; j+=i)
            {
                m=j;
                b[j]=1;
                while(m%i==0)
                {
                    cnt[j]++;
                    m=m/i;
                    testt++;
                }
            }
        }
    }
}

int main()
{
    iosb;
    scanf("%d",&t);
    sito();
//    cout<<"O = "<<testt<<endl;
//    FOR(i,1,maxi-10)
//    cout<<i<<":"<<cnt[i]<<endl;
    while(t--)
        solve();
    return 0;
}
