#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
#define int long long
inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> memo(n + 1, -1);

    map<int, vector<int>> mp;
    vector<int> prefix_sum(n + 1);
    int cur = 0;
    for(int i = 1; i <= n; i++){
        cur += a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        mp[cur].push_back(i);
    }

    auto find_segment = [&](auto&& find_segment, const int idx) -> int{
        if(idx == 0){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        int mx = find_segment(find_segment, idx - 1);
        int pre_sum = prefix_sum[idx];
        if(pre_sum == 0){
            mx = max(mx, 1LL);
        }
        vector<int>& idxs = mp[pre_sum];
        int l = 0, r = idxs.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(idxs[mid] >= idx){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(r != -1){
            mx = max(mx, find_segment(find_segment, idxs[r]) + 1);
        }
        memo[idx] = mx;
        return mx;
    };
    cout << find_segment(find_segment, n) << "\n";
    return ;
}

signed main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}