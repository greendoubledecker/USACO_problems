#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll r, c;
	cin >> r >> c;
	vector<vector<ll>> v(r, vector<ll>(c));
	for(ll i = 0; i < r; ++i){
		for(ll j = 0; j < c; ++j){
			cin >> v[i][j];
		}
	}
	for(ll i = 0; i < c; ++i){
		for(ll j = i; j < c; ++j){
			bool thisWorks = true;
			for(ll k = 0; k < r; ++k){
				ll temp = v[k][i];
				v[k][i] = v[k][j];
				v[k][j] = temp;
				ll missed = 0;
				for(ll l = 0; l < c; ++l){
					if(v[k][l] != l + 1){
						++missed;
					}
				}
				temp = v[k][i];
				v[k][i] = v[k][j];
				v[k][j] = temp;
				thisWorks = thisWorks && missed < 3;
			}
			if(thisWorks){cout << "YES\n"; return 0;}
		}
	}
	cout << "NO\n";
}
