#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
	ll index = 0;
	vector<Node*> nb;
	bool open = true;
	bool notvisited = true;
};
void dfs(Node* &start){
	start -> notvisited = false;
	for(Node* &moo : start -> nb){
		if(moo -> notvisited && moo -> open){
			moo -> notvisited = false;
			dfs(moo);
		}
	}
}
 void check(vector<Node*> &v){
	for(Node* n : v){
		if(n -> open){
			dfs(n);
			break;
		}
	}
	bool flag = false;
	for(Node* &n : v){
		if(n -> notvisited && n -> open){
			flag = true;
		}
		n -> notvisited = true;
	}
	if(flag){
		cout << "NO\n";
	}else{
		cout << "YES\n";
	}
}
int main(){
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<Node*> v(n);
	for(ll i = 0; i < n; ++i){
		v[i] = new Node;
		v[i] -> index = i;
	}
	for(ll i = 0; i < m; ++i){
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		v[a] -> nb.push_back(v[b]);
		v[b] -> nb.push_back(v[a]);
	}
	check(v);
	while(n--){
		if(n == 0) break;
		ll x;
		cin >> x;
		--x;
		v[x] -> open = false;
		//cout << "ehjkvgfvjgwkhtgwtrfywhrtuyrtufwbukhrfgyubrgfybvwrgyfbuhjkw" << endl;
		check(v);
	}
}
