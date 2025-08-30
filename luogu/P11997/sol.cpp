/**
 *      author:  yuyuan567
 *      created: 2025-08-30 23:07:25
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
    std::vector<int> a(n), b(m), c(k);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < k; i++) {
        std::cin >> c[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < k; z++) {
                mx = std::max(mx, a[i] * b[j] % c[z]);
            }
        }
    }
    std::cout << mx;
    return 0;
}
