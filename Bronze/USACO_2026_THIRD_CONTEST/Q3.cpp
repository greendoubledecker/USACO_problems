#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> swapHoriz(string before, string after){
	vector<pair<ll, ll>> ans;
	for(ll i = 0; i < after.size(); ++i){
		char c = after[i];
		if(before[i] == c){
			continue;
		}
		for(ll befInd = i + 1; befInd < before.size(); ++befInd){
			if(before[befInd] == c){
				ans.push_back({i, befInd});
				before[befInd] = before[i];
				before[i] = c;
				break;
			}
		}
	}
	return ans;
}
vector<pair<ll, pair<ll, ll>>> swapVert(vector<string> s, string tgt){
	unordered_set<ll> usablecols;
	for(ll c = 0; c < tgt.size(); ++c){
		usablecols.insert(c);
	}
	vector<unordered_set<ll>> cols(tgt.size());
	vector<unordered_map<ll, ll>> pos(tgt.size());
	for(ll c = 0; c < tgt.size(); ++c){
		for(ll r = 0; r < s.size(); ++r){
			pos[c].insert({s[r][c]-'a', r});
			cols[c].insert(s[r][c]);
		}
	}
	vector<pair<ll, pair<ll, ll>>> ans; //col, then two values to swap
	for(ll i = 0; i  < tgt.size(); ++i){
		for(ll c = 0; c < tgt.size(); ++c){
			if(usablecols.count(c) && cols[c].count(tgt[i])){
				usablecols.erase(c);
				ans.push_back({c, {0, pos[c][tgt[i]-'a']}});
				//cout << "push " << c << ' ' << pos[c][tgt[i]-'a'] << endl;
				break;
			}
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
		vector<pair<ll, pair<ll, ll>>> vert = swapVert(s, tgt);
		ll cnt = 0;
		for(pair<ll, pair<ll, ll>> swap : vert){
			if(swap.second.second != 0){
				++cnt;
				s[0][swap.first] = s[swap.second.second][swap.first];
			}
		}
		vector<pair<ll, ll>> hor = swapHoriz(s[0], tgt);
		cout << cnt + hor.size() << endl;
		for(pair<ll, pair<ll, ll>> swap : vert){
			if(swap.second.second != 0){
				cout << "2 " << swap.second.first + 1 << ' ' << swap.second.second + 1 << ' ' << swap.first + 1 << endl;
			}
		}
		for(pair<ll, ll> p : hor){
			cout << "1 1 " << p.first + 1 << ' ' << p.second + 1 << endl;
		}
	}
}
