#include <bits/stdc++.h>

using namespace std;

int main(){
	int tt;
	cin >> tt;
	while(tt--) {
		long long n;
		cin >> n;
		long long ans = 1;
		while(n > 3){
			n /= 4;
			ans <<= 1;
		}
		cout << ans << "\n";
	}
}

