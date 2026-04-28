#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("haybales.out", "w", stdout);
	freopen("haybales.in", "r", stdin);
	ll n,q;
	cin >> n >> q;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	while(q--){
		ll a, b;
		cin >> a >> b;
		ll left = lower_bound(v.begin(), v.end(), a) - v.begin();
		ll right = upper_bound(v.begin(), v.end(), b) - v.begin();
		cout << right - left << endl;
	}
}
