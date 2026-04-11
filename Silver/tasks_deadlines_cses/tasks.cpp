//The task is this problem, the deadline is tomorrow 7am, and it's 10pm now. Here I go...
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	ll sum = 0;
	vector<ll> time;
	for(ll i = 0; i < n; ++i){
		ll t, d;
		cin >> t >> d;
		time.push_back(t);
		sum += d;
	}
	sort(time.begin(), time.end());
	vector<ll> ps(1, time[0]);
	for(ll i = 1; i < n; ++i){
		ps.push_back(ps[i-1] + time[i]);
	}
	ll totaltime = 0;
	for(ll i = 0; i < n; ++i){
		totaltime += ps[i];
	}
	cout << sum - totaltime << endl;
}
