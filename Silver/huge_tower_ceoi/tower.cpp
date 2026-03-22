#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll ans = 1;
	for(ll i = 0; i < n; ++i){
		auto boundary = lower_bound(v.begin(), v.end(), v[i] - k);
		ll num = (((v.end() - boundary) + 1) - (n - i)) % (ll)(1e9 + 9);
		ans *= num;
		ans %= (ll)(1e9 + 9);
	}
	cout << ans << endl;
}
