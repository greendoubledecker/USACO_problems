#include <bits/stdc++.h>
using namespace std;
using ll = __int128_t;
vector<ll> a;
ll k;
bool works(ll guess){
	//cout << "bbl" << endl;
	ll ans = 0;
	for(ll i = 0; i < a.size(); ++i){
		ans += max(guess - a[i], (ll)0) / (i + 1) + (max(guess - a[i], (ll)0) % (i + 1) != 0);
	}
	return ans <= k;
}
int main(){
	ll n;
	long long nn, kk;
	cin >> nn >> kk;
	n = (ll)nn; k = (ll)kk;
	a = vector<ll>(n);
	for(ll &i : a){
		long long ii;
		cin >> ii;
		i = (ll)ii;
	}
	ll l = 0, r = LLONG_MAX, ans = -1;
	while(l <= r){
		cout << (long long)l << ' ' << (long long)r << endl;
		ll mid = l + (r - l) / 2;
		if(works(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << (long long)ans << endl;
}
