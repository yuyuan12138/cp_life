/**
 *      author:  yuyuan567
 *      created: 2025-07-27 12:24:21
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
    vector<int> dp(n + 1);
    dp[0] = 1;
    const int mod = 1e9 + 7;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    debug(dp);
    cout << dp[n] % mod << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}