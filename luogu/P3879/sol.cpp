/**
 *      author:  yuyuan567
 *      created: 2025-08-23 06:04:43
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
    std::map<std::string, std::set<int>> mp;
    for (int i = 0; i < n; i++) {
        int l; std::cin >> l;
        for (int j = 0; j < l; j++) {
            std::string s; std::cin >> s;
            mp[s].insert(i + 1);
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        std::string s;
        std::cin >> s;
        if (mp.find(s) != mp.end()) {
            for (auto x: mp[s]) {
                std::cout << x << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
