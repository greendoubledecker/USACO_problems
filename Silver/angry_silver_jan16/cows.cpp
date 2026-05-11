#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> pos;
ll k;
bool ge(ll r){
	ll curr = pos[0];
	ll needed = 0;
	while(curr < 1e9 + 10){
		//cout << "curr = " << curr << endl;
		++needed;
		ll next = curr + 2 * r;
		auto blahblahblah = upper_bound(pos.begin(), pos.end(), next); //MAKE SURE ITS NOT pos.end()!!!
		if(blahblahblah != pos.end()){
			next = *blahblahblah;
		}else{
			break;
		}
		curr = next;
	}
	return needed <= k;
}
int main(){
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	ll n;
	cin >> n >> k;
	pos = vector<ll>(n);
	for(ll &i : pos){
		cin >> i;
	}
	sort(pos.begin(), pos.end());
	ll l = 1, r = 1e9 + 10;
	ll ans = r;
	while(l <= r){
		//cout << "l = " << l << " r = " << r << endl;
		ll m = l + (r-l) / 2;
		if(ge(m)){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	cout << ans << endl;
}
