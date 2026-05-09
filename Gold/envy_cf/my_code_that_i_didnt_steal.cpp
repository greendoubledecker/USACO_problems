#include <bits/stdc++.h>    //btw i didnt steal this code
using namespace std;        //am i getting more suspicious the more i talk...
using ll = long long;       //okay, i'll just shut up now.
vector<ll> parent;
vector<ll> sz;
vector<pair<ll, ll>> previous; //first is the changed node, and second is the old size
vector<vector<ll>> graphByWeight(5e5 + 10);
vector<vector<pair<ll, ll>>> queriesByWeight(5e5 + 10);
ll find(ll ind){
	while(parent[ind] != ind){
		ind = parent[ind];
	}
	return ind;
}
bool merge(ll a, ll b){
	a = find(a);
	b = find(b);
	if(a == b){
		return false;
	}
	if(sz[a] < sz[b]){
		swap(a, b);
	}
	previous.push_back({b, sz[a]});
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}
bool permanentMerge(ll a, ll b){
	a = find(a);
	b = find(b);
	if(a == b){
		return false;
	}
	if(sz[a] < sz[b]){
		swap(a, b);
	}
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}
struct Edge{
	ll u, v, w;
};
void rollback(ll checkpoint){
	while(previous.size() > checkpoint){
		pair<ll, ll> p = previous.back();
		previous.pop_back();
		ll a = parent[p.first];
		sz[a] = p.second;
		parent[p.first] = p.first;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; ++i){
		parent.push_back(i);
		sz.push_back(1);
	}
	vector<Edge> edges;
	for(ll i = 0; i < m; ++i){
		ll a, b, w;
		cin >> a >> b >> w;
		--a;
		--b;
		Edge e;
		e.u = a;
		e.v = b;
		e.w = w;
		edges.push_back(e);
		//cout << "start weight = =c=d= " << e.w << endl;
		graphByWeight[w].push_back(i);
	}
	ll q;
	cin >> q;
	vector<bool> bad(q);
	for(ll queryIndex = 0; queryIndex < q; ++queryIndex){
		ll k;
		cin >> k;
		for(ll j = 0; j < k; ++j){
			ll id;
			cin >> id;
			--id;
			//cout << "weight is " << edges[id].w << endl;
			queriesByWeight[edges[id].w].push_back({queryIndex, id});
		}
	}
	//cout << "debuggggggg\n";
	for(ll w = 1; w < 5e5 + 5; ++w){
		if(!queriesByWeight[w].empty()){
			auto &vec = queriesByWeight[w];
			sort(vec.begin(), vec.end());
			//cout << "Pairs with weight " << p.first << ":\n";
			//ffor(pair<ll, ll> pair : p.second){
			//	cout << "{" << pair.first << "," << pair.second << "}" << endl;
			//}
			ll i = 0;
			while(i < vec.size()){
				//cout << "outer loop\n";
				ll queryIndex = vec[i].first;
				ll checkpoint = previous.size();
				bool flag = true;
				while(i < vec.size() && vec[i].first == queryIndex){
					ll edgeId = vec[i].second;
					auto &e = edges[edgeId];
					if(!merge(e.u, e.v)){
						flag = false;
					}
					++i;
				}
				rollback(checkpoint);
				if(!flag){
					bad[queryIndex] = true;
				}
			}
		}
		for(ll edgeId : graphByWeight[w]){
			auto &e = edges[edgeId];
			permanentMerge(e.u, e.v);
		}
	}
	for(ll i = 0; i < q; ++i){
		if(bad[i]){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}
