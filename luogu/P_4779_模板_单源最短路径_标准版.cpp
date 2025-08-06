/**
 *      author:  yuyuan567
 *      created: 2025-08-03 14:23:50
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

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    const int INF = INT32_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    const int n = graph.size();
    vector<int> dis(n, INF), vis(n, 0);
    dis[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto& [v, w] : graph[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back(make_pair(v, w));
    }

    auto res = dijkstra(graph, --s);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}