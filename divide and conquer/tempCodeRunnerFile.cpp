#include <bits/stdc++.h>
using namespace std;

int check(char prev, char prev_prev){

    int val = prev - '0' + 10*(prev_prev - '0');
    // cout << val << endl;
    if(val <= 26 && val >= 1){
        return true;
    }
    return false;
}

long long solve(string s, int n){
    vector<long long>dp(n+1);
    dp[0] = 1;
    if(s[1] != '0'){
        dp[1] += 1;
    }
    if(check(s[1], s[0]) && s[0] != '0'){
        // cout << "treu";
        dp[1] += 1;
    }
    for(int i = 2; i < n; i++){
        if(s[i] != '0')dp[i] += dp[i-1];
        if(check(s[i], s[i-1]) && s[i-1] != '0') {
            // cout << s[i-1] - '0' + 10*(s[i-2] - '0') << endl;
            dp[i] += dp[i-2];
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    return dp[n-1];

}


int main(){

    string s;
    while(cin >> s){
        if(s == "0") break;
        else{
            cout << solve(s, s.size()) << endl;
        }
    }
}