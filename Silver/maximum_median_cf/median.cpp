#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ge(ll x, ll k, vector<ll> v){
	ll sum = 0;
	for(ll i = v.size() / 2; i < v.size(); ++i){
		sum += max(0ll, x - v[i]);
	}
	return sum <= k;
}
int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll l = 1, r = 1e10;
	ll ans = -1;
	while(l <= r){
		ll mid = l + (r - l) / 2;
		if(ge(mid, k, v)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
}
