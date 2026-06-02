#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
bool check(ll guess){
	ll ans = 0;
	for(ll i = 1; i <= n; ++i){
		ans += min(guess/i, n);
		if(guess%i == 0 && guess/i <= n) --ans;
	}
	return ans > n*n/2;
}
int main(){
	cin >> n;
	if(n == 1){
		cout << "1\n";
		return 0;
	}
	ll l = 0, r = 1e18, ans = -1;
	while(l <= r){
		ll mid = l + (r-l) / 2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ans - 1 << endl;
}
