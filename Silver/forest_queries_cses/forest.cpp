#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll h,w;
	cin >> h;
	w = h;
	ll q;
	cin >> q;
	vector<vector<ll>> ps(h + 1, vector<ll>(w + 1));
	for(ll i = 0; i <= w; ++i){
		ps[0][i] = 0;
	}
	for(ll i = 0; i <= h; ++i){
		ps[i][0] = 0;
	}
	for(ll r = 1; r <= h; ++r){
		for(ll c = 1; c <= w; ++c){
			char ch;
			cin >> ch;
			if(ch == '*'){
				ps[r][c] = ps[r-1][c]+ps[r][c-1]-ps[r-1][c-1] + 1;
			}else{
				ps[r][c] = ps[r-1][c]+ps[r][c-1]-ps[r-1][c-1];
			}
		}
	}
	/*
	for(ll r = 1; r <= h; ++r){
		for(ll c = 1; c <= w; ++c){
			cout << ps[r][c] << ' ';
		}
		cout << endl;
	}
	*/
	while(q--){
		ll x1,y1,x2,y2;
		cin >> y1 >> x1 >> y2 >> x2;
		--x1;
		--y1;
		cout << ps[y2][x2] + ps[y1][x1] - ps[y2][x1] - ps[y1][x2] << endl;
	}
}
