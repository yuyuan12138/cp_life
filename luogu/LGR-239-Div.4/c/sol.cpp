/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:36:41
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
    int cnt1 = 0, cnt2 = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        if (x == 1) ok = false;
        if (ok) {
            if (x == 0) {
                cnt1++;
            } 
            cnt2++;
        }
    }
    std::cout << cnt2 << ' ' << cnt1 << '\n';
    return 0;
}
