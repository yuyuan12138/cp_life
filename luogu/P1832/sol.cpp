/**
 *      author:  yuyuan567
 *      created: 2025-08-27 20:47:31
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif



std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    sieve(n);
    std::vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 0; i < primes.size(); i++) {
        for (int j = primes[i]; j <= n; j++) {
            f[j] += f[j - primes[i]];
        }
    }
    debug(f);
    std::cout << f[n]; 
    return 0;
}
