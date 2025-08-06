/**
 *      author:  yuyuan567
 *      created: 2025-08-06 00:39:02
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
    int n;
    std::cin >> n;
    std::vector<int> r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> r[i];
    }
    std::vector<int> pa(n, -1);
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        pa[u] = v;
        edges[v].push_back(u);
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (pa[i] == -1) {
            root = i;
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(2));

    [&](this auto&& self, int u, int pa) -> void {
        dp[u][1] = r[u];
        dp[u][0] = 0;
        for (auto v : edges[u]) {
            if (u == pa) {
                continue;
            }
            self(v, u);
            dp[u][0] += std::max({dp[v][0], dp[v][1], 0});
            dp[u][1] += dp[v][0];
        }
    }(root, -1);
    debug(dp);
    std::cout << std::max(dp[root][0], dp[root][1]);
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}