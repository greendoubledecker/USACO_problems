//HHHHHHHHHHHHHHHHHHHHHHHHHHHHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEELLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Cow{
	ll x; ll y;
};
bool compx(Cow a, Cow b){
	return a.x < b.x;
}
bool compy(Cow a, Cow b){
	return a.y < b.y;
}
ll ps[2505][2505];
ll count(ll t, ll b, ll l, ll r){
	return ps[r+1][t+1] + ps[l][b] - ps[l][t+1] - ps[r+1][b];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	Cow cows[2505];
	for(ll i = 0; i < n; ++i){
		cin >> cows[i].x >> cows[i].y;
	}
	sort(cows, cows + n, compx);
	for(ll i = 0; i < n; ++i){cows[i].x = i + 1;}
	sort(cows, cows + n, compy);
	for(ll i = 0; i < n; ++i){cows[i].y = i + 1;}
	//cout << "fart\n";
	for(ll i = 0; i < n; ++i){
		ps[cows[i].x][cows[i].y] = 1;
	}
	//cout << "pee\n";
	for(ll x = 1; x <= n; ++x){
		for(ll y = 1; y <= n; ++y){
			ps[x][y] += ps[x - 1][y] + ps[x][y - 1] - ps[x - 1][y - 1];
			//cout << ps[x][y] << ' ';
		}
		//cout << endl;
	}
	//cout << "poop\n";
	ll ans = 0;
	for(ll y1 = 0; y1 < n; ++y1){
		for(ll y2 = y1; y2 < n; ++y2){
			ll left = min(cows[y1].x, cows[y2].x) - 1;
			ll right = max(cows[y1].x, cows[y2].x) - 1;
			ans += count(y2, y1, 0, left) * count(y2, y1, right, n - 1);
			//cout << y1 << " and " << y2 << endl;
			//cout << ans <<endl;;
		}
	}
	cout << ans + 1 << endl;
}
//GGGGGGGGGGGGGGGGGGGGGGGGGOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOODDDDDDDDDDDDDDDDDDDDDDDDDBBBBBBBBBBBBBBBBBBBBBBBBBBBYYYYYYYYYYYYYYYYYYYYYYYYYYYEEEEEEEEEEEEEEEEEEEEEEEEEEE!!!!!!!!!!!!!!!!!!!!!!!!!
