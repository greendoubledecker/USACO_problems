#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void tc(){
	ll n;
	cin >> n;
	set<ll> seen;
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		seen.insert(x);
	}
	ll ans = seen.size();
	while(!seen.count(ans)){
		seen.insert(ans);
		++ans;
	}
	cout << ans << endl;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		tc();
	}
}
