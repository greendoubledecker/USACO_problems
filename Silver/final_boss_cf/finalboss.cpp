#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void tc(){
	ll h, n;
	cin >> h >> n;
	vector <ll> attacks(n);
	for(ll i = 0; i < n; ++i){
		cin >> attacks[i];
	}
	vector<ll> cooldown(n);
	for(ll i = 0; i < n; ++i){
		cin >> cooldown[i];
	}
	ll l = 1;
	ll r = 1e11;
	while(l < r){ //possibly l or l+1
		ll mid = l + (r-l) / 2;
		//cout << "l = " << l << " mid = " << mid << " r = " << r << endl;
		ll sum = 0;
		for(ll i = 0; i < n; ++i){
			sum += (mid - 1) / cooldown[i] * attacks[i];
			sum += attacks[i];
			if(sum >= h) break;
		}
		//cout << "sum = " << sum << endl;
		if(sum >= h){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << l << endl;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		tc();
	}
}
