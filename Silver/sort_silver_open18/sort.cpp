#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct IndexedNumber{
	ll val;
	ll index;
};
bool comp(IndexedNumber a, IndexedNumber b){
	if(a.val == b.val){
		return a.index < b.index;
	}
	return a.val < b.val;
}
int main(){
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	ll n;
	cin >> n;
	vector<IndexedNumber> v(n);
	for(ll i = 0; i < n; ++i){
		cin >> v[i].val;
		v[i].index = i;
	}
	sort(v.begin(), v.end(), comp);
	ll maxx = 0;
	for(ll i = 0; i < n; ++i){
		maxx = max(maxx, v[i].index - i);
	}
	cout << maxx + 1 << endl;
}
