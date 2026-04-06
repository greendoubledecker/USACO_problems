#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
vector<ll> parent;
vector<ll> sz;
ll find(ll ind){
	if(parent[ind] == ind){
		return ind;
	}else{
		return find(parent[ind]);
	}
}
void merge(ll a, ll b){
	ll rootA = find(a), rootB = find(b);
	if(rootA == rootB){
		return;
	}
	if(sz[rootA] > sz[rootB]){
		sz[rootA] += sz[rootB];
		parent[rootB] = rootA;
	}else{
		sz[rootB] += sz[rootA];
		parent[rootA] = rootB;
	}
}
int main(){
	ll n, q;
	cin >> n >> q;
	for(ll i = 0; i < n; ++i){
		parent.push_back(i);
		sz.push_back(1);
	}
	while(q--){
		string s;
		cin >> s;
		if(s[0] == 'U'){
			ll a, b;
			cin >> a >> b;
			merge(a - 1, b - 1);
		}else{
			ll x;
			cin >> x;
			cout << sz[find(x - 1)] << endl;
		}
	}
}
