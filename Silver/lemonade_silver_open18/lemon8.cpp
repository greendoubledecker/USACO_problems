#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for(ll i = n - 1; i > -1; --i){
		if(v[i] < ans) break;
		++ans;
	}
	cout << ans << endl;
}
