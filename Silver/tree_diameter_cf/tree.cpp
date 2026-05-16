#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> connections;
vector<ll> dist;
void dfs(ll root, ll d){
	dist[root] = d;
	//cout << root << " has dist " << d << endl;
	for(ll i : connections[root]){
		if(dist[i] != -1) continue;
		dfs(i, d + 1);
	}
}
int main(){
	ll n;
	cin >> n;
	connections = vector<vector<ll>>(n);
	dist = vector<ll>(n, -1);
	for(ll i = 0; i < n - 1; ++i){
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		connections[a].push_back(b);
		connections[b].push_back(a);
	}
	dfs(0, 0);
	ll maxpos = 0;
	for(ll i = 1; i < n; ++i){
		if(dist[i] > dist[maxpos]){
			maxpos = i;
		}
	}
	for(ll i = 0; i < n; ++i){
		dist[i] = -1;
	}
	//cout << endl;
	dfs(maxpos, 0);
	ll maxx = 0;
	for(ll i = 0; i < n; ++i){
		maxx = max(maxx, dist[i]);
	}
	cout << maxx << endl;
}
