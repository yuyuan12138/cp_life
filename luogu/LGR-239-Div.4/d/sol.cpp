/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:39:15
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int m;
            std::cin >> m;
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || j == m - 1) {
                    ans++;
                } else {
                    if ((i + 1) * (j + 1) % 10 == 6) {
                        ans++;
                    }
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
