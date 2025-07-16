#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    
    int max_r = *max_element(r.begin(), r.end());
    vector<vector<pair<int, int>>> intervals(max_r + 1);
    
    for (int i = 0; i < n; i++) {
        int xi = x[i], ri = r[i];
        for (int y = 0; y <= ri; y++) {
            ll s = (ll)ri * ri - (ll)y * y;
            if (s < 0) continue;
            int k = sqrt(s);
            while ((ll)(k + 1) * (k + 1) <= s) k++;
            while ((ll)k * k > s) k--;
            int start = xi - k;
            int end = xi + k;
            intervals[y].emplace_back(start, end);
        }
    }
    
    ll ans = 0;
    for (int y = 0; y <= max_r; y++) {
        auto& vec = intervals[y];
        if (vec.empty()) continue;
        sort(vec.begin(), vec.end());
        
        vector<pair<int, int>> merged;
        for (auto& p : vec) {
            if (merged.empty()) {
                merged.push_back(p);
            } else {
                auto& last = merged.back();
                if (p.first <= last.second + 1) {
                    merged.pop_back();
                    merged.emplace_back(last.first, max(last.second, p.second));
                } else {
                    merged.push_back(p);
                }
            }
        }
        
        ll total = 0;
        for (auto& p : merged) {
            total += p.second - p.first + 1;
        }
        
        if (y == 0) {
            ans += total;
        } else {
            ans += 2 * total;
        }
    }
    
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
}