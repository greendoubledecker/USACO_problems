#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	ll x;
	cin >> x;
	ll ps = 0;
	map<ll, ll> pscount;
	pscount[0] = 1;
	ll ans = 0;
	for(ll i = 0; i < n; ++i){
		ll a;
		cin >> a;
		ps += a;
		++pscount[ps];
		if(x == 0){
			ans += pscount[ps] - 1;
			continue;
		}
		ll other = ps - x;
		if(pscount.count(other)){
			ans += pscount[other];
		}
	}
	cout << ans << endl;
}
