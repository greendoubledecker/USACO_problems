#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool skedfj(pair<ll, ll> a, pair<ll, ll> b){
	return a.first < b.first;
}
pair<ll, ll> twosum(vector<pair<ll, ll>> v, ll x){
	//cout << "x = " << x << endl;
	ll l = 0, r = v.size() - 1;
	while(l < r){
		if(v[l].first + v[r].first > x){
			--r;
		}else if(v[l].first + v[r].first < x){
			++l;
		}else{
			return {v[l].second, v[r].second};
		}
	}
	return {-1, -1};
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, x;
	cin >> n >> x;
	vector<pair<ll, ll>> v(n);
	for(ll i = 0; i < n; ++i){
		ll w;
		cin >> w;
		v[i] = {w, i};
	}
	sort(v.begin(), v.end(), skedfj);
	pair<ll, ll> p = twosum(v, x);
	if(p.first != -1){
		cout << p.first + 1 << ' ' << p.second + 1 << endl;
		return 0;
	}
	cout << "IMPOSSIBLE\n";
}
