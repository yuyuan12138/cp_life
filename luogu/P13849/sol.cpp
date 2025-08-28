/**
 *      author:  yuyuan567
 *      created: 2025-08-27 21:22:15
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
    std::map<std::string, int> mp;
    while (true) {
        std::string a, b, c;
        std::cin >> a;
        if (a == "------") {
            break;
        }
        std::cin >> b >> c;
        int x = std::stoi(a);
        int y = std::stoi(b);
        mp[c] += y - x;
    }
    std::vector<std::pair<std::string, int>> ans;
    while (true) {
        std::string a, b, c;
        std::cin >> a;
        if (a == "======") {
            break;
        }
        std::cin >> b >> c;
        int x = std::stoi(a), y = std::stoi(b);
        mp[c] -= (y - x);
    }
    bool ok = false;
    for (auto& [name, value]: mp) {
        if (value == 0) continue; 
        ok = true;
        if (value > 0) {
            std::cout << name << " " << -value << '\n';
        } else {
            std::cout << name << " +" << -value << '\n';
        }
    }
    if (!ok) {
        std::cout << "No differences found.";
    }
    return 0;
}
