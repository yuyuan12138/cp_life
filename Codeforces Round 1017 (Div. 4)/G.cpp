/*** 
 * @Author: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @Date: 2025-05-10 16:39:49
 * @LastEditors: yuyuan 115848824+yuyuan12138@users.noreply.github.com
 * @LastEditTime: 2025-05-10 16:53:49
 * @FilePath: \Codeforces Round 1017 (Div. 4)\G.cpp
 * @Description: 
 * @
 * @Copyright (c) ${Date} by ${115848824+yuyuan12138@users.noreply.github.com}, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

#define int long long

using namespace std;

void solve(){
    int q;
    cin >> q;
    
    int tot = 0;
    int n = 0;

    deque<int> qNorm, qRev;
    int norm = 0, rev = 0;

    int p = 0;

    for(int i = 0; i < q; i++){
        int s;
        cin >> s;
        if(s == 3){
            n ++;
            int k; cin >> k;
            qNorm.push_back(k);
            qRev.push_front(k);
            norm += k * n;
            rev += tot;
            rev += k;
            tot += k;
        }else if(s == 1){
            int right = qNorm.back();
            qNorm.pop_back();
            qNorm.push_front(right);

            norm = norm + tot  - right * n;
            right = qRev.front();
            qRev.pop_front();

            qRev.push_back(right);
            rev = rev - tot + right * n;
            
        }else{
            swap(rev, norm);
            swap(qNorm, qRev);
        }

        cout << norm << endl;
    }

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}