/**
 *      author:  yuyuan567
 *      created: 2025-07-27 12:38:44
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
    int n, target; cin >> n >> target;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> dp(target + 1);
    for(int x = 1; x <= target; x++){
        dp[x] = 0x3f3f3f3f;
        for(auto coin: coins){
            if(x - coin >= 0){
                dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
    }
    debug(dp);
    if(dp[target] == 0x3f3f3f3f){
        cout << -1 << "\n";
        return ;
    }
    cout << dp[target] << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}