/**
 *      author:  yuyuan567
 *      created: 2025-07-27 21:30:49
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
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int t = i;
        int mx = 0;
        while(t){
            mx = max(mx, t % 10);
            t /= 10;
        }
        dp[i] = dp[i - mx] + 1;
    }
    
    cout << dp[n] << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}