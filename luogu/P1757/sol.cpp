/**
 *      author:  yuyuan567
 *      created: 2025-08-22 23:39:26
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
    int m, n;
    std::cin >> m >> n;
    std::map<int, std::vector<std::pair<int, int>>> items;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        items[c].push_back({a, b});
    }
    std::vector<int> f(m + 1);
    
    return 0;
}
