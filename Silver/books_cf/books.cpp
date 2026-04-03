//NOTE TO VALERA: THE SHORTEST BOOKS ARE NOT ALWAYS THE BEST...
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, time;
	cin >> n >> time;
	vector<ll> v(n);
	bool allGreater = true;
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
		if(v[i] <= time) allGreater = false;
	}
	if(allGreater){
		cout << "0\n";
		return 0;
	}
	ll l = 0;
	ll r = -1;
	ll len = 0;
	ll ans = 0;
	for(; l < n; ++l){
		while(len <= time){
			++r;
			if(r == n) break;
			len += v[r];
		}
		if(r != n){
			len -= v[r];
		}
		--r;
		//cout << "l = " << l << " r = " << r << " time = " << len << endl;
		ans = max(ans, r - l);
		len -= v[l];
	}
	cout << ans + 1 << endl;
}
