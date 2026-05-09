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
struct Edge{
	ll a, b;
	bool operator<(const Edge& other) const {
		return tie(a, b) < tie(other.a, other.b);
	}
};
int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	parent.assign(n, 0);
	iota(parent.begin(), parent.end(), 0);
	sz.assign(n, 1);
	set<Edge> st;
	for(ll i = 0; i < m; ++i){
		Edge e;
		//e.id = i;
		cin >> e.a >> e.b;
		--e.a; --e.b;
		st.insert(e);
	}
	vector<Edge> earthquakes;
	for(ll i = 0; i < k; ++i){
		Edge e;
		cin >> e.a >> e.b;
		--e.a; --e.b;
		st.erase(e);
		earthquakes.push_back(e);
	}
	reverse(earthquakes.begin(), earthquakes.end()); //i'm doing everything backwards
	for(auto e : st){
		merge(e.a, e.b);
	}
	vector<pair<ll, ll>> ans;
	ll cc = 0;
	for(ll i = 0; i < n; ++i){
		if(parent[i] == i) ++cc;
	}
	ans.push_back({sz[find(0)], cc});
	for(Edge e : earthquakes){
		cc -= merge(e.a, e.b);
		ans.push_back({sz[find(0)], cc});
	}
	ans.pop_back();
	reverse(ans.begin(), ans.end()); //flip it back around for output
	for(auto p : ans){
		cout << p.first << ' ' << p.second << endl;
	}
}
