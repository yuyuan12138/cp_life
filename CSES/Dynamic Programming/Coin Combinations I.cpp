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
    vector<int> coins(n);
    
    for(auto& coin: coins) cin >> coin;
    vector<int> dp(target + 1);
    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        for(auto& coin: coins){
            if(i - coin >= 0){
                dp[i] += dp[i - coin];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[target] % mod << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}