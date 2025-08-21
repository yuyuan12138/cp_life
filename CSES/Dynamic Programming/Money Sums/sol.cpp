/**
 *      author:  yuyuan567
 *      created: 2025-08-18 13:18:33
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
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        std::map<int, int> nmp;
        nmp[x] = 1;
        for (auto& [key, val]: mp) {
            nmp[key] = val;
            nmp[key + x] = val;
        }
        mp = nmp;
    }
    std::cout << mp.size() << "\n";
    for (auto& [key, val]: mp) {
        for (int i = 0; i < val; i++) {
            std::cout << key << " ";
        }
    }
    return 0;
}
