/**
 *      author:  yuyuan567
 *      created: 2025-08-05 21:59:41
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "../algo/debug.h"
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

    friend std::istream& operator>>(std::istream& is, ModInt& x) {
        long long tmp;
        is >> tmp;
        x.v = normalize(tmp);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
        return os << x.v;
    }
};

constexpr int MOD = 1e8;
using Mint = ModInt<MOD>;

void solve() {
    int n, f;
    std::cin >> n >> f;
    std::vector<int> R(n);
    for (int i = 0; i < n; i++) {
        std::cin >> R[i];
        R[i] %= f;
    }
    std::vector<std::vector<Mint>> dp(n, std::vector<Mint>(f));
    for (int i = 0; i < n; i++) {
        dp[i][R[i]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < f; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i - 1][(j - R[i] + f) % f];
        }
    }
    std::cout << dp[n - 1][0];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}