/**
 *      author:  yuyuan567
 *      created: 2025-08-22 18:02:45
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
    int v, n, c;
    std::cin >> v >> n >> c;
    std::vector<int> f(c + 1), val(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> val[i] >> w[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = c; j >= w[i]; j--) {
            f[j] = std::max(f[j], f[j - w[i]] + val[i]);
        }
    }
    int ans = -1;
    debug(f);
    for (int i = 0; i <= c; i++) {
        if (f[i] >= v) {
            ans = std::max(ans, c - i);
        }
    }
    if (ans == -1) {
        std::cout << "Impossible"  << '\n';
    } else {
        std::cout << ans << '\n';
    }

    return 0;
}
