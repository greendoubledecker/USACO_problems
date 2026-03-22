#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> barn(1001, vector<ll>(1001));
int main(){
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	while(n--){
		ll l,b,r,t;
		cin >> l >> b >> r >> t;
		++barn[l][b];
		++barn[r][t];
		--barn[l][t];
		--barn[r][b];
	}
	ll ans = 0;
	for(ll i = 0; i < 1001; ++i){
		for(ll j = 0; j < 1001; ++j){
			if(i > 0){
				barn[i][j] += barn[i - 1][j];
			}
			if(j > 0){
				barn[i][j] += barn[i][j - 1];
			}
			if(i > 0 && j > 0){
				barn[i][j] -= barn[i - 1][j - 1];
			}
			if(barn[i][j] == k){
				++ans;
			}
			//if(j < 10){
				//cout << barn[i][j];
			//}
		}
		//cout << endl;
	}
	cout << ans << endl;
}
