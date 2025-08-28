/**
 *      author:  yuyuan567
 *      created: 2025-08-27 23:08:09
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
        int n;
        std::cin >> n;
        if (n % 3 == 2) {
            std::cout << n / 3 * 2 + 1 << '\n';
        } else if(n % 3 == 1) {
            std::cout << n / 3 * 2 << '\n';
        } else {
            std::cout << n / 3 * 2 << '\n';
        }
    }
    return 0;
}
