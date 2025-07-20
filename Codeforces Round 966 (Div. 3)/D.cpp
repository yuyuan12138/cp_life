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
    int n; cin >> n;
    vector<ll> prefix_sum(n + 1);
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        prefix_sum[i] = prefix_sum[i - 1] + t;
    }
    string s; cin >> s;
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++){
        if(s[l] == 'L'){
            break;
        }
        l++;
    }
    for(int i = 0; i < n; i++){
        if(s[r] == 'R'){
            break;
        }
        r--;
    }
    ll ans = 0;
    while(l < r){
        ans += prefix_sum[r + 1] - prefix_sum[l];
        l ++ ;
        r -- ;
        while(l < n && s[l] != 'L'){
            l++;
        }
        while(r >= 0 && s[r] != 'R'){
            r--;
        }
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