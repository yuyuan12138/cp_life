/**
 *      author:  yuyuan567
 *      created: 2025-07-27 14:51:49
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
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0x3f3f3f3f));
    dp[0][0] = 0;
    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            if(i > 0){
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }

            if(i > 0 && j > 0){
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
            }
            
        }
    }
    
    cout << dp[s1.size()][s2.size()];
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}