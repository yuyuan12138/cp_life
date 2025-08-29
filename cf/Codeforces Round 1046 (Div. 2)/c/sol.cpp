/**
 *      author:  yuyuan567
 *      created: 2025-08-29 14:18:25
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
        std::vector<int> a(n);
        std::vector<std::vector<int>> vec(n + 1);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            vec[a[i]].push_back(i);
        }
        std::vector<int> f(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (a[i] == 1) {
                    f[i] = 1;
                }
            } else {
                int sz = vec[a[i]].size();
                int idx = sz - a[i];
                if (idx < 0) {
                    f[i] = f[i - 1];
                } else {
                    int pos = vec[a[i]][idx];
                    if (pos == 0) {
                        f[i] = std::max(f[i - 1], a[i]);
                    } else {
                        f[i] = std::max(f[i - 1], f[pos - 1] + a[i]);
                    }
                }
            }
            ans = std::max(ans, f[i]);
        }

        std::cout << ans << '\n';
    }
    return 0;
}
