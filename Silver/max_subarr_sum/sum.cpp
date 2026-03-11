#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	vector<ll> ps(1,0);
	for(ll i = 0; i < n; ++i){
		ll s;
		cin >> s;
		ps.push_back(ps[ps.size()-1] + s);
	}
	ll minn = 0;
	ll maxx = LLONG_MIN;
	for(ll i = 1; i <= n; ++i){
		maxx = max(maxx, ps[i] - minn);
		minn = min(minn, ps[i]);
	}
	cout << maxx << endl;
}
