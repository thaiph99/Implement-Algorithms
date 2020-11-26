// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

unsigned long long getPerfectNumber(int n)
{
    return (1ULL*pow(2,n-1)*(pow(2,n)-1));
}

const int N = 100;
int lp[N+1];

int main()
{
    // primes
    vector<int> pr;
    for(int i=2; i<=N; ++i)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    // cal
    for(auto &i:pr)
    {
        cout << getPerfectNumber(i)<<endl;
    }
    return 0;
}
