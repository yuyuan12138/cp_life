/**
 *      author:  yuyuan567
 *      created: 2025-08-22 16:57:56
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
    int v, n;
    std::cin >> v >> n;
    std::vector<int> f(v + 1);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = v; j >= a[i]; j--) {
            f[j] = std::max(f[j], f[j - a[i]] + a[i]);
        }
    }
    std::cout << v - f[v] << '\n';
    return 0;
}
