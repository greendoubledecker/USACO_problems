//[][][][][][][][][]}>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> children;
vector<ll> ans;
void solve(ll curr){
	//cout << "curr = " << curr << endl;
	if(children[curr].empty()){
		ans[curr] = 0;
		return;
	}else{
		ll cnt = 0;
		for(ll i : children[curr]){
			++cnt;
			solve(i);
			cnt += ans[i];
		}
		ans[curr] = cnt;
		return;
	}
}
int main(){
	ll n;
	cin >> n;
	children = vector<vector<ll>>(n);
	ans = vector<ll>(n);
	for(ll i = 1; i < n; ++i){
		ll parent;
		cin >> parent;
		children[parent - 1].push_back(i);
	}
	//cout << "openopenopenopen\n";
	solve(0);
	for(ll i = 0; i < n - 1; ++i){
		cout << ans[i] << ' ';
	}
	cout << ans[n - 1] << endl;
}
