#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool comp(pair<ll, ll> a, pair<ll, ll> b){
	return a.second > b.second;
}
int main(){
	freopen("rental.out", "w", stdout);
	freopen("rental.in", "r", stdin);
	ll n, m, r;
	cin >> n >> m >> r;
	vector<ll> cows(n);
	for(ll i = 0; i < n; ++i){
		cin >> cows[i];
	}
	sort(cows.begin(), cows.end());
	vector<ll> maxmilk(1);
	maxmilk[0] = 0;
	for(ll i = 0; i < n; ++i){
		maxmilk.push_back(maxmilk[i] + cows[n - i - 1]);
		//cout << "maxmilk: " << maxmilk[i + 1] << endl;
	}
	//cout << endl;

	vector<pair<ll, ll>> shops(m);
	for(ll i = 0; i < m; ++i){
		cin >> shops[i].first >> shops[i].second;
	}
	sort(shops.begin(), shops.end(), comp);
	vector<ll> milkmoney(1);
	milkmoney[0] = 0;
	ll fullorders = 0;
	ll money = 0;
	ll milk = 0;
	for(ll i = 0; i < n; ++i){
		if(fullorders == m){
			milkmoney.push_back(money);
			//cout << "milkmoney: " << money << endl;
			continue;
		}
		milk += cows[n - i - 1];
		while(milk >= shops[fullorders].first){
			money += shops[fullorders].second * shops[fullorders].first;
			milk -= shops[fullorders].first;
			++fullorders;
			if(fullorders == m){
				break;
			}
		}
		if(fullorders == m){
			milkmoney.push_back(money);
			//cout << "milkmoney: " << money << endl;
			continue;
		}
		milkmoney.push_back(money + milk * shops[fullorders].second);
		//cout << "milkmoney: ";
		//cout << milkmoney[i + 1] << " milk: " << milk << " second: " << shops[fullorders].second << endl;
	}

	//cout << endl;

	vector<ll> rent(r);
	for(ll i = 0; i < r; ++i){
		cin >> rent[i];
	}
	sort(rent.begin(), rent.end());
	vector<ll> rentmoney(1);
	rentmoney[0] = 0;
	for(ll i = 0; i < max(n, r); ++i){
		if(i >= r){
			rentmoney.push_back(rentmoney[r]);
			//cout << "rentmoney: ";
			//cout << rentmoney[r] << endl;
			continue;
		}
		rentmoney.push_back(rentmoney[i] + rent[r - i - 1]);
		//cout << "rentmoney: ";
		//cout << rentmoney[i + 1] << endl;
	}

	ll maxx = 0;
	for(ll i  = 0; i < n; ++i){
		maxx = max(maxx, milkmoney[n - i] + rentmoney[i]);
	}
	cout << maxx << endl;
}
