#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	vector<pair<ll,ll>> v(n);
	for(ll i = 0; i < n; ++i){
		cin >>v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	ll time = -1;
	ll ans = 0;
	for(ll i = 0; i < n; ++i){
		if(v[i].second >= time){
			++ans;
			time = v[i].first;
		}
	}
	cout <<ans << endl;
}
