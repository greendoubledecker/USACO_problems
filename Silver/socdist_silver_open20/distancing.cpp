#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll,ll>> intervals;
ll n;
bool check(ll d){
	ll prev = LLONG_MIN;
	ll cnt = 0;
	for(pair<ll, ll> i : intervals){
		while(max(prev + d, i.first) <= i.second){
			prev = max(prev + d, i.first);
			++cnt;
			if(cnt >= n){
				break;
			}
		}
		if(cnt >= n){
			break;
		}
	}
	return cnt >= n;
}

int main(){
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	cin >> n;
	ll m;
	cin >> m;
	for(ll i = 0; i < m; ++i){
		ll a,b;
		cin >> a >> b;
		intervals.push_back({a,b});
	}
	sort(intervals.begin(), intervals.end());
	ll l = 1, r = 2e18, ans = -1;
	while(l <= r){
		ll mid = l + (r-l) / 2;
		if(check(mid)){
			//cout << mid << " works\n";
			ans = mid;
			l = mid + 1;
		}else{
			//cout << mid << " does not work\n";
			r = mid - 1;
		}
	}
	cout << ans << endl;
}
