/**
 *      author:  yuyuan567
 *      created: 2025-08-28 14:08:59
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
    int n = 40;
    std::vector<int64_t> a(n);
    for (int i = 0; i < 40; i++) {
        std::cin >> a[i];
    }
    int64_t sum = std::accumulate(a.begin(), a.end(), 0LL);
    std::vector<int64_t> f(sum + 1);
    for (int i = 0; i < 40; i++) {
        f[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        std::vector<int64_t> nf = f;
        for (int j = a[i]; j <= sum; j++) {
            nf[j] += f[j - a[i]];
        }
        f = nf;
    }
    int64_t ans = 0;
    for (int64_t i = 0; i <= sum; i++) {
        if (f[i]) {
            ans = std::max(ans, i * (sum - i));
        }
    }
    std::cout << ans;
    return 0;
}
