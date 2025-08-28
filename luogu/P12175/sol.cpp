/**
 *      author:  yuyuan567
 *      created: 2025-08-28 14:32:11
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        std::vector<int> f(n);
        int cur = 0;
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int k = j - i; k >= 0; k -= i) {
                if (a[k] > a[k + i]) {
                    break;
                }
                mx = std::max(f[k], mx);
            }
            f[j] = std::max(f[j], mx + 1);
            cur = std::max(cur, f[j]);
        }
        ans = std::max(ans, cur);
    }
    std::cout << ans;
    return 0;
}
