// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

void player_1()
{
    cout << "Ashishgup" << endl;
}

void player_2()
{
    cout << "FastestFinger" << endl;
}

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int tc, n;

int main()
{
    cin >> tc;
    FOR(it, 1, tc)
    {
        cin >> n;
        bool lose = (n == 1);
        if (n > 2 && n % 2 == 0)
        {
            if ((n & (n - 1)) == 0)
                lose = 1;
            else if (n % 4 != 0 && isPrime(n / 2))
                lose = 1;
        }
        if (lose)
            player_2();
        else
            player_1();
    }
}