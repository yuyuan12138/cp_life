/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:58:55
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
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> Y(n, std::vector<int> (n)), T(n, std::vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            std::cin >> w;
            Y[i][j] = w;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            std::cin >> w;
            T[i][j] = w;
        }
    }
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        int c1;
        if (Y[u][v] != -1) {
            c1 = Y[u][v];
        } else {
            c1 = 1e9 + 3;
        }
        int c2 = 1e9 + 3;
        for (int i = 0; i < n; i++) {
            if (i == v || i == u) continue;
            if (T[u][i] == -1 || T[i][v] == -1) continue;
            c2 = std::min(c2, T[u][i] + T[i][v]);
        }
        int ans = std::min(c1, c2);
        if (ans == 1e9 + 3) {
            std::cout << -1 << '\n';
        } else {
            std::cout << ans << '\n';
        }
    }
    return 0;
}
