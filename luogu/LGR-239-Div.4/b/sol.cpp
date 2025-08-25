/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:31:57
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
    char x, y;
    int z;
    std::cin >> x >> y >> z;
    if (x == 'A') {
        if (y == 'N') {
            std::cout << "A320";
        } else {
            if (z == 2) {
                std::cout << "A350";
            } else {
                std::cout << "A380";
            }
        }
    } else if (x == 'B') {
        if (y == 'N') {
            std::cout << "B737";
        } else {
            if (z == 4) {
                std::cout << "B747";
            } else {
                std::cout << "B787";
            }
        }
    } else {
        std::cout << "C919";
    }
    return 0;
}
