/**
 *      author:  yuyuan567
 *      created: 2025-08-03 16:25:15
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > a) {
        swap(b, a);
    }
    if (((c < a && c > b) && ((d > a || d < b))) || ((d < a && d > b) && ((c > a || c < b)))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}