/**
 *      author:  yuyuan567
 *      created: 2025-08-16 19:23:48
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
**/
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    DSU dsu(n);
    std::vector<std::array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        dsu.merge(u, v);
        edges[i] = {u, v, w};
    }
    std::set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(dsu.find(i));
    }
    if (st.size() > k || n < k) {
        std::cout << "No Answer";
    } else {
        std::vector<int> idx(m);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int x, int y) -> bool {
            if (edges[x][2] == edges[y][2]) {
                return true;
            } else {
                return edges[x][2] < edges[y][2];
            }
                });
        dsu.init(n);
        int cnt = n;
        int ans = 0;
        if (k == n) {
            std::cout << "0";
        } else {
            for (auto i: idx) {
                if (dsu.merge(edges[i][0], edges[i][1])) {
                    ans += edges[i][2];
                    cnt--;
                }
                if (cnt == k) {
                    break;
                }
        }
        std::cout << ans;

        }
        
    }
    return 0;
}
