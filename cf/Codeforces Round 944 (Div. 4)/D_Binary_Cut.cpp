/**
 *      author:  yuyuan567
 *      created: 2025-08-03 16:29:25
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
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int slow = 0;
    char type = s[0];
    int ans = 1;
    bool flag = false;
    for (int fast = 0; fast < n; fast++) {
        if (s[fast] != type) {
            if (s[fast] == '1' && type == '0') {
                flag = true;
            }
            type = s[fast];
            ans += 1;
        }
    }
    cout << ans - flag << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}