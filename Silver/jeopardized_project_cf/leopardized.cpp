#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll ps[100'010];
	ll pow2[100'010];
	pow2[0] = 1;
	ps[1] = 0;
	for(ll i = 1; i < 100'010; ++i){
		pow2[i] = (pow2[i-1] * 2) % 1000000007;
	}
	for(ll i = 2; i < 100'010; ++i){
		//cout << i << ' ';
		ps[i] = (ps[i - 1] + pow2[i-1] - pow2[i / 2] + 1000000007) % 1000000007;
	}
	/*
	for(ll i = 1; i < 40; ++i){
		cout << ps[i] << ' ';
	}
	*/
	ll t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		cout << (ps[b] - ps[a-1] + 1000000007) % 1000000007 << '\n';
	}
}
