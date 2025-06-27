#include <iostream>

using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == b && c == d && b == c){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
}