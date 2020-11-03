#include <iostream>
 
#define ll long long
using namespace std;
 
const int MAX_N = 6 * 1e5 + 1;
int fen[MAX_N], n;
 
void update(ll p, ll val)
{
    for (ll i = p; i; i -= i & -i)
        fen[i] += val;
}
ll getSum(ll p)
{
    ll ans = 0;
    for (ll i = p; i <= MAX_N - 2; i += i & -i)
    {
        // cout << "(" << (i & -i) << ")" << i << ":" << fen[i] << " ";
        ans += fen[i];
    }
    // cout << endl;
    return ans;
}
 
void show(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
 
int main(int argc, char const *argv[])
{
    // freopen("fenwickTree.txt", "r", stdin);
    cin >> n;
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        // cout << x << ":)" << endl;
        res += getSum(x + 1);
        update(x, 1);
        // show(fen, n);
        // cout << "res : " << res << endl;
    }
    cout << res << endl;
    return 0;
} 