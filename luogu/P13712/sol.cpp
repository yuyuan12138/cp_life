/**
 *      author:  yuyuan567
 *      created: 2025-08-30 22:50:06
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
        int mn = INT32_MAX;
        int x, y, a, b, c, d;
        std::cin >> x >> y >> a >> b >> c >> d;
        if (x == y) {
            std::cout << "0\n";
            continue;
        }
        if ((x & a) == y) {
            mn = std::min(mn, c);
        }
        if ((x | b) == y) {
            mn = std::min(mn, d);
        }
        if (((x & a) | b) == y || ((x | b) & a) == y) {
            mn = std::min(mn, c + d);
        }
        std::cout << (mn != INT32_MAX ? mn : -1) << '\n';
    }
    return 0;
}
