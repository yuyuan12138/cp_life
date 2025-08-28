/**
 *      author:  yuyuan567
 *      created: 2025-08-28 14:51:51
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::vector<int>> vis(n, std::vector<int> (k + 1));

    auto self = [&](this auto&& self, int u, int step) -> void {
        if (step == k + 1 || vis[u][step]) {
            return ;
        }
        vis[u][step] = 1;
        for (int v: adj[u]) {
            self(v, step + 1);
        }
    };
    for (int i = 0; i < n; i++) {
        self(i, 0);
        for (int x = 1; x <= k; x++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (vis[j][x]) {
                    cnt++;
                }
            }
            std::cout << cnt << " ";
        }
        std::cout << "\n";
        for (int j = 0; j < n; j++) {
            for (int x = 0; x <= k; x++) {
                vis[j][x] = 0;
            }
        }
    }

    return 0;
}
