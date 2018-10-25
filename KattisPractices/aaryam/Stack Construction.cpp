#include <bits/stdc++.h>
using namespace std;

const int N = 205;

string s;
int dp[N][N];

int solve(int l, int r) {
    if(l > r) return 0;
    if(dp[l][r] != -1)  return dp[l][r];
    if(l == r) {
        dp[l][r] = 3;
        return dp[l][r];
    }
    dp[l][r] = INT_MAX;
    if(s[l] == s[r])  dp[l][r] = min(dp[l][r], 4 + solve(l + 1, r - 1));
    for(int i = l; i < r; i++) {
        dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r));
        if(s[i] == s[r])  dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r) - 2);
    }
    // cout<<l<<" "<<r<<" --> "<<dp[l][r]<<endl;
    return dp[l][r];
}

int main() {
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        memset(dp, -1, sizeof(dp));
        
        getline(cin, s);
        cout<<solve(0, s.length() - 1)<<endl;
    }
}

