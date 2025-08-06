#include <iostream>
#include <algorithm>

using namespace std;

int arr[2 * 100000 + 2];

bool check(int x, int y){
    int z = x ^ y;
    if(x + y > z && x + z > y && y + z > x){
        return true;
    }
    return false;
}

void solve(){
    int x;
    cin >> x;
    int right = x - 1, left = 1;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(check(x, mid)){
            cout << mid << endl;
            return ;
        }else{
            left = mid + 1;
        }
    }

    cout << -1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
}