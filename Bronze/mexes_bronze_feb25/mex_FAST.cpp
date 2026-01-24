#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	vector<ll> occ(n + 1);
	for(ll i = 0; i < n; ++i){
		cin >> v[i];
		++occ[v[i]];
	}
	vector<ll> gaps(1, 0); //gaps before that number
	for(ll i = 0; i < n; ++i){
		if(occ[i] == 0){
			gaps.push_back(gaps[i] + 1);
		}else{
			gaps.push_back(gaps[i]);
		}
	}
	for(ll i = 0; i <= n; ++i){
		cout << max(occ[i], gaps[i]) << endl;
	}
}
