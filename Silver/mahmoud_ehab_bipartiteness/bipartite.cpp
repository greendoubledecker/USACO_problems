#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll index = 0;
	bool red;
	vector<Node*> nb;
	bool seen = false;
};
ll rcnt;
void dfs(Node* start){
	start -> seen = true;
	rcnt += start -> red;
	for(Node* n : start -> nb){
		if(n -> seen) continue;
		n -> red = !start -> red;
		dfs(n);
	}
}
int main(){
	rcnt = 0;
	ll n;
	cin >> n;
	vector<Node*> v(n);
	for(ll i = 0; i < n; ++i){
		v[i] = new Node;
		v[i] -> index = i;
	}
	for(ll i = 1; i < n; ++i){
		ll a, b;
		cin >> a >> b;
		v[a-1] -> nb.push_back(v[b-1]);
		v[b-1] -> nb.push_back(v[a-1]);
	}
	v[0] -> red = true;
	dfs(v[0]);
	cout << rcnt * (n - rcnt) - n + 1 << endl;
}
