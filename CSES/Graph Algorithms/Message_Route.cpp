/**
 *      author:  yuyuan567
 *      created: 2025-08-07 15:36:21
 */
#include <bits/stdc++.h>


#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    
    std::vector<int> dis(n, INT32_MAX);
    std::vector<bool> vis(n, false);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});
    dis[0] = 0;
    std::vector<int> prev(n, -1);

    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int v: g[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                prev[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    if (dis[n - 1] == INT32_MAX) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        int x = n - 1;
        std::vector<int> ans;
        // ans.push_back(n - 1);
        while (x != -1) {
            ans.push_back(x);
            x = prev[x];
        }
        std::cout << ans.size() << "\n";
        for (int i = ans.size() - 1; i >= 0; i--) {
            std::cout << ans[i] + 1 << " ";
        }
        std::cout << "\n";
    }
    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}