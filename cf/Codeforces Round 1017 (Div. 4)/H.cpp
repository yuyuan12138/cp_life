/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-10 16:55:06
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-10 17:25:23
 * @FilePath: \Codeforces Round 1017 (Div. 4)\H.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

#define int long long

using namespace std;

unordered_map<int, vector<int>> pos_map;

int f(int k, vector<int>& a, int l, int r) {
    int ans = 0;
    int current_k = k;
    unordered_set<int> processed;
    
    // Convert to 0-based indices
    int l_idx = l - 1;
    int r_idx = r - 1;
    
    int i = l_idx;
    while (i <= r_idx) {
        int elem = a[i];
        if (elem == 1) {  
            ans += current_k * (r_idx - i + 1);
            break;
        }
        
        if (processed.count(elem)) {
            ans += current_k;
            i++;
            continue;
        }
        int original_k = current_k;
        while (current_k % elem == 0) {
            current_k /= elem;
        }
        processed.insert(elem);
        
        auto& positions = pos_map[elem];
        auto left = lower_bound(positions.begin(), positions.end(), i);
        auto right = upper_bound(positions.begin(), positions.end(), r_idx);
        int cnt = right - left;
        
        if (cnt > 0) {
            ans += current_k * cnt;
            int last_pos = *(right - 1);
            i = last_pos + 1;
        } else {
            ans += current_k;
            i++;
        }
    }
    return ans;
}

void preprocess(vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        pos_map[a[i]].push_back(i);
    }
    for (auto& [elem, positions] : pos_map) {
        sort(positions.begin(), positions.end());
    }
}

void solve(){
    pos_map.clear();
    int n, q;
    cin >> n >> q;
    int k, l, r;
    vector<int> v(n);
    for(auto& x: v) cin >> x;
    preprocess(v);
    while(q--){
        cin >> k >> l >> r;
        cout << f(k, v, l, r) << endl;
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}
