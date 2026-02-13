#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll n, q;
	cin >> n >>q;
	vector<ll> prices(n);
	for(ll i = 0; i < n; ++i){
		cin >> prices[i];
		if(i == 0) continue;
		prices[i] = min(prices[i], 2 * prices[i - 1]);
	}
	while(q--){
		ll x;
		cin >> x;
		ll price = 0;
		while(x > 0){
			int worthIt;
			long double ratio = 1'000'000'000'000;
			for(ll i = 0; i < n; ++i){
				long double cur = prices[i] / min((double) x, pow(2, i));
				if(cur < ratio){
					ratio = cur;
					worthIt = i;
				}
			}
			ll times = x / pow(2, worthIt);
			times = max(1LL, times);
			x -= times * pow(2, worthIt);
			price += times * prices[worthIt];
		}
		cout << price << endl;
	}
}
