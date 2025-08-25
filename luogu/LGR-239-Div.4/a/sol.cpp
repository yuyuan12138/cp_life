/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:28:29
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
    int x, a, b, t;
    std::cin >> x >> a >> b >> t;
    x /= 60;
    if (x < 1) {
        std::cout << "0\n";
    } else if (x < 2) {
        std::cout << a << '\n';
    } else if (x < 4) {
        std::cout << b << '\n';
    } else {
        std::cout << t << '\n';
    }
    return 0;
}
