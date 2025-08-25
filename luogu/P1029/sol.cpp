/**
 *      author:  yuyuan567
 *      created: 2025-08-23 06:11:36
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
    int x, y;
    std::cin >> x >> y;
    int64_t tot = 1LL * x * y;
    
    int ans = 0;
    for (int64_t i = 1; i * i <= tot; i++) {
        if (tot % i == 0 && std::gcd(i, tot / i) == x) {
            ans += 2;
            if (i * i == tot) {
                ans--;
            }
        }
        
    }
    std::cout << ans;
    return 0;
}
