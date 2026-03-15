#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	ll sum = v[0];
	ll l = 0, r = 0;
	ll ans = 0;
	for(; l < n; ++l){
		while(sum < x){
			++r;
			if(r == n){
				break;
			}
			sum += v[r];
		}
		if(sum == x){
			++ans;
		}
		//cout << "l = " << l << " r = " << r << " sum = " << sum << '\n';
		sum -= v[l];
	}
	cout << ans << endl;
}
