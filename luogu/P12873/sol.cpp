/**
 *      author:  yuyuan567
 *      created: 2025-08-30 16:06:42
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
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int leaf = -1;
    int mx_dep = -1;
    [&](this auto&& self, int u, int pa, int dep) -> void {
        if (dep > mx_dep) {
            leaf = u;
            mx_dep = dep;
        }
        for (int v : adj[u]) {
            if (v == pa)
                continue;
            self(v, u, dep + 1);
        }
        return;
    }(0, -1, 0);
    int mx = 0;
    [&](this auto&& self, int u, int pa, int dep) -> void {
        mx = std::max(dep, mx);
        for (int v : adj[u]) {
            if (v == pa)
                continue;
            self(v, u, dep + 1);
        }
        return;
    }(leaf, -1, 0);
    std::cout << mx / 2 * 2 << '\n';
    return 0;
}
