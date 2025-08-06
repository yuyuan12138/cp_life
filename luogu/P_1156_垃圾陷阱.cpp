/**
 *      author:  yuyuan567
 *      created: 2025-08-06 00:05:56
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

struct Item {
    int t, f, h;
};

void solve() {
    int h, n;
    std::cin >> h >> n;
    std::vector<Item> itmes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].t >> items[i].f >> items[i].h;
    }
    std::sort(all(items), [](Item& a, Item& b) { return a.t ^ b.t ? a.t < b.t : a.f < b.f });

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}