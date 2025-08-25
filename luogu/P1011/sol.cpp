/**
 *      author:  yuyuan567
 *      created: 2025-08-22 16:54:32
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
    int a, n, m, x;
    std::cin >> a >> n >> m >> x;
    std::vector<int> f(n + 1);
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    std::cout << a * (f[x - 2] + 1) + (m - (f[n - 3] + 1) * a) / (f[n - 2] - 1) * (f[x - 1] - 1) << '\n';
    return 0;
}
