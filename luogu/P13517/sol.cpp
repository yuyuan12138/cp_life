/**
 *      author:  yuyuan567
 *      created: 2025-08-28 12:30:18
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
    bool ok = true;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i > 0 && a[i] == a[i - 1] + 1) {
            ok = false;
        }
    }
    if (!ok) {
        std::cout << "-1";
    } else {
        std::vector<int> grids(a[n - 1] + 3);
        for (int i = 0; i < n; i++) {
            grids[a[i]] = 1;
        }
        std::vector<int> f(a[n - 1] + 2);
        if (grids[1] == 1) {
            f[1] = 0;
        } else {
            f[1] = 1;
        }
        for (int i = 2; i <= a[n - 1] + 1; i++) {
            if (grids[i] == 1) {
                f[i] = 0;
            } else {
                if (grids[i - 1] == 1) {
                    f[i] = f[i - 2] + 1;
                } else {
                    if (grids[i - 2] == 1) {
                        f[i] = f[i - 1] + 1;
                    } else {
                        f[i] = std::min(f[i - 1], f[i - 2]) + 1;
                    }
                }
            }
        }
        std::cout << f[a[n - 1] + 1];
    }
    
    return 0;
}
