/**
 *      author:  yuyuan567
 *      created: 2025-07-27 13:35:12
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
    const int mod = 1e9 + 7;
    // cnt(x) = sum cnt(x - c_i)

    int n; cin >> n;
    int target; cin >> target;
    vector<int> coins(n + 1);  
    for(int i = 1; i <= n; i++){
        cin >> coins[i];
    }
    
    // for(auto& coin: coins) cin >> coin;
    // sort(all(coins), greater<int>());
    // vector<int> dp(target + 1);
    vector<vector<int>> dp(n + 1, vector<int> (target + 1));
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= target; x++){
            dp[i][x] = dp[i - 1][x] % mod;
            if(x - coins[i] >= 0)
                dp[i][x] += dp[i][x - coins[i]];
            dp[i][x] %= mod;
        }
    }

    cout << dp[n][target] % mod << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}