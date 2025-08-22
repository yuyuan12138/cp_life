/**
 *      author:  yuyuan567
 *      created: 2025-08-22 18:15:04
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int power(int a, int64_t b, int p) {
    int res = 1;
    for (; b; b /= 2, a = int64_t(1) * a * a % p) {
        if (b % 2) {
            res = int64_t(1) * res * a % p;
        }
    }
    return res;
}

int64_t mul(int64_t a, int64_t b, int64_t p) {
    int64_t c = a * b - int64_t(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

int64_t power(int64_t a, int64_t b, int64_t p) {
    int64_t res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> p; 
    for (int i = 1; i <= n; i++) {
        if (power(i, 4LL, INT32_MAX) > n) {
            break;
        }
        p.push_back(power(i, 4LL, INT32_MAX));
    }
    std::vector<int> f(n + 1, 0x3f3f3f3f);
    int m = p.size();
    for (int i = 0; i < m; i++) {
        f[p[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = p[i]; j <= n; j++) {
            f[j] = std::min(f[j], f[j - p[i]] + 1);
        } 
    }
    std::cout << f[n];
    return 0;
}
