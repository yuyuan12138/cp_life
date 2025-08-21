/**
 *      author:  yuyuan567
 *      created: 2025-08-18 10:06:08
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    // f[i][j]
    
    std::vector<std::vector<int>> f(n, std::vector<int> (m));
    int mx = 0;
     
    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) {
            f[i][0] = 1;
        } else if (i > 0) {
            f[i][0] = f[i - 1][0];
        }
        mx = std::max(mx, f[i][0]);
    }
    for (int j = 0; j < m; j++) {
        if (a[0] == b[j]) {
            f[0][j] = 1;
        } else if (j > 0) {
            f[0][j] = f[0][j - 1];
        }
        mx = std::max(mx, f[0][j]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) { 
            if (a[i] == b[j]) {
                f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
            } else {
                f[i][j] = std::max(f[i][j], std::max(f[i - 1][j], f[i][j - 1]));
            }
            mx = std::max(mx, f[i][j]);
        }
    }
    std::vector<int> ans;

    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i--, j--;
        } else if (i > 0 && f[i][j] == f[i - 1][j]) {
            i--;
        } else if (j > 0) {
            j--;
        } else {
            break;
        }
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << mx << '\n';
    for (auto& x: ans) {
        std::cout << x << " ";
    }

    return 0;
}
