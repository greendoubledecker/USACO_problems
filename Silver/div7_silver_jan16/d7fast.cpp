#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 7;
int main(){
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	ll n;
	cin >> n;
	vector<ll> ps(1,0);
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		ps.push_back((ps[i] + x) % mod);
	}
	vector<ll> first(mod, 1e9);
	vector<ll> last(mod, -1);
	for(ll i = 0; i <= n; ++i){
		if(first[ps[i]] == 1e9){
			first[ps[i]] = i;
		}
		last[ps[i]] = i;
	}
	ll ans = 0;
	for(ll i = 0; i < mod; ++i){
		ans = max(ans, last[i] - first[i]);
	}
	cout << ans << endl;
}
