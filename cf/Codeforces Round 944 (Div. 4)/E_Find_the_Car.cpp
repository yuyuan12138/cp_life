/**
 *      author:  yuyuan567
 *      created: 2025-08-03 16:34:02
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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k), b(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    auto check = [&](ll x, ll d) -> bool {
        if (a[x] > d) {
            return true;
        } else {
            return false;
        }
    };
    while (q--) {
        ll d;
        cin >> d;
        ll l = 0, r = k - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid, d)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l == 0) {
            cout << d * b[0] / a[0] << " ";
        } else if (l == k) {
            cout << b[k - 1] << " ";
        } else {
            ll dis = d - a[r];
            ll tm = b[r] + dis * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);
            // debug(tm);
            cout << tm << ' ';
        }
    }
    cout << "\n";
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