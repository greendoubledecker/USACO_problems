#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for(ll i = 0; i < n; ++i){cin >> a[i];}
		for(ll i = 0; i < n; ++i){cin >> b[i];}
		ll l = 0, r = 1e10;
		while(r - l > 1){
			ll mid = l + (r - l) / 2;
			ll sum = 0;
			for(ll i = 0; i < n; ++i){
				if (a[i] >= mid){
					sum += (a[i] - mid) / b[i] + 1;
				}
			}
			if(sum >= k){
				l = mid;
			}else{
				r = mid;
			}
		}

		long long ans = 0;
		ll sum = 0;

		for(ll i = 0; i < n; ++i){
			if(a[i] > l){
				ll mid = (a[i] - l) / b[i] + 1;
				ans += mid * a[i] - mid * (mid - 1) / 2 * b[i];
				sum += mid;
			}
		}

		cout << ans - l * (sum - k) << endl;
	}
}
