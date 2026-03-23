#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll acnt[5005], bcnt[5005];
ll startcnt[10005], endcnt[10005];
int main(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		++acnt[a];
		++bcnt[b];
	}
	for(ll i = 0; i < 5005; ++i){
		for(ll j = 0; j < 5005; ++j){
			startcnt[i + j] += acnt[i] * acnt[j];
			endcnt[i + j + 1] += bcnt[i] * bcnt[j];
		}
	}
	/*
	for(ll i = 0; i < 12; ++i){
		cout << startcnt[i] << ' ';
	}
	cout << endl;
	for(ll i = 0; i < 12; ++i){
		cout << endcnt[i] << ' ';
	}
	cout << endl;
	*/
	ll x = 0;
	for(ll i = 0; i <= 2 * m; ++i){
		x += startcnt[i];
		x -= endcnt[i];
		cout << x << endl;
	}
}
