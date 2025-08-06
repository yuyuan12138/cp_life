/**
 *      author:  yuyuan567
 *      created: 2025-07-27 00:31:40
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
    // 1e3, 2e3, 1e3
    ifstream read("time.in");
    int n, m, c; read >> n >> m >> c;
    vector<int> moonies(n + 1);
    for(int i = 1; i <= n; i++){
        read >> moonies[i];
    }
    // vector<vector<int>> g(n + 1, vector<int> (n + 1));
    vector<vector<int>> children(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        read >> u >> v;
        children[u].push_back(v);
    }
    const int MAX_DAYS = 1e3 + 1;
    vector<vector<int>> dp(n + 1, vector<int> (MAX_DAYS, -1));
    int ans = 0;
    dp[1][0] = 0;

    for(int day = 0; day < MAX_DAYS; day++){
        for(int i = 1; i <= n; i++){
            if(dp[i][day] == -1) continue;
            for(auto& child: children[i]){
                dp[child][day + 1] = max(dp[child][day + 1], dp[i][day] + moonies[child]);
            }
        }
        ans = max(ans, dp[1][day] - c * day * day);
    }
    ofstream("time.out") << ans << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}