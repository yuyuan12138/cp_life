#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string> 
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <bitset>
#include <forward_list>
#include <deque>
#include <set>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <complex>
#include <functional>
#include <cassert>
#include <climits>
#include <limits>
#include <tuple>
#include <cstdint>
#include <array>

using namespace std;
using data = int;

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (is_prime[i] && 2 * i <= n) {
            swap(p[i], p[2 * i]);
        }
    }

    vector<bool> available(n+1, false);
    for (int j = 4; j <= n; j++) {
        if (!is_prime[j]) {
            if (j % 2 == 0) {
                int half = j / 2;
                if (half <= n / 2 && is_prime[half]) {
                    continue;
                }
            }
            available[j] = true;
        }
    }

    for (int q = 2; q <= n/2; q++) {
        if (!is_prime[q]) continue;
        vector<int> multiples;
        for (int j = 2 * q; j <= n; j += q) {
            if (available[j]) {
                multiples.push_back(j);
            }
        }
        if (multiples.size() < 2) continue;
        for (int idx = 0; idx < (int)multiples.size() - 1; idx += 2) {
            int a = multiples[idx];
            int b = multiples[idx+1];
            swap(p[a], p[b]);
            available[a] = false;
            available[b] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i];
        if (i < n) cout << " ";
    }
    cout << "\n";

    return ;

}

int main() {
    // init();
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}