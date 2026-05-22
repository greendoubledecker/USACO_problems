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
	ll n,k,a,b,q;
	cin >> n >> k >> a >> b >> q;
	BIT fenwickA(n + 1);
	BIT fenwickB(n + 1);
	while(q--){
		ll w;
		cin >> w;
		if(w == 1){
			ll x, y;
			cin >> x >> y;
			ll txA = fenwickA.sum(x, x);
			ll txB = fenwickB.sum(x, x);
			fenwickA.update(x, min(a, txA + y) - txA);
			fenwickB.update(x, min(b, txB + y) - txB);
		}else{
			ll x;
			cin >> x;
			cout << fenwickB.sum(1, x - 1) + fenwickA.sum(x + k, n) << endl;
		}
	}
}
