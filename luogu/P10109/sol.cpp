/**
 *      author:  yuyuan567
 *      created: 2025-08-30 15:39:09
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
    std::vector<int> pa(n);
    for (int i = 1; i < n; i++) {
        std::cin >> pa[i];
    }
    std::vector<int> cnt(n);
    auto dfs = [&](this auto&& self, int u) -> void {
        cnt[u]++;
        if (pa[u] == u)
            return;
        self(pa[u]);
    };
    int q;
    std::cin >> q;
    while (q--) {
        cnt.assign(n, 0);
        int m;
        std::cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            std::cin >> x;
            dfs(x);
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= m) {
                mx = std::max(mx, i);
            }
        }
        std::cout << mx << '\n';
    }
    return 0;
}
