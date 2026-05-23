#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; ++i){
		cin >> a[i];
	}
	//cout << "???\n";
	vector<ll> sorted = a;
	sort(sorted.begin(), sorted.end());
	auto compress = [&](int x){
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
    };
	vector<ll> c(n);
	for(ll i = 0; i < n; ++i) c[i] = compress(a[i]);

	vector<ll> l(n), r(n);
	BIT bit1(n), bit2(n);
	for(ll j = 0; j < n; ++j){ //k
		l[j] = bit1.sum(c[j] + 1, n);
		bit1.update(c[j], 1);
	}
	for(ll j = n-1; j >= 0; --j){ //i
		r[j] = bit2.sum(1, c[j] - 1);
		bit2.update(c[j] , 1);
	}

	ll ans = 0;
	for(ll j = 0; j < n; ++j){
		ans += l[j] * r[j];
	}
	cout << ans << endl;
}
