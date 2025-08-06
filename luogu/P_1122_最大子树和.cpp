/**
 *      author:  yuyuan567
 *      created: 2025-08-06 00:55:53
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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = -2147483647;
    std::vector<int> dp(n);
    // for (int x = 0; x < n; x++) {
    [&](this auto&& self, int u, int pa) -> void {
        dp[u] = a[u];
        for (auto& v : edges[u]) {
            if (v == pa)
                continue;
            self(v, u);
            dp[u] += std::max(dp[v], 0);
        }
    }(0, -1);
    for (int i = 0; i < n; i++) {
        ans = std::max(dp[i], ans);
    }
    std::cout << ans << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}