/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:42:01
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
    int ans = 0;
    std::vector<int> p(n), j(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> j[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < n; i++) { 
        ans += std::max(0, s[i] - std::abs(p[i] - j[i]));
    }
    std::cout << ans;
    return 0;
}
