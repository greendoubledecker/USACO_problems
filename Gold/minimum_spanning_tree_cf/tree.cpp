#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
vector<ll> parent;
vector<ll> sz;
ll find(ll ind){
	if(parent[ind] == ind){
		return ind;
	}else{
		parent[ind] = find(parent[ind]);
		return parent[ind];
	}
}
bool merge(ll a, ll b){
	ll rootA = find(a), rootB = find(b);
	if(rootA == rootB){
		return false;
	}
	if(sz[rootA] > sz[rootB]){
		sz[rootA] += sz[rootB];
		parent[rootB] = rootA;
	}else{
		sz[rootB] += sz[rootA];
		parent[rootA] = rootB;
	}
	return true;
}

bool comp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; ++i){
		parent.push_back(i);
		sz.push_back(1);
	}
	pair<pair<ll, ll>, ll> edges[m];
	for(ll i = 0; i < m; ++i){
		cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
		--edges[i].first.first;
		--edges[i].first.second;
	}
	sort(edges, edges + m, comp);
	ll weight = 0;
	vector<pair<ll, ll>> ans;
	for(ll i = 0; i < m; ++i){
		if(merge(edges[i].first.first, edges[i].first.second)){
			ans.push_back({edges[i].first.first, edges[i].first.second});
			weight += edges[i].second;
		}
	}
	cout << weight << endl;
	for(pair<ll, ll> i : ans){
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
}
