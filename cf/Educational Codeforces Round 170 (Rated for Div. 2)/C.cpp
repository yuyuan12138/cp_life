#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> cnt_num;
    for(int i = 1; i <= n; i++){
        if(cnt_num.find(a[i]) == cnt_num.end()) cnt_num[a[i]] = 0;
        cnt_num[a[i]]++;
    }
    vector<pii> nums(all(cnt_num));
    
    int slow = 0;
    int cur_k = 1;
    int ans = nums[slow].second;
    int cnt = nums[slow].second;
    for(int fast = 1; fast < nums.size(); fast++){
        if(nums[fast].first - 1 != nums[fast - 1].first){
            slow = fast;
            cur_k = 0;
            cnt = 0;
        }
        if(cur_k == k){
            slow += 1;
            cur_k--;
            cnt -= nums[slow - 1].second;
        }

        cnt += nums[fast].second;
        ans = max(ans, cnt);
        cur_k++;
    }
    cout << ans << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}