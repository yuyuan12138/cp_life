/**
 *      author:  yuyuan567
 *      created: 2025-08-28 12:45:57
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
    int64_t n, k;
    std::cin >> n >> k;
    std::vector<int64_t> a(n);
    std::vector<int64_t> pref(n + 1);
    std::vector<int64_t> pref_pref_mn(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        pref_pref_mn[i] = std::min(pref_pref_mn[i - 1], pref[i]);
    }
    int64_t ans = INT64_MIN;
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, pref[n] + (pref[i] - pref_pref_mn[i - 1]) * (k - 1));
    }
    std::cout << ans;
    return 0;
}
