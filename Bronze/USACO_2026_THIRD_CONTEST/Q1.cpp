#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		map<ll, ll> cnt;
		for(ll i = 0; i < n; ++i){
			ll x;
			cin >> x;
			++cnt[x];
		}
		ll ans = 0;
		if(k>0){
			for(ll i = 0; i < n * (n + 2); ++i){
				if(cnt[i] > 1){
					cnt[i+k] += cnt[i] - 1;
					ans += cnt[i] - 1;
					cnt[i]= 1;
				}
			}
		}else{
			for(ll i = n; i > -n * (n + 2); --i){
				if(cnt[i] > 1){
					cnt[i+k] += cnt[i] - 1;
					ans += cnt[i] - 1;
					cnt[i]= 1;
				}
			}
		}
		cout << ans << '\n';
	}
}
