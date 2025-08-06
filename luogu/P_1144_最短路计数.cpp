/**
 *      author:  yuyuan567
 *      created: 2025-08-03 15:06:11
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
constexpr int MOD = 100003;

vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int source) {
    int n = g.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dis(n, 0x3f3f3f3f), vis(n, 0), ans(n, 0);
    dis[source] = 0;
    pq.push({0, source});
    ans[source] = 1;
    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;
        for (auto& [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
                ans[v] = ans[u];
            } else if (dis[v] == dis[u] + w) {
                ans[v] = (ans[u] + ans[v]) % MOD;
            }
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    auto ans = dijkstra(g, 0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] % MOD << '\n';
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}