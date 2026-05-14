#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> movies(n);
	for(ll i = 0; i < n; ++i){
		cin >> movies[i].second >> movies[i].first;
	}
	sort(movies.begin(), movies.end());
	multiset<ll> endings;
	for(ll i = 0; i < k; ++i){
		endings.insert(0);
	}
	ll ans = 0;
	for(auto [end, start] : movies){
		auto it = endings.upper_bound(start);
		if(it == endings.begin()) continue;
		--it;
		endings.erase(it);
		endings.insert(end);
		++ans;
	}
	cout << ans << endl;
}
