/**
 *      author:  yuyuan567
 *      created: 2025-08-27 23:40:21
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
    int mn = a[n - 1];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        mn = std::min(mn, a[i]);
        ans += std::min(a[i], mn);
    }
    std::cout << ans;
    return 0;
}
