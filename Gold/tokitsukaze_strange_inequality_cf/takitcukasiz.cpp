#include <bits/stdc++.h>
using namespace std;
using ll = long long; //oops, using too much long;
int f[5005][5005], g[5005][5005];
struct BIT{
	ll n;
	vector<ll> tree;
	BIT(ll n) : n(n), tree(vector<ll>(n + 1, 0)){};
	void update(ll pos, ll add){
		while(pos <= n){
			tree[pos] += add;
			pos += pos & -pos;
		}
	}
	ll sum(ll l, ll r){
		if(l == 1){
			ll ans = 0;
			while(r > 0){
				ans += tree[r];
				r -= r & -r;
			}
			return ans;
		}else{
			return sum(1, r) - sum(1, l - 1);
		}
	}
};
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> p(n + 1);
		for(ll i = 1; i <= n; ++i){
			cin >> p[i];
		}
		//cout << "dbg\n";
		BIT bit1(n);
		bit1.update(p[1], 1);
		for(ll b = 2; b <= n - 2; ++b){
			for(ll c = b + 1; c < n; ++c){
				//cout << b << ' ' << c << '\n';
				f[b][p[c]] = bit1.sum(1, p[c] - 1);
			}
			bit1.update(p[b], 1);
		}
		//cout << "pee\n";
		BIT bit2(n);
		bit2.update(p[n], 1);
		for(ll c = n - 1; c >= 3; --c){
			for(ll b = 2; b < c; ++b){
				g[c][p[b]] = bit2.sum(1, p[b] - 1);
			}
			bit2.update(p[c], 1);
		}
		//cout << "poooooop\n";
		ll ans = 0;
		for(ll b = 2; b <= n - 2; ++b){
			for(ll c = b + 1; c < n; ++c){
				ans += f[b][p[c]] * g[c][p[b]];
			}
		}
		cout << ans << '\n';
	}
}
