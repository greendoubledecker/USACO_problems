#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, pair<ll, ll>> mapp;
int main(){
	ll x;
	ll n;
	cin >> n >> x;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	for(ll i = 0; i < n; ++i){
		for(ll j = i + 1; j < n; ++j){
			ll sum = v[i] + v[j];
			ll other = x - sum;
			//cout << "i = " << i << " j = " << j << " other = " << other << endl;
			if(mapp.count(other)){
				//cout << "has other = {" << mapp[other].first << ' ' << mapp[other].second << "}\n";
				pair<ll, ll> p = mapp[other];
				if(p.first != i && p.first != j && p.second != i && p.second != j){
					cout << p.first + 1 <<' '<< p.second + 1 <<' '<< i + 1 <<' '<< j + 1 << endl;
					return 0;
				}
			}
			if(!mapp.count(sum)){
				//cout << "add to map" << endl;
				mapp[sum] = {i, j};
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
