#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	vector<ll> row0(n);
	vector<ll> row1(n);
	for(ll i = 0; i < n; ++i){
		cin >> row0[i];
	}
	for(ll i = 0; i < n; ++i){
		cin >> row1[i];
	}
	ll dp0 = 0;
	ll dp1 = 0;
	for(ll i = 0; i < n; ++i){
		ll temp = max(dp0, dp1 + row0[i]);
		dp1 = max(dp1, dp0 + row1[i]);
		dp0 = temp;
	}
	cout << max(dp0, dp1) << endl;
}
