#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll index = 0;
	vector<pair<Node*, bool>> connections;
	ll type = -1;
};
bool dfs(Node* start){
	//cout << "recursing " << start -> index << endl;
	for(auto &n : start -> connections){
		if(n.first -> type == -1){
			if(start -> type == 0){
				if(n.second){
					n.first -> type = 1;
				}else{
					n.first -> type = 0;
				}
			}else{
				if(n.second){
					n.first -> type = 0;
				}else{
					n.first -> type = 1;
				}
			}
			if(!dfs(n.first)){
				return false;
			}
			continue;
		}
		if(n.first -> type == start -> type && (n.second)){
			return false;
		}
		if(n.first -> type != start -> type && !(n.second)){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("revegetate.out", "w", stdout);
	freopen("revegetate.in", "r", stdin);
	ll n, m;
	cin >> n >> m;
	vector<Node*> nodes(n);
	for(ll i = 0; i < n; ++i){
		nodes[i] = new Node;
		nodes[i] -> index = i;
	}
	for(ll i = 0; i < m; ++i){
		char c;
		ll a, b;
		cin >> c >> a >> b;
		nodes[a-1] -> connections.push_back({nodes[b-1], c == 'D'});
		nodes[b-1] -> connections.push_back({nodes[a-1], c == 'D'});
	}
	ll cnt = 0;
	for(ll i = 0; i < n; ++i){
		if(nodes[i] -> type == -1){
			nodes[i] -> type = 0;
			if(dfs(nodes[i])){
				++cnt;
			}else{
				cout << "0\n";
				return 0;
			}
		}
	}
	cout << '1';
	for(ll i = 0; i < cnt; ++i){
		cout << '0';
	}
}
