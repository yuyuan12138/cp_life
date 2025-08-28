/**
 *      author:  yuyuan567
 *      created: 2025-08-27 23:12:23
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
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }
        if (n == 1) {
            std::cout << "Yes\n";
        } else {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 != b[i] % 2) {
                    ok = false;
                } 
            }
            std::cout << (ok ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
