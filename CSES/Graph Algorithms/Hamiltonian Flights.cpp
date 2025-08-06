/**
 *      author:  yuyuan567
 *      created: 2025-08-04 23:32:22
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

template <int MOD>
struct ModInt {
    long long v;
    ModInt() : v(0) {}
    ModInt(long long _v) : v(normalize(_v)) {}

    static long long normalize(long long x) {
        if (x < 0)
            x %= MOD, x += MOD;
        return x % MOD;
    }

    explicit operator int() const {
        return v;
    }
    explicit operator long long() const {
        return v;
    }

    ModInt operator+(const ModInt& rhs) const {
        return ModInt(v + rhs.v);
    }
    ModInt operator-(const ModInt& rhs) const {
        return ModInt(v - rhs.v);
    }
    ModInt operator*(const ModInt& rhs) const {
        return ModInt(v * rhs.v);
    }
    ModInt operator/(const ModInt& rhs) const {
        return *this * rhs.inv();
    }

    ModInt& operator+=(const ModInt& rhs) {
        v = (v + rhs.v) % MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& rhs) {
        v = (v - rhs.v + MOD) % MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& rhs) {
        v = v * rhs.v % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& rhs) {
        return *this *= rhs.inv();
    }

    ModInt pow(long long exp) const {
        ModInt base = *this, res = 1;
        for (; exp; exp >>= 1, base *= base)
            if (exp & 1)
                res *= base;
        return res;
    }

    ModInt inv() const {
        // Fermat's little theorem (MOD must be prime)
        return pow(MOD - 2);
    }

    friend istream& operator>>(istream& is, ModInt& x) {
        long long tmp;
        is >> tmp;
        x.v = normalize(tmp);
        return is;
    }

    friend ostream& operator<<(ostream& os, const ModInt& x) {
        return os << x.v;
    }
};

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
    }
    std::vector<Mint> dp(n);

    [&](int u) -> void {

    }(0);
    std::cout << dp[n - 1];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}