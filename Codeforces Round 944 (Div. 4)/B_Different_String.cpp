/**
 *      author:  yuyuan567
 *      created: 2025-08-03 16:22:06
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
    bool f = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            f = false;
        }
    }
    if (f) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) {
                swap(s[i], s[i + 1]);
                cout << "YES\n";
                cout << s << "\n";
                return;
            }
        }
    }
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