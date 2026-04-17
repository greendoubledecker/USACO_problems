#include <bits/stdc++.h> // Let's say City 0 is a 'hub'.
using namespace std;     // If the hub can connect to all other cities, and all other cities can connect to the hub, then all cities can connect to each other.
using ll = long long;    // On the other hand, if the hub cannot connect to some cities, or some cities cannot connect to the hub, then the graph is not fully connected.
struct Node{
	ll index = 0;
	vector<Node*> connections;
	bool visited = false;
};
void connect(Node* a, Node* b){
	a -> connections.push_back(b);
}

void dfs(Node* start){
	start ->visited = true;
	for(Node* &i : start -> connections){
		if(!i -> visited){
			dfs(i);
		}
	}
}

int main(){
	ll n, m;
	cin >> n >> m;
	vector<Node*> nodes(n);
	for(ll i = 0; i < n; ++i){
		nodes[i] = new Node;
		nodes[i] -> index = i;
	}
	vector<pair<ll,ll>> edges(m);
	for(ll i = 0; i < m; ++i){
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		edges[i] = {a,b};
		connect(nodes[a], nodes[b]);
	}
	dfs(nodes[0]);
	for(ll i = 0; i < n; ++i){
		if(!nodes[i] -> visited){
			cout << "NO\n1 " << i + 1 << '\n';
			return 0;
		}
	}
	for(ll i = 0; i < n; ++i){
		nodes[i] = new Node;
		nodes[i] -> index = i;
	}
	for(ll i = 0; i < m; ++i){
		connect(nodes[edges[i].second], nodes[edges[i].first]);
	}
	dfs(nodes[0]);
	for(ll i = 0; i < n; ++i){
		if(!nodes[i] -> visited){
			cout << "NO\n" << i + 1 << " 1\n";
			return 0;
		}
	}
	cout << "YES\n";
}
