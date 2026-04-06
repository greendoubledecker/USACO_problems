#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dfs(vector<ll> &left, vector<ll>& right, ll root){
	if(root == -1) return -1;
	ll ans = 0;
	ans = max(dfs(left, right, left[root]), dfs(left, right, right[root])) + 1;
	return ans;
}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> parent(n, -1);
		vector<ll> left(n, -1);
		vector<ll> right(n, -1);
		stack<ll> stc;
		vector<ll> v;
		for(ll i = 0; i < n; ++i){
			ll lastpop = -1;
			ll x;
			cin >> x;
			--x;
			v.push_back(x);
			while(!stc.empty() && stc.top() < x){ // top is > x
				//cout << "pop " << stc.top() << endl;
				lastpop = stc.top();
				stc.pop();
			}
			if(lastpop != -1){
				left[x] = lastpop;
				parent[lastpop] = x;//lastpop becomes left child of x
			}
			if(!stc.empty()){
				//cout << "top = " << stc.top() << endl;
				right[stc.top()] = x;
				parent[x] = stc.top(); // x becomes right child of top
			}
			stc.push(x);
		}
		ll root = 0;
		for(ll i = 0; i < n; ++i){
			if(parent[i] == -1){
				root = i;
			}
			//cout << "parent: " << parent[i] << endl;
		}
		/*
		for(ll i = 0; i < n; ++i){
			cout << "left: " << left[i] << endl;
		}
		for(ll i = 0; i < n; ++i){
			cout << "right: " << right[i] << endl;;
		}
		cout << root << endl;
		*/
		cout << n - dfs(left, right, root) - 1 << endl;
	}
}
