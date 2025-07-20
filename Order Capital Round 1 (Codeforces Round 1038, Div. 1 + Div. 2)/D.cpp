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

/**
 * Move to the i th. So Going direct is well.
 */

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> v_edge(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        v_edge[u].push_back(v);
        v_edge[v].push_back(u);
    }

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}