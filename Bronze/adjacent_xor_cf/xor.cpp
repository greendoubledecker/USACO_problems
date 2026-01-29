#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> A(n), B(n);
		for(ll i = 0; i < n; ++i){
			cin >> A[i];
		}
		for(ll i = 0; i < n; ++i){
			cin >> B[i];
		}
		if(A[n - 1] != B[n - 1]){
			cout << "NO" << endl;
			continue;
		}
		bool works = true;
		for(int i = 0; i < n - 1; ++i){
			if(A[i] != B[i] && (A[i] ^ A[i + 1]) != B[i] && (A[i] ^ B[i + 1]) != B[i]){
				works = false;
				cout << "No" << endl;
				break;
			}
		}
		if(!works){
			continue;
		}
		cout << "yEs" << endl;
	}
}
