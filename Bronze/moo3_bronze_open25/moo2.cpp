#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;

using namespace std;

int main(){
	ll n, m;
	string s;
	cin >> n >> m >> s;
	vector<vector<ll>> appears(26);
	for(ll i = 0; i < n; ++i){
		appears[s[i] - 'a'].push_back(i);
	}
	/*
	for(ll i = 0; i < 26; ++i){
		for(ll j : appears[i]){
			cout << j << " ";
		}
		cout << endl;
	}
	*/
	for(ll x = 0; x < m; ++x){
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		ll maxx = 0;
		for(ll y = 0; y < 26; ++y){
			/*
			cout << "letter " << y << endl;
			for(ll n : appears[y]){
				cout << n << endl;		
			}
			*/
			if(appears[y].empty()){
				continue;
			}
			ll k_index = upper_bound(appears[y].begin(), appears[y].end(), b) - appears[y].begin() - 1;
			//cout << "k_index " << k_index << endl;
			
			if(k_index < 0){
				continue;
			}
			
			ll k = appears[y][k_index];
			//++k;
			
			if(k < a || k > b){
				continue;
			}
			
			//cout << "k complete, = " << k << endl;
			
			ll i = n;
			for(ll z = 0; z < 26; ++z){
				if(z != y && !appears[z].empty()){
					ll i_index = lower_bound(appears[z].begin(), appears[z].end(), a) - appears[z].begin();
					//cout << "i_index " << i_index << endl;
					if(i_index >= appears[z].size()){
						continue;
					}
					//cout << appears[z].size();
					i = min(i, appears[z][i_index]);
				}
			}
			
			if(i < a || i > b){
				continue;
			}
			
			//cout << "i complete, = " << i << endl;
			
			ll rightjind = upper_bound(appears[y].begin(), appears[y].end(), ((double)k + i) / 2) - appears[y].begin();
			ll leftjind = rightjind - 1;
			ll j;
			//cout << "j complete, left right j = " << leftjind << " " << rightjind;
			if(rightjind != appears[y].size() && (leftjind == -1 || abs(appears[y][rightjind] - ((double)k + i) / 2) < abs(appears[y][leftjind] - ((double)k + i) / 2))){
				j = appears[y][rightjind];
			}else{
				j = appears[y][leftjind];
			}
			
			if(j < a || j > b){
				continue;
			}
			
			//cout << j << endl;
			//cout << "i j k = " << i << " " << j << " " << k << endl;
			if(i >= j || j >= k){
				continue;
			}
			maxx = max((k - j) * (j - i), maxx);
		}
		if(maxx == 0){
			--maxx;
		}
		cout << maxx << endl;
	}
}
