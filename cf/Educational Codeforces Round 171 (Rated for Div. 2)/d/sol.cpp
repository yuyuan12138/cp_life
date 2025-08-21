/**
 *      author:  yuyuan567
 *      created: 2025-08-21 16:13:32
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
    std::vector<int64_t> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    std::vector<int64_t> pref_pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref_pref[i + 1] = pref_pref[i] + pref[i + 1];
    }
    std::vector<int64_t> pref_pref_pref(n + 1);
    std::vector<int64_t> pref_sz(n + 1);
    for (int i = 0; i < n; i++) {
        pref_sz[i + 1] = pref_sz[i] + n - i;
        pref_pref_pref[i + 1] = pref_pref_pref[i] - pref[i] * n + pref_pref[n];
    }

    auto query = [&](int64_t x) -> int64_t {
        auto it = std::lower_bound(pref_sz.begin(), pref_sz.end(), x); 
        int64_t idx = std::distance(pref_sz.begin(), it);
        if (idx == 0) {
            return 0;
        }
        int64_t last_x = x - pref_sz[idx - 1]; 
        int64_t res = 0;
        res += pref_pref_pref[idx - 1];
        res += pref_pref[last_x + idx - 1] - pref_pref[idx - 1];
        debug(last_x); debug(idx);
        return res;
    };
    int q;
    std::cin >> q;
    while (q--) {
        int64_t l, r;
        std::cin >> l >> r;

        std::cout << query(r) - query(l - 1) << '\n';
    }
    return 0;
}
