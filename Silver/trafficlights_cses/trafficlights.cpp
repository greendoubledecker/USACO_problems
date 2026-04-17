#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> cnt;
set<ll> trafficlights;
int main(){
	ll x, n;
	cin >> x >> n;
	cnt[x] = 1;
	trafficlights.insert(x);
	trafficlights.insert(0);
	while(n--){
		ll p;
		cin >> p;
		auto pos = trafficlights.lower_bound(p);
		ll right = *pos;
		--pos;
		ll left = *pos;

		//cout << ind <<endl;
		if(cnt[right - left] == 1){
			cnt.erase(right - left);
		}else{
			--cnt[right - left];
		}
		++cnt[right - p];
		++cnt[p - left];
		trafficlights.insert(p);
		cout << cnt.rbegin()->first << ' ';
	}
}
