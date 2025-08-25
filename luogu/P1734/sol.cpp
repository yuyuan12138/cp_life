/**
 *      author:  yuyuan567
 *      created: 2025-08-22 23:19:15
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
    std::vector<int> f(n + 1);
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                f[i] += j;
            }
        }
    }
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            dp[j] = std::max(dp[j], dp[j - i] + f[i]);
        }
    }
    debug(f); debug(dp);
    std::cout << dp[n];
    return 0;
}
