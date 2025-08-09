/**
 *      author:  yuyuan567
 *      created: 2025-08-07 00:46:26
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve(){
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    ll bot = 0, top = 0;

    if (s[0] == '1') {
        bot = 0;
        top = 1;
    } else {
        top = 0;
        bot = n - 1;
    }

    ll mx = std::max(bot, top);
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            top = bot + 1;
            bot = 0;
        } else {
            top += i;
            bot += n - i - 1;
        }
        mx = std::max({mx, top, bot});
    }    

    std::cout << mx << "\n";
    

    return ;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1; std::cin >> t;
    while(t--) solve();
    return 0;
}