/**
 *      author:  yuyuan567
 *      created: 2025-08-28 16:29:25
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
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, P, Q;
        std::cin >> n >> P >> Q;
        int sum = 0;
        std::vector<int> p(n), q(n);
        for (int i = 0; i < n; i++) {
            std::cin >> p[i] >> q[i];
            sum += q[i];
        }
        std::vector<int> f(std::min(sum + 1, Q + 1));
        for (int i = 0; i < n; i++) {
            std::vector<int> nf = f;
            for (int j = q[i]; j <= std::min(sum, Q); j++) {
                nf[j] = std::max(nf[j], f[j - q[i]] + p[i]);
            }
            f = nf;
        }  
        int ans = -1;
        for (int i = 0; i <= std::min(Q, sum); i++) {
            if (f[i] >= P) {
                ans = i;
                break;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
