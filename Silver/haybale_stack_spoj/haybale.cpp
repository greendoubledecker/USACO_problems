#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> diff(n + 1, 0);
	while(k--){
		ll a, b;
		cin >> a >> b;
		++diff[a-1];
		--diff[b];
	}
	vector<ll> bales(1, diff[0]);
	for(ll i = 1; i < n; ++i){
		bales.push_back(bales[i - 1] + diff[i]);
	}
	sort(bales.begin(), bales.end());
	cout << bales[n / 2] << endl;
}
