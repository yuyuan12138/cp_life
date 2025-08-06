/**
 *      author:  yuyuan567
 *      created: 2025-07-26 23:39:49
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
    ifstream in("hps.in");
    ofstream out("hps.out");
    int n, k; in >> n >> k;
    vector<int> gestures(n + 1);
    map<char, int> mp;
    mp['H'] = 0, mp['S'] = 1, mp['P'] = 2;
    for(int i = 1; i <= n; i++){
        char c; in >> c;
        gestures[i] = mp[c];
    }
    // vector<char> mp = {'0', 'H', 'S', 'P'};
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(4, 0)));
    int ans = 1;
    if(gestures[1] == 0){
        dp[1][0][2] = 1;
    }
    if(gestures[1] == 1){
        dp[1][0][0] = 1;
    }
    if(gestures[1] == 2){
        dp[1][0][1] = 1;
    }
    
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int who = 0; who <= 2; who++){
                dp[i][j][who] = dp[i - 1][j][who];
                if (j > 0){
                    dp[i][j][who] = max(dp[i][j][who],
                                max(dp[i][j - 1][(who + 1) % 3],
                                    dp[i][j - 1][(who + 2) % 3])
                    );
                }
                
                if(who == 0 && gestures[i] == 1){
                    dp[i][j][who]++;
                }
                if(who == 1 && gestures[i] == 2){
                    dp[i][j][who]++;
                }
                if(who == 2 && gestures[i] == 0){
                    dp[i][j][who]++;
                }
                ans = max(ans, dp[i][j][who]);
            }
        }
    }
    // debug(dp);
    out << ans << "\n";
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}