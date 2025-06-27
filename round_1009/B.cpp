#include <iostream>
#include <algorithm>

using namespace std;

int arr[2 * 100000 + 2];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += arr[i];
    }
    cout << sum - n + 1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
}