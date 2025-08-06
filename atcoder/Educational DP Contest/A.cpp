/**
 *      author:  yuyuan567
 *      created: 2025-07-26 15:29:22
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
    vector<int> heights(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> heights[i];
    }
    vector<int> dp(n + 1);
    dp[2] = abs(heights[2] - heights[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    cout << dp[n] << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}