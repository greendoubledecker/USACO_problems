#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool comp(pair<ll, ll> a, pair<ll, ll> b){
	return a.first < b.first;
}
int main(){
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> events;
	for(ll i = 1; i <= n; ++i){
		ll a, b;
		cin >> a >> b;
		events.push_back({a, i});
		events.push_back({b, -i});
	}
	sort(events.begin(), events.end(), comp);
	vector<ll> closedTime(n); //time that the pool will be closed after firing lifeguard
	set<ll> onDuty;
	ll cnt = 0;
	ll zero = 0;
	for(ll i = 0; i < 2*n - 1; ++i){
		//cout << "event " << i << endl;
		if(events[i].second > 0){
			onDuty.insert(events[i].second);
			++cnt;
		}else{
			onDuty.erase(-events[i].second);
			--cnt;
		}
		if(cnt == 1){
			closedTime[*onDuty.begin()-1] += events[i + 1].first - events[i].first;
		}
		if(cnt == 0){
			zero += events[i + 1].first - events[i].first;
		}
	}
	ll minn = 1e12;
	for(ll i : closedTime){
		minn=min(minn,i);
	}
	cout << events[2*n-1].first - events[0].first - minn - zero << endl;
}
