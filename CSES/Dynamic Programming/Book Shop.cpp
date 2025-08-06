/**
 *      author:  yuyuan567
 *      created: 2025-07-27 21:37:48
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
    int n, x; cin >> n >> x;
    vector<int> h(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    vector<vector<int>> dp(n + 1, vector<int> (x + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - h[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
            }
        }
    }
    cout << dp[n][x] << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}