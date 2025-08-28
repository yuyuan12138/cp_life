/**
 *      author:  yuyuan567
 *      created: 2025-08-28 16:41:54
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
        int n, m, x;
        std::cin >> n >> m >> x;
        std::vector<std::string> grids(n);
        for (int i = 0; i < n; i++) {
            std::cin >> grids[i];
        }
        std::vector<std::vector<std::vector<int>>> f(n, std::vector<std::vector<int>> (m, std::vector<int> (x + 1)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= x; k++) {
                    if (i == 0 && j == 0) {
                        if (grids[i][j] == '?') {
                            if (k >= 1) {
                                f[i][j][k] = 1;
                            }
                        } else {
                            f[i][j][k] = (grids[i][j] == '1' ? 1 : 0);
                        }
                    } else if (i == 0) {
                        if (grids[i][j] == '?') {
                            if (k == 0) {
                                f[i][j][0] = f[i][j - 1][0];
                            } else {
                                f[i][j][k] = f[i][j - 1][k];
                                f[i][j][k] = f[i][j - 1][k - 1] + 1;
                            }
                        } else {
                            f[i][j][k] = f[i][j - 1][k] + (grids[i][j] == '1' ? 1 : 0);
                        }
                    } else if (j == 0) {
                        if (grids[i][j] == '?') {
                            f[i][j][k] = f[i - 1][j][k];
                            if (k >= 1) {
                                f[i][j][k] = f[i - 1][j][k - 1] + 1;
                            }
                        } else {
                            f[i][j][k] = f[i - 1][j][k] + (grids[i][j] == '1' ? 1 : 0);
                        }
                    } else {
                        if (grids[i][j] == '?') {
                            f[i][j][k] = std::max(f[i - 1][j][k], f[i][j - 1][k]);
                            if (k >= 1) {
                                f[i][j][k] = std::max(f[i - 1][j][k - 1], f[i][j - 1][k - 1]) + 1;
                            } 
                        } else {
                            f[i][j][k] = std::max(f[i - 1][j][k], f[i][j - 1][k]) + (grids[i][j] == '1' ? 1 : 0);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= x; i++) {
            ans = std::max(ans, f[n - 1][m - 1][i]);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
