#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//GRAPHS
struct Node{
	ll index = 0;
	ll dist = 1'000'000'000'000'000'000LL;
	vector<pair<Node*, ll>> connections;
	bool finalised = false;
};
void connect(Node* a, Node* b, ll cost){
	a -> connections.push_back({b, cost});
	b -> connections.push_back({a, cost});
}
struct Compare{
	bool operator()(const Node* n1, const Node* n2){
		return n1 -> dist > n2 -> dist;
	}
};
//DIJKSTRA
void dijkstra(Node* start){
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
//END

int main(){
	Node* nodes[500];
	for(ll i = 0; i < 500; ++i){
		nodes[i] = new Node;
		nodes[i] -> index = i;
	}
	ll edges;
	cin >> edges;
	while(edges--){
		ll a, b, cost;
		cin >> a >> b >> cost;
		connect(nodes[a], nodes[b], cost);
	}
	ll start;
	cin >> start;
	dijkstra(nodes[start]);
	ll q;
	cin >> q;
	while(q--){
		ll v;
		cin >> v;
		if(nodes[v] -> dist == 1'000'000'000'000'000'000LL){
			cout << "NO PATH\n";
		}else{
			cout << nodes[v] -> dist << endl;
		}
	}
}
