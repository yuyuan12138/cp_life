/**
 *      author:  yuyuan567
 *      created: 2025-08-18 11:04:08
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b;
    std::cin >> a >> b;
    std::vector<std::vector<int>> f(a + 1, std::vector<int> (b + 1));
    
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                f[i][j] = 0;
            } else {
                f[i][j] = 1e9;
                for (int k = 1; k < i; k++) {
                    f[i][j] = std::min(f[i][j], f[k][j] + f[i - k][j] + 1);
                }
                for (int k = 1; k < j; k++) {
                    f[i][j] = std::min(f[i][j], f[i][k] + f[i][j - k] + 1);
                }
            }
        } 
    }
    std::cout << f[a][b];
    return 0;
}
