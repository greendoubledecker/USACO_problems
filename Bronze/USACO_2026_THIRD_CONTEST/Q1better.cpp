#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		vector<vector<ll>> groups(abs(k));
		for(ll i = 0; i < n; ++i){
			ll x;
			cin >> x;
			groups[abs(x % k)].push_back(abs(x / k));
		}
		ll ans = 0;
		if(k>0){
			for(ll g = 0; g < k; ++g){
				sort(groups[g].begin(), groups[g].end());
				ll expected = 0;
				for(ll i = 0; i < groups[g].size(); ++i){
					expected = max(expected, groups[g][i]);
					ans += expected - groups[g][i];
					++expected;
				}
			}
		}else{
			for(ll g = 0; g < -k; ++g){
				sort(groups[g].begin(), groups[g].end());
				ll expected = LLONG_MAX;
				for(ll i = groups[g].size() - 1; i >= 0; --i){
					expected = min(expected, groups[g][i]);
					ans += groups[g][i] - expected;
					--expected;
				}
			}
		}
		cout << ans << '\n';
	}
}
