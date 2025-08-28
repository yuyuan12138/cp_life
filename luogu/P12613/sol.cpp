/**
 *      author:  yuyuan567
 *      created: 2025-08-28 13:47:27
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
    int r, c, m;
    std::cin >> r >> c >> m;
    auto query = [&] (int x, int y) -> int {
        return (x * c + y) % m + 1;
    };
    std::vector<int> f(c);
    for (int i = 0; i < c; i++) {
        f[i] = query(0, i);
    }
    for (int i = 1; i < r; i++) {
        std::vector<int> nf(c);
        for (int j = 0; j < c; j++) {
            nf[j] = query(i, j);
            int mn = f[j];
            if (j > 0) {
                mn = std::min(mn, f[j - 1]);
            }
            if (j < c - 1) {
                mn = std::min(mn, f[j + 1]);
            }
            nf[j] += mn;
        }
        f = nf;
    }
    int ans = INT32_MAX;
    for (int i = 0; i < c; i++) {
        ans = std::min(ans, f[i]);
    }
    std::cout << ans;
    return 0;
}
