// by thaiph99
#include <bits/stdc++.h>
using namespace std;

int reve(int a)
{
    int res = 0;
    while (a > 0)
    {
        res = res * 10 + a % 10;
        a = a / 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n, nn, ans = 0;
    cin >> n;
    for (int i = 9; i >= 2; i--)
        while (n % i == 0)
        {
            ans = ans * 10 + i;
            n = n / i;
        }
    if (n == 1)
        cout << reve(ans) << endl;
    else
        cout << -1 << endl;
}
