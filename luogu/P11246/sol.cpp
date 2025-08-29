/**
 *      author:  yuyuan567
 *      created: 2025-08-28 23:36:31
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
    std::vector<int> nums;
    for (int i = 1; i * i <= n; i++) {
        nums.push_back(i * i);
    }
    std::vector<int> f(n + 1, INT32_MAX);
    f[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = nums[i]; j <= n; j++) {
            f[j] = std::min(f[j], f[j - nums[i]] + 1);
        }
    }
    std::cout << f[n];
    return 0;
}
