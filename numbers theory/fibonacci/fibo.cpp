// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll unsigned long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ull n, t;
const ll mod = 998244353;

struct Matrix
{
    ll a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        FOR(i, 0, 1)
        FOR(j, 0, 1)
        FOR(k, 0, 1)
        {
            product.a[i][k] += ((a[i][j]%mod) * (other.a[j][k]%mod))%mod;
            product.a[i][k] %= mod;
        }
        return product;
    }
};

Matrix expo_power(Matrix a, ull k)
{
    if(k==1)
        return a;
    Matrix t = expo_power(a, k/2);
    if(k&1)
        t=t*a;
    return t;
}

int main(int argc, char const *argv[])
{
//    cin >> t;
    Matrix a;
    a.a[0][0] = 0, a.a[0][1] = 1, a.a[1][0] = 1, a.a[1][1] = 0;
//    while(t--)
//    {
        cin>>n;
        Matrix ans = expo_power(a, n);
        cout << (ans.a[1][0]%mod) << endl;
//    }
    return 0;
}

/*
submit in
https://codeforces.com/gym/102644
https://dmoj.ca/problem/fibonacci
*/
