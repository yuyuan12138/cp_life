/**
 *      author:  yuyuan567
 *      created: 2025-08-07 01:28:05
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve() {
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        std::string a, b;
        std::cin >> a >> b;
        int l = -1, r = n;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                l += 1;
            } else {
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[n - i - 1] == b[m - i - 1]) {
                r -= 1;
            } else {
                break;
            }
        }
        if (r - l <= 1) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}