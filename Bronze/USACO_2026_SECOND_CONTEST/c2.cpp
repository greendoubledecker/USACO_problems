#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll n, q;
	cin >> n >> q;
	vector<ll> changedPrices(n);
	//vector<pair<ll, ll>> prices;
	//vector<long double> ratios;
	//long double ratio = 1'000'000'000'000;
	for(ll i = 0; i < n; ++i){
		ll p;
		cin >> p;
		if(i > 0){
			changedPrices[i] = min(p, changedPrices[i - 1] * 2);
		}else{
			changedPrices[i] = p;
		}
		//long double cur = p / pow(2, i);
		//if(cur < ratio){
		//	ratio = cur;
		//	prices.push_back({i, p});
		//}
		//ratios.push_back(ratio);
	}
	/*
	vector<ll> suffixCheapest(n);
	suffixCheapest[n - 1] = changedPrices[n - 1];
	for(ll i = n - 2; i >= 0; --i){
		suffixCheapest[i] = min(suffixCheapest[i + 1], changedPrices[i]);
	}
	*/
	while(q--){
		ll x;
		cin >> x;
		ll price = 0;
		while(x > 0){
			//long double ratio = 1'000'000'000'000;
			//long double p2 = 1;
			ll lessPow = floor(log2(x));
			if(lessPow >= n){
				ll buyLess = changedPrices[n - 1];
				long double power = pow(2, n - 1);
				ll times = x >> (n - 1);
				price += times * buyLess;
				x -= times * power;
				continue;
			}
			ll buyLess = changedPrices[lessPow];
			long double lessRatio = buyLess / pow(2, lessPow);
			if((ll) log2(x) + 1 >= n){
				price += buyLess;
				x -= pow(2, lessPow);
				continue;
			}
			ll buyMore = changedPrices[(ll) log2(x) + 1];
			long double moreRatio = buyMore / x;
			//cout << "buyMore = " << buyMore << " lessPow = " << lessPow << " buyLess = " << buyLess << " moreRatio = " << moreRatio << " lessRatio = " << lessRatio << endl;
			if(lessRatio < moreRatio){
				price += buyLess;
				x -= pow(2, lessPow);
			}else{
				price += buyMore;
				break;
			}
		}
		cout << price << endl;
	}
}
