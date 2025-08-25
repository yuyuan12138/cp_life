/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:44:44
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
**/
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    DSU dsu(n * m);
    std::vector<std::vector<int>> grids(n, std::vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grids[i][j];
        }
    }
    while (q--) {
        int i, j;
        std::cin >> i >> j;
        i--, j--;
        bool ok;
        dsu.init(n * m);
        int cnt = 1;
        while (true) {
            
            if ((i == 0 && grids[i][j] == 1) || (i == n - 1 && grids[i][j] == 2) || (j == 0 && grids[i][j] == 3) || (j == m - 1 && grids[i][j] == 4)) {
                ok = true;
                break;
            }
            if (grids[i][j] == 1) {
                if (!dsu.merge(i * m + j, (i - 1) * m + j)) {
                    ok = false;
                    break;
                } 
                i--;
            } else if (grids[i][j] == 2) {
                if (!dsu.merge(i * m + j, (i + 1) * m + j)) {
                    ok = false;
                    
                    break;
                }
                i++;
            } else if (grids[i][j] == 3) {
                if (!dsu.merge(i * m + j, i * m + j - 1)) {
                    ok = false;
                    break;
                }
                j--;
            } else {
                if (!dsu.merge(i * m + j, i * m + j + 1)) {
                    ok = false;
                    break;
                }
                j++;
            }
            cnt++;
        }
        if (ok) {
            std::cout << cnt << '\n'; 
        } else {
            std::cout << -1 << '\n';
        }
    }
    return 0;
}
/**
 *      author:  yuyuan567
 *      created: 2025-08-22 19:44:44
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
**/
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, q;
    std::cin >> n >> m >> q;
    DSU dsu(n * m);
    std::vector<std::vector<int>> grids(n, std::vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grids[i][j];
        }
    }
    while (q--) {
        int i, j;
        std::cin >> i >> j;
        i--, j--;
        bool ok;
        dsu.init(n * m);
        int cnt = 1;
        while (true) {
            
            if ((i == 0 && grids[i][j] == 1) || (i == n - 1 && grids[i][j] == 2) || (j == 0 && grids[i][j] == 3) || (j == m - 1 && grids[i][j] == 4)) {
                ok = true;
                break;
            }
            if (grids[i][j] == 1) {
                if (!dsu.merge(i * m + j, (i - 1) * m + j)) {
                    ok = false;
                    break;
                } 
                i--;
            } else if (grids[i][j] == 2) {
                if (!dsu.merge(i * m + j, (i + 1) * m + j)) {
                    ok = false;
                    
                    break;
                }
                i++;
            } else if (grids[i][j] == 3) {
                if (!dsu.merge(i * m + j, i * m + j - 1)) {
                    ok = false;
                    break;
                }
                j--;
            } else {
                if (!dsu.merge(i * m + j, i * m + j + 1)) {
                    ok = false;
                    break;
                }
                j++;
            }
            cnt++;
        }
        if (ok) {
            std::cout << cnt << '\n'; 
        } else {
            std::cout << -1 << '\n';
        }
    }
    return 0;
}
