
// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const ll nax = 1e2 + 9;
ll n;
vector<ll> pr;
const ll N = 1000000;
void sieveLinear()
{
    vector<ll> lp(N + 1);
    for (ll i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

ll genNum(ll a, ll b)
{
    string s = to_string(a) + to_string(b);
    ll ans = 0;
    FOR(i, 0, s.size() - 1)
    ans = ans * 10 + (s[i] - '0');
    return ans;
}

bool isOk(ll num)
{
    ll sqr = sqrt(num);
    int last = lower_bound(pr.begin(), pr.end(), sqr) - begin(pr);
    FOR(i, 0, last)
    if (num % pr[i] == 0)
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    iosb;
    sieveLinear();
    cout << pr[pr.size() - 1] << endl;
    cin >> n;
    ll cnt = 0;
    for (int i = 1; i <= pr.size() - 2; i += 2)
    {
        ll x = genNum(pr[i - 1], pr[i]);
        if (isOk(x))
            cnt++;
        if (cnt == n)
            return cout << x, 0;
    }
    return 0;
}