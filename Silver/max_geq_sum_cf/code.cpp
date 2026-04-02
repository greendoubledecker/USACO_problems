#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> nextGreaterElement(vector<ll> v){
	stack<ll> stc;
	vector<ll> ans(v.size(), v.size());
	for(ll i = v.size()- 1; i >= 0; --i){
		while(!stc.empty() && v[stc.top()] <= v[i]){
			stc.pop();
		}
		if(!stc.empty()){
			ans[i] = stc.top();
		}
		stc.push(i);
	}
	return ans;
}

vector<ll> prevGreaterElement(vector<ll> v){
	stack<ll> stc;
	vector<ll> ans(v.size(), -1);
	for(ll i = 0; i <v.size(); ++i){
		while(!stc.empty() && v[stc.top()] <= v[i]){
			stc.pop();
		}
		if(!stc.empty()){
			ans[i] = stc.top();
		}
		stc.push(i);
	}
	return ans;
}

ll query(vector<ll> &tree, ll node, ll nodestart, ll nodeend, ll querystart, ll queryend){
	if(queryend < nodestart || querystart > nodeend){
		return -1e15;
	}
	if(querystart <= nodestart && nodeend <= queryend){
		return tree[node];
	}
	ll mid = nodestart + (nodeend - nodestart) / 2;
	ll left = query(tree, 2* node, nodestart, mid, querystart, queryend);
	ll right = query(tree, 2* node + 1, mid + 1, nodeend, querystart, queryend);
	return max(left, right);
}

void tc(){
	ll n;
	cin >> n;
	ll _n = n;
	while (__builtin_popcount(_n) != 1) _n++;
	vector<ll> v(n);
	for(ll i = 0; i  < n; ++i){
		cin >> v[i];
	}
	vector<ll> ps(1), ss(1);
	ps[0] = 0;
	ss[0] = 0;
	for(ll i = 1; i <= n; ++i){
		ps.push_back(ps[i - 1] + v[i - 1]);
		//cout << "ps: " << ps[i] << endl;
		ss.push_back(ss[i - 1] + v[n - i]);
	}
	reverse(ss.begin(), ss.end());
	/*
	for(ll i : ss){
		cout << "ss: " << i << endl;
	}
	*/
	vector<ll> nextgreater = nextGreaterElement(v);
	vector<ll> prevgreater = prevGreaterElement(v);
	vector<ll> preftree(2*_n, -1e15), sufftree(2*_n, -1e15);
	for(ll i = 0; i < n; ++i){
		preftree[_n + i] = ps[i + 1];
		sufftree[_n + i] = ss[i];
	}
	for(ll i= _n - 1; i >= 1; --i){
		preftree[i] = max(preftree[2*i], preftree[2*i + 1]);
		sufftree[i] = max(sufftree[2*i], sufftree[2*i + 1]);
	}
	bool flag = true;
	for(ll i = 0; i < n; ++i){
		ll right = query(preftree, 1, 0, _n - 1, i + 1, nextgreater[i] - 1) - ps[i + 1];
		ll left = query(sufftree, 1, 0, _n - 1, prevgreater[i] + 1, i - 1) - ss[i];
		if(left > 0 || right > 0){
			//cout << "i = " << i << endl;
			//cout << "left = " << left << endl;
			//cout << "right = " << right << endl;
			//cout << "ps = " << ps[i] << " ss = " << ss[i];
			flag = false;
			break;
		}
	}
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		tc();
	}
}
