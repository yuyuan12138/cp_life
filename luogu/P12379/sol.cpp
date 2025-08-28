/**
 *      author:  yuyuan567
 *      created: 2025-08-28 14:02:39
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
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> f(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            f[i] = int(s[i] - 'a') + 1;
        } else if (i == 1) {
            f[i] = std::max(int(s[i] - 'a') + 1, int(s[i - 1] - 'a') + 1);
        } else {
            f[i] = std::max(f[i - 1], f[i - 2] + int(s[i] - 'a') + 1);
        }
    }
    std::cout << f[n - 1];
    return 0;
}
