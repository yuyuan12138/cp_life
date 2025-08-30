/**
 *      author:  yuyuan567
 *      created: 2025-08-30 16:44:43
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
    int n, m;
    std::cin >> n >> m;
    std::map<int, std::vector<int>> x_color;
    std::map<int, std::vector<int>> y_color;
    std::vector<std::vector<int>> s(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            std::cin >> c;
            s[i][j] = c;
            x_color[c].push_back(i);
            y_color[c].push_back(j);
        }
    }
    int64_t ans = 0;
    for (auto& [_, vec] : x_color) {
        std::sort(vec.begin(), vec.end());
        int cur = 1;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (i < vec.size() - 1 && vec[i] == vec[i + 1]) {
                cur++;
            } else {
                ans += cur * (vec.back() - vec[i]);
                cur = 1;
            }
        }
    }
    for (auto& [_, vec] : y_color) {
        std::sort(vec.begin(), vec.end());
        int cur = 1;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (i < vec.size() - 1 && vec[i] == vec[i + 1]) {
                cur++;
            } else {
                ans += cur * (vec.back() - vec[i]);
                cur = 1;
            }
        }
    }
    std::cout << ans;
    return 0;
}
