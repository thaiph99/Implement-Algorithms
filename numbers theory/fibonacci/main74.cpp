// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int m = 1e9+7;

pair<ll, ll> fib(ll n)
{
    if(n == 0)
        return {0, 1};
    auto p = fib(n/2);
    ll c = (p.first%m) * (((2 * p.second)%m - (p.first%m) + m)%m) %m;
    ll d = (((p.first%m) * (p.first %m) %m) + ((p.second%m) * (p.second%m) %m))%m;
    if(n%2)
        return {d, (c + d)%m};
    else
        return {c, d};
}

int main()
{
    ll t, n;
    cin>>n;
    auto ans = fib(n);
    cout<<ans.first<<endl;
    return 0;
}

/*
submit in
https://codeforces.com/gym/102644
https://dmoj.ca/problem/fibonacci
*/
