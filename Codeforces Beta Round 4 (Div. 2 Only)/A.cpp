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
    if(n <= 2 || n % 2 == 1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
    return ;
}

int main() {
    speedup();
    solve();
    return 0;
}