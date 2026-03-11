#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll, pair<ll, ll>>> horSwap(vector<string> s, string tgt){
	vector<pair<ll, pair<ll, ll>>> ans;
	for(ll i = 0; i < tgt.size(); ++i){
		bool needBreak = false;
		for(ll r = 0; r < s.size(); ++r){
			for(ll c = 0; c < tgt.size(); ++c){
				if(s[r][c] == tgt[i] && c != i){
					ans.push_back({r, {c, i}});
					char temp = s[r][c];
					s[r][c] = s[r][i];
					s[r][i] = temp;
					needBreak = true;
				}
			}
			if(needBreak) break;
		}
	}
	return ans;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		string tgt;
		cin >> tgt;
		vector<string> s(n);
		for(ll i = 0; i < n; ++i){
			cin >> s[i];
		}
		vector<pair<ll, pair<ll, ll>>> ans = horSwap(s, tgt);
		ll ver = 0;
		for(pair<ll, pair<ll, ll>> swap : ans){
			if(swap.first != 0){
				++ver;
			}
		}
		cout << ans.size() + ver << endl;
		for(pair<ll, pair<ll, ll>> swap : ans){
			cout << "1 " << swap.first + 1 << ' ' << swap.second.first + 1 << ' ' << swap.second.second + 1 << endl;
		}
		for(pair<ll, pair<ll, ll>> swap : ans){
			if(swap.first != 0){
				cout << "2 1 " << swap.first + 1 << ' ' << swap.second.second + 1 << endl;
			}
		}
	}
}
