/**
 *      author:  yuyuan567
 *      created: 2025-08-28 23:52:29
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
    int n;
    std::cin >> n;
    std::vector<int> c(n), x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i] >> x[i];
    }
    std::vector<int> ans(n, INT32_MAX);
    int cur = -1;
    for (int i = 1; i < n; i++) {
        if (c[i] == c[i - 1] && cur != -1) {
            cur += x[i] - x[i - 1];
            ans[i] = std::min(ans[i], cur);
        } else {
            if (c[i] == c[i - 1]) {
                continue;
            } else {
                cur = x[i] - x[i - 1];
                ans[i] = std::min(ans[i], cur);
            }
        }
    }
    debug(ans);
    return 0;
}
