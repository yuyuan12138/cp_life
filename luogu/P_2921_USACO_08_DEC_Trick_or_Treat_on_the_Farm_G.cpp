/**
 *      author:  yuyuan567
 *      created: 2025-08-03 13:50:39
 */
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        indeg[a[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = a[u];
        if (--indeg[v] == 0) {
            q.push(v);
        }
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        if (indeg[i] > 0 && ans[i] == 0) {
            vector<int> cycle;
            int cur = i;
            do {
                cycle.push_back(cur);
                cur = a[cur];
            } while (cur != i);
            int sz = cycle.size();
            for (int node : cycle) {
                ans[node] = sz;
            }
        }
    }

    vector<vector<int>> rev(n);
    for (int i = 0; i < n; i++) {
        rev[a[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] != 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : rev[u]) {
            if (ans[v] == 0) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}