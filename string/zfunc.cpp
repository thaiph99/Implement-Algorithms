// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string a, b;

vector<int> zFuc(string s)
{
    int n= int(s.length());
    vector<int> z(n+9);
    for(int i=1, l=0, r=0; i<n; i++)
    {
        if(i<=r)
            z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            z[i]++;
        if(i+z[i]-1>r)
            l=i, r=i+z[i]-1;
        cout<<i<<":"<<z[i]<<":"<<l<<":"<<r<<endl;
    }
    return z;
}

void showZ(vector<int> z)
{
    for(auto &i : z)
        cout <<i<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a;
    cin >> b;
    string s = b + "$" + a;
    ll n = s.length();
    vector<int> z = zFuc(s);
    showZ(z);
    for(int i=0;i<n;i++)
    {
        if(z[i]==b.length())
            cout<<i-b.length()<<" ";
    }
    return 0;
}
