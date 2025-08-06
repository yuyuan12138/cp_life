/**
 *      author:  yuyuan567
 *      created: 2025-07-27 14:34:30
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> grids(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= n; j++){
            if(s[j - 1] == '*'){
                grids[i][j] = 1;
            }
        }
    }
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    dp[1][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grids[i][j]) continue;
            dp[i][j] = dp[i - 1][j] * (grids[i - 1][j] != 1) + dp[i][j - 1] * (grids[i][j - 1] != 1);
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][n] % mod;
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}