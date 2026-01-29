#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> a(n), b(n);
		for(ll i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(ll i = 0; i < n; ++i){
			cin >> b[i];
		}
		
		//find d_min
		ll j = 0;
		for(ll i = 0; i < n; ++i){
			while(b[j] < a[i]){
				++j;
			}
			cout << b[j] - a[i] << ' ';
		}
		cout << '\n';
		
		//find d_max
		j = 0;
		for(ll i = 0; i < n; ++i){
			j = max(i, j);
			while(j <= n - 2 && b[j] >= a[j + 1]){ //b[j] >= a[j + 1] because this means that a[i + 1] can be transformed to b[j], so j can keep moving
				++j;
			}
			cout << b[j] - a[i] << ' ';
		}
		cout << '\n';
	}
}
