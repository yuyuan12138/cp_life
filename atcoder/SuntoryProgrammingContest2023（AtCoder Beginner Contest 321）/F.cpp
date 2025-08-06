/**
 *      author:  yuyuan567
 *      created: 2025-07-27 13:53:42
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
    const int mod = 998244353;
    int q, k; cin >> q >> k;
    vector<int> dp(k + 1);
    dp[0] = 1;
    while(q--){
        char type; int num; cin >> type >> num;
        if(type == '+'){
            for(int x = k; x >= num; x--){
                if(x - num >= 0){
                    dp[x] = (dp[x] + dp[x - num]) % mod;
                }
            }
        }else{
            for(int x = num; x <= k; x++){
                if(x - num >= 0){
                    dp[x] = (dp[x] - dp[x - num] + mod) % mod;
                }
            }
        }
        cout << dp[k] << "\n";
    }
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}