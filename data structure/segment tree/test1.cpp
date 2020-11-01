#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a, b;
const ll base = 31;
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 9;
int n;

ll POW[maxn], hashT[maxn], hashP[maxn];
void build()
{
    for (int i = 1; i <= n; i++)
        POW[i] = (POW[i - 1] * base) % MOD;
    for (int i = 1; i <= (int)(a.length() - 1); i++)
        hashT[i] = (hashT[i - 1] * base + a[i] - '0' + 1) % MOD;
    for (int i = 1; i <= (int)(b.length() - 1); i++)
        hashP[i] = (hashP[i - 1] * base + b[i] - '0' + 1) % MOD;
}

ll getHashT(int i, int j, ll hashT[])
{
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

void show(int i, int j, string s)
{
    for (int ii = i; ii <= j; ii++)
        cout << s[ii];
    cout << "-";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> a >> b;
    string xx = a, yy = b;
    a = " " + a;
    b = " " + b;
    n = a.length();
    POW[0] = 1;
    build();
    ll ans1 = -1;
    for (int i = 1; i <= n - 1; i++)
    {
        if (getHashT(i, n - 1, hashT) == getHashT(1, n - i, hashP) && (n - i < (int)(b.length())))
        {
            ans1 = i;
            break;
        }
    }
    if (ans1 != -1)
        cout << string(begin(a) + 1, end(a)) << string(b.begin() + 1 + (n - ans1), b.end());
    else
        cout << xx << yy << endl;
}