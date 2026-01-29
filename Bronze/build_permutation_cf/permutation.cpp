#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	for(ll i = 0; i < n; ++i){
		sum += abs(v[i] - (i + 1));
	}
	cout << sum << endl;
}
