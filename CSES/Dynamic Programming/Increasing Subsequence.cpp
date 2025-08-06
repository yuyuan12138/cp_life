/**
 *      author:  yuyuan567
 *      created: 2025-07-27 15:54:03
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

void solve() {
    int n;
    cin >> n;
    vector<int> dp;
    while (n--) {
        int x;
        cin >> x;
        int pos = lower_bound(all(dp), x) - dp.begin();
        if (pos == dp.size()) {
            dp.push_back(x);
        } else {
            dp[pos] = x;
        }
    }
    cout << dp.size();
    return;
}

int main() {
    speedup();
    solve();
    return 0;
}