// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ull n;
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
    Matrix ans;
    FOR(i, 0, 1)
    ans.a[i][i] = 1;
    while (k > 0)
    {
        if (k % 2)
            ans = ans * a;
        a = a * a;
        k /= 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    Matrix a;
    a.a[0][0] = 0, a.a[0][1] = 1, a.a[1][0] = 1, a.a[1][1] = 1;
    Matrix ans = expo_power(a, n+1);
    cout << ((ans.a[1][0]%mod)*(ans.a[1][1]%mod))%mod << endl;
    return 0;
}

/*
submit in
https://codeforces.com/gym/102644
https://dmoj.ca/problem/fibonacci
*/
