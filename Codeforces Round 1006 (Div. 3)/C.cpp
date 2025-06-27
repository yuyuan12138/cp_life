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

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n, x;
    cin >> n >> x;
    int first_cnt_1_number = 0;
    int cnt_1 = 0;
    int tmp = x;
    bool flag = false;
    int bit = 0;
    vector<int> mask(32);
    while(x){
        if(x & 1){
            if(!flag){
                first_cnt_1_number ++;
            }
            cnt_1++;
            mask[bit] = 1;
        }else{
            flag = true;
        }
        x >>= 1;
        bit ++;
    }

    if(cnt_1 >= n){
        
    }

    

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}