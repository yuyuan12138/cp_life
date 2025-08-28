/**
 *      author:  yuyuan567
 *      created: 2025-08-28 12:40:42
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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            f[j] = std::max(f[j], f[j - i - 1] + a[i]);
        }
    }
    std::cout << f[n];
    return 0;
}
