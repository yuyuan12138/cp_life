/**
 *      author:  yuyuan567
 *      created: 2025-08-05 21:08:20
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

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0x3f3f3f3f));
    // int l, r;
    std::vector<int> l(n), r(n);

    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
    }
    dp[0][0] = r[0] + r[0] - l[0] - 1;
    dp[0][1] = r[0] - 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = 1 +
            std::min(dp[i - 1][0] + std::abs(l[i - 1] - r[i]) + r[i] - l[i],
                     dp[i - 1][1] + std::abs(r[i - 1] - r[i]) + r[i] - l[i]);
        dp[i][1] = 1 +
            std::min(dp[i - 1][0] + std::abs(l[i - 1] - l[i]) + r[i] - l[i],
                     dp[i - 1][1] + std::abs(r[i - 1] - l[i]) + r[i] - l[i]);
    }

    std::cout << std::min(dp[n - 1][0] + n - l[n - 1], dp[n - 1][1] + n - r[n - 1]);

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}