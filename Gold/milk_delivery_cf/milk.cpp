#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll index = 0;
	ll dist = 1'000'000'000'000'000'000LL;
	vector<pair<Node*, ll>> connections;
	bool finalised = false;
};
struct Compare{
	bool operator()(const Node* n1, const Node* n2){
		return n1 -> dist > n2 -> dist;
	}
};
void djicsstraSpeltWrong(Node* start){ //it's spelt dijkstra
	priority_queue<Node*, vector<Node*>, Compare> pq;
	start -> dist = 0;
	pq.push(start);
	while(!pq.empty()){
		Node* cur = pq.top();
		pq.pop();
		if(cur -> finalised){
			continue;
		}else{
			cur -> finalised = true;
			for(pair<Node*, ll> &edge : cur -> connections){
				Node* next = edge.first;
				if(!next -> finalised && cur -> dist + edge.second < next -> dist){
					next -> dist = cur -> dist + edge.second;
					pq.push(next);
				}
			}
		}
	}
}
int main(){
	ll n,m,k,t;
	cin >> n >> m >> k >> t;
	vector<Node*> cities(n);
	for(ll i = 0; i < n; ++i){
		cities[i] = new Node;
	}
	Node* subway = new Node;
	while(k--){
		ll c;
		cin >> c;
		--c;
		subway -> connections.push_back({cities[c], t});
		cities[c] -> connections.push_back({subway, 0});
	}
	while(m--){
		ll a,b,w;
		cin >> a >> b >> w;
		--a; --b;
		cities[a] -> connections.push_back({cities[b], w});
		cities[b] -> connections.push_back({cities[a], w});
	}
	djicsstraSpeltWrong(cities[0]);
	if(cities[n - 1] -> dist == 1'000'000'000'000'000'000LL){
		cout << -1 << endl;
	}else{
		cout << cities[n - 1] -> dist << endl;
	}
}
